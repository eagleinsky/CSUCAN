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

/*************��ʼ��SJA1000оƬ***************
����Ϊһ�����飬����can��ʼ��������
args[0]: 1���õ�һ��canͨ����2���õڶ���canͨ��
args[1]: ������ѡ��0����50k��1����100k
args[2-5]: ���μĴ�������,���粻���Σ������ó�0xff
args[6-9]: ����Ĵ������飬�ɶ����ó�0xff
������Ե�һ·can��100k������������ʼ����
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
		write_data(args[0],MOD_OFFSET, (uchar)(temp | 0x01));/*���븴λģʽ����ʼ��SJA1000*/
	}
	count = 0;
	write_data(args[0],CDR_OFFSET, 0x88);	/*0x88*//*ѡ��PeilCANģʽ���ر�ʱ�����*/

	write_data(args[0],AMR0_OFFSET, args[2]);	/*11111111,�������μĴ���0*/
	write_data(args[0],AMR1_OFFSET, args[3]);	/*11111111,�������μĴ���1*/
	write_data(args[0],AMR2_OFFSET, args[4]);	/*11111111,�������μĴ���2*/
	write_data(args[0],AMR3_OFFSET, args[5]);	/*11111111,�������μĴ���3*/
	/*�����κα�־��*/
	write_data(args[0],ACR0_OFFSET, args[6]);	/*00010000,���ܴ���Ĵ���0*/
	write_data(args[0],ACR1_OFFSET, args[7]);	/*00010000,���ܴ���Ĵ���1*/
	write_data(args[0],ACR2_OFFSET, args[8]);	/*00010000,���ܴ���Ĵ���2*/
	write_data(args[0],ACR3_OFFSET, args[9]);	/*00010000,���ܴ���Ĵ���3*/
	write_data(args[0],BTR0_OFFSET, btr0[args[1]]);	
	write_data(args[0],BTR1_OFFSET, btr1[args[1]]);
	write_data(args[0],OCR_OFFSET, 0x1a);	/*OCR,������ƼĴ���
									TX1���գ�TX0����
									�������ģʽ*/
	write_data(args[0],IEN_OFFSET,0x01);	/////ʹ��SJA1000�����ж�

	write_data(args[0],MOD_OFFSET, 0x08);	/*0x08*//*���õ��˲������ܷ�ʽ�������ع���״̬*/

	while (read_data(args[0],MOD_OFFSET) & 0x01 == 0x01)
	{
		count++;
		if (count >= 10)
			return FALSE;	
	}
	return TRUE;
}

/*******************************
�������������������ӳ���
��ڲ�����
          tdata�������ͻ�����ָ��
���ڲ�����
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
�������������������ӳ���
��ڲ�����rdata�������ջ�����ָ��
���ڲ�����
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




