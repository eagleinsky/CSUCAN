#include "main.h"

unsigned short can_select;
unsigned short can_data;


uchar read_data(uchar channel,uchar address)
{ 
 	uchar candata=0; 
	 if(channel==1)
	 {
		*(can_addr+SELECT_ADDR1)=address;
		candata= *(can_addr+DATA_ADDR1);
		return candata;
	}
	else if(channel==2)
	{
		*(can_addr+SELECT_ADDR2)=address;
		candata= *(can_addr+DATA_ADDR2);
		return candata;
	}
	else  return FALSE;
}
void write_data(uchar channel,uchar address, uchar value )
{
	if(channel==1)
	 {
		*(can_addr+SELECT_ADDR1)=address;
		*(can_addr+DATA_ADDR1)=value;
	}
	else if(channel==2)
	{
		*(can_addr+SELECT_ADDR2)=address;
			*(can_addr+DATA_ADDR2)=value;
	}
}

/*************初始化SJA1000芯片***************
参数为一个数组，包含can初始化参数：
args[0]: 1配置第一个can通道，2配置第二个can通道
args[1]: 波特率选择，0代表50k，1代表100k
args[2-5]: 屏蔽寄存器数组,，如不屏蔽，都设置成0xff
args[6-9]: 代码寄存器数组，可都设置成0xff
比如测试第一路can，100k，可以这样初始化：
can_init(1,1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff)
*********************************************/
uchar can_init(unsigned char *args)
{
	uchar temp = 0;
	uchar count = 0;
	uchar btr0[] = {0xc7, 0x03};//50k,100k...
	uchar btr1[] = {0x3e, 0x3e};//50k,100k...
	
//	if (args[0] == 2)
//	{
//		can_select = SELECT_ADDR2;
//		can_data = DATA_ADDR2;
//	}
//	else
//	{
//		can_select = SELECT_ADDR1;
//		can_data = DATA_ADDR1;
//	}
	temp = read_data(args[0],MOD_OFFSET);
	while((read_data(args[0],MOD_OFFSET) & 0x01) == 0 )
	{
		count++;
		if (count >= 10)
			return FALSE;
		write_data(args[0],MOD_OFFSET, (uchar)(temp | 0x01));/*进入复位模式，初始化SJA1000*/
	}
	count = 0;
	write_data(args[0],CDR_OFFSET, 0x88);	/*0x88*//*选择PeilCAN模式，关闭时钟输出*/

	write_data(args[0],AMR0_OFFSET, args[2]);	/*11111111,接受屏蔽寄存器0*/
	write_data(args[0],AMR1_OFFSET, args[3]);	/*11111111,接受屏蔽寄存器1*/
	write_data(args[0],AMR2_OFFSET, args[4]);	/*11111111,接受屏蔽寄存器2*/
	write_data(args[0],AMR3_OFFSET, args[5]);	/*11111111,接受屏蔽寄存器3*/
	/*接收任何标志符*/
	write_data(args[0],ACR0_OFFSET, args[6]);	/*00010000,接受代码寄存器0*/
	write_data(args[0],ACR1_OFFSET, args[7]);	/*00010000,接受代码寄存器1*/
	write_data(args[0],ACR2_OFFSET, args[8]);	/*00010000,接受代码寄存器2*/
	write_data(args[0],ACR3_OFFSET, args[9]);	/*00010000,接受代码寄存器3*/
	write_data(args[0],BTR0_OFFSET, btr0[args[1]]);	
	write_data(args[0],BTR1_OFFSET, btr1[args[1]]);
	write_data(args[0],OCR_OFFSET, 0x1a);	/*OCR,输出控制寄存器
									TX1悬空，TX0推挽
									正常输出模式*/
	write_data(args[0],IEN_OFFSET,0x01);	/////使能SJA1000接收中断

	write_data(args[0],MOD_OFFSET, 0x08);	/*0x08*//*设置单滤波器接受方式，并返回工作状态*/

	while (read_data(args[0],MOD_OFFSET) & 0x01 == 0x01)
	{
		count++;
		if (count >= 10)
			return FALSE;	
	}
	return TRUE;
}

/*******************************
功能描述：发送数据子程序
入口参数：
          tdata－－发送缓冲区指针
出口参数：
*******************************/
uchar can_send(uchar channel,uchar *tdata)
{
	uchar count = 0;
	uchar offset = TXBuf_OFFSET; 
	while(read_data( channel,SR_OFFSET) & 0x20)
	{
		count++;
		if (count >= 10)
			return FALSE;		
	}
	/*
	write_data(offset++, 0x88);
	write_data(offset++, 0x20);
	write_data(offset++, 0x20);
	write_data(offset++, 0x20);
	write_data(offset++, 0x20);
	*/

	write_data(channel,offset++, tdata[0]);
	write_data(channel,offset++, tdata[1]);
	write_data(channel,offset++, tdata[2]);
	write_data(channel,offset++, tdata[3]);
	write_data(channel,offset++, tdata[4]);
	write_data(channel,offset++, tdata[5]);
	write_data(channel,offset++, tdata[6]);
	write_data(channel,offset++, tdata[7]);
	write_data(channel,offset++, tdata[8]);
	write_data(channel,offset++, tdata[9]);
	write_data(channel,offset++, tdata[10]);
	write_data(channel,offset++, tdata[11]);
	write_data(channel,offset++, tdata[12]);

	write_data(channel, CMR_OFFSET, 0x01);
	return TRUE;

}

/*******************************
功能描述：接收数据子程序
入口参数：rdata－－接收缓冲区指针
出口参数：
*******************************/
uchar can_recv(uchar channel,uchar *rdata)
//EXPORT RECV_BUF CALLBACK can_recv()
{
	uchar offset = RxBuf_OFFSET;
	uchar count = 0;
	while(( read_data(channel, SR_OFFSET) & 0x01) == 0)
	{
		count++;
		if (count >= 200)
			return FALSE;	
	}
	rdata[0] = read_data(channel,offset);
	rdata[1] = read_data(channel,(uchar)(offset + 1));
	rdata[2] = read_data(channel,(uchar)(offset + 2));
	rdata[3] = read_data(channel,(uchar)(offset + 3));
	rdata[4] = read_data(channel,(uchar)(offset + 4));
	rdata[5] = read_data(channel,(uchar)(offset + 5));
	rdata[6] = read_data(channel,(uchar)(offset + 6));
	rdata[7] = read_data(channel,(uchar)(offset + 7));
	rdata[8] = read_data(channel,(uchar)(offset + 8));
	rdata[9] = read_data(channel,(uchar)(offset + 9));
	rdata[10] = read_data(channel,(uchar)(offset + 10));
	rdata[11] = read_data(channel,(uchar)(offset + 11));
	rdata[12] = read_data(channel,(uchar)(offset + 12));

	write_data(channel,CMR_OFFSET, 0x04);
	return TRUE;
}




