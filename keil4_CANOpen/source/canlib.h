#ifndef _CAN_H
#define _CAN_H

//#define BasicCAN

//can接收在中断函数里面写

#ifndef BasicCAN
#define PeilCAN
#endif

#define uchar unsigned char
#define byte unsigned char
#define uint  unsigned int
#define TRUE 1
#define FALSE 0

//extern int base;
#define can_addr ((UINT8 volatile far *) 0x310)	 //

#define SELECT_ADDR1	1  //(base + 0x11)	/*片选地址*/
#define DATA_ADDR1		0  //(base + 0x10)	/*读写数据地址*/
#define SELECT_ADDR2	0x21  //(base + 0x13)	/*片选地址*/
#define DATA_ADDR2		0x20  //(base + 0x12)	/*读写数据地址*/

#ifdef  BasicCAN             /*BasicCAN模式下寄存器的定义*/
#define MOD_OFFSET      0x00 /*控制寄存器偏移*/
#define CMR_OFFSET      0x01 /*命令寄存器偏移*/
#define SR_OFFSET       0x02 /*状态寄存器偏移*/
#define IR_OFFSET       0x03 /*中断寄存器偏移*/
#define ACR_OFFSET      0x04 /*验收代码寄存器偏移*/
#define AMR_OFFSET      0x05 /*验收屏蔽寄存器偏移*/
#define BTR0_OFFSET     0x06 /*总线定时寄存器0偏移*/
#define BTR1_OFFSET     0x07 /*总线定时寄存器1偏移*/
#define OCR_OFFSET      0x08 /*输出控制寄存器偏移*/
#define TR_OFFSET       0x09 /*测试寄存器偏移*/

#define CDR_OFFSET      0x1f /*时钟频分寄存器偏移*/

#define TXBuf_OFFSET    0x10 /*发送缓冲器偏移*/

#define RxBuf_OFFSET    0x10 /*接收缓冲器偏移*/
#endif

#ifdef  PeilCAN              /*PeilCAN模式下寄存器的定义*/
#define MOD_OFFSET      0x00 /*模式寄存器偏移*/
#define CDR_OFFSET      0x1f /*时钟频分寄存器偏移*/

#define CMR_OFFSET      0x01 /*命令寄存器偏移*/
#define SR_OFFSET       0x02 /*状态寄存器偏移*/
#define IR_OFFSET       0x03 /*中断状态寄存器偏移*/
#define IEN_OFFSET      0x04 /*中断使能寄存器偏移*/

#define BTR0_OFFSET     0x06 /*总线定时寄存器0偏移*/
#define BTR1_OFFSET     0x07 /*总线定时寄存器1偏移*/
#define OCR_OFFSET      0x08 /*输出控制寄存器偏移*/
#define TR_OFFSET       0x09 /*测试寄存器偏移*/

#define ACR0_OFFSET     0x10 /*验收代码寄存器0偏移*/
#define ACR1_OFFSET     0x11 /*验收代码寄存器1偏移*/
#define ACR2_OFFSET     0x12 /*验收代码寄存器2偏移*/
#define ACR3_OFFSET     0x13 /*验收代码寄存器3偏移*/

#define AMR0_OFFSET     0x14 /*验收屏蔽寄存器0偏移*/
#define AMR1_OFFSET     0x15 /*验收屏蔽寄存器1偏移*/
#define AMR2_OFFSET     0x16 /*验收屏蔽寄存器2偏移*/
#define AMR3_OFFSET     0x17 /*验收屏蔽寄存器3偏移*/

#define TXBuf_OFFSET    0x10 /*发送缓冲器偏移*/

#define RxBuf_OFFSET    0x10 /*接收缓冲器偏移*/

#define ALC_OFFSET      0x0B /*仲裁丢失捕捉寄存器偏移*/
#define ECC_OFFSET      0x0C /*错误代码捕捉寄存器偏移*/
#define EWLR_OFFSET     0x0D /*出错警告界限寄存器偏移*/
#define RXERR_OFFSET    0x0E /*接收错误计数器偏移*/
#define TXERR_OFFSET    0x0F /*发送错误计数器偏移*/
#define RMC_OFFSET      0x1D /*接收FIFO中的报文数量偏移*/
#define RBSA_OFFSET     0x1E /*接收缓冲区起始地址偏移*/

#endif



/*相关函数*/
uchar read_data(uchar channel,uchar address);
void write_data(uchar channel,uchar address, uchar value );
uchar  can_init(uchar *args); /*初始化SJA1000*/
uchar can_send(uchar channel,uchar *tdata); /*发送数据子程序*/
uchar can_recv(uchar channel,uchar *rdata); /*接收数据子程序*/


#endif
