#ifndef _CAN_H
#define _CAN_H

//#define BasicCAN

//can�������жϺ�������д

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

#define SELECT_ADDR1	1  //(base + 0x11)	/*Ƭѡ��ַ*/
#define DATA_ADDR1		0  //(base + 0x10)	/*��д���ݵ�ַ*/
#define SELECT_ADDR2	0x21  //(base + 0x13)	/*Ƭѡ��ַ*/
#define DATA_ADDR2		0x20  //(base + 0x12)	/*��д���ݵ�ַ*/

#ifdef  BasicCAN             /*BasicCANģʽ�¼Ĵ����Ķ���*/
#define MOD_OFFSET      0x00 /*���ƼĴ���ƫ��*/
#define CMR_OFFSET      0x01 /*����Ĵ���ƫ��*/
#define SR_OFFSET       0x02 /*״̬�Ĵ���ƫ��*/
#define IR_OFFSET       0x03 /*�жϼĴ���ƫ��*/
#define ACR_OFFSET      0x04 /*���մ���Ĵ���ƫ��*/
#define AMR_OFFSET      0x05 /*�������μĴ���ƫ��*/
#define BTR0_OFFSET     0x06 /*���߶�ʱ�Ĵ���0ƫ��*/
#define BTR1_OFFSET     0x07 /*���߶�ʱ�Ĵ���1ƫ��*/
#define OCR_OFFSET      0x08 /*������ƼĴ���ƫ��*/
#define TR_OFFSET       0x09 /*���ԼĴ���ƫ��*/

#define CDR_OFFSET      0x1f /*ʱ��Ƶ�ּĴ���ƫ��*/

#define TXBuf_OFFSET    0x10 /*���ͻ�����ƫ��*/

#define RxBuf_OFFSET    0x10 /*���ջ�����ƫ��*/
#endif

#ifdef  PeilCAN              /*PeilCANģʽ�¼Ĵ����Ķ���*/
#define MOD_OFFSET      0x00 /*ģʽ�Ĵ���ƫ��*/
#define CDR_OFFSET      0x1f /*ʱ��Ƶ�ּĴ���ƫ��*/

#define CMR_OFFSET      0x01 /*����Ĵ���ƫ��*/
#define SR_OFFSET       0x02 /*״̬�Ĵ���ƫ��*/
#define IR_OFFSET       0x03 /*�ж�״̬�Ĵ���ƫ��*/
#define IEN_OFFSET      0x04 /*�ж�ʹ�ܼĴ���ƫ��*/

#define BTR0_OFFSET     0x06 /*���߶�ʱ�Ĵ���0ƫ��*/
#define BTR1_OFFSET     0x07 /*���߶�ʱ�Ĵ���1ƫ��*/
#define OCR_OFFSET      0x08 /*������ƼĴ���ƫ��*/
#define TR_OFFSET       0x09 /*���ԼĴ���ƫ��*/

#define ACR0_OFFSET     0x10 /*���մ���Ĵ���0ƫ��*/
#define ACR1_OFFSET     0x11 /*���մ���Ĵ���1ƫ��*/
#define ACR2_OFFSET     0x12 /*���մ���Ĵ���2ƫ��*/
#define ACR3_OFFSET     0x13 /*���մ���Ĵ���3ƫ��*/

#define AMR0_OFFSET     0x14 /*�������μĴ���0ƫ��*/
#define AMR1_OFFSET     0x15 /*�������μĴ���1ƫ��*/
#define AMR2_OFFSET     0x16 /*�������μĴ���2ƫ��*/
#define AMR3_OFFSET     0x17 /*�������μĴ���3ƫ��*/

#define TXBuf_OFFSET    0x10 /*���ͻ�����ƫ��*/

#define RxBuf_OFFSET    0x10 /*���ջ�����ƫ��*/

#define ALC_OFFSET      0x0B /*�ٲö�ʧ��׽�Ĵ���ƫ��*/
#define ECC_OFFSET      0x0C /*������벶׽�Ĵ���ƫ��*/
#define EWLR_OFFSET     0x0D /*��������޼Ĵ���ƫ��*/
#define RXERR_OFFSET    0x0E /*���մ��������ƫ��*/
#define TXERR_OFFSET    0x0F /*���ʹ��������ƫ��*/
#define RMC_OFFSET      0x1D /*����FIFO�еı�������ƫ��*/
#define RBSA_OFFSET     0x1E /*���ջ�������ʼ��ַƫ��*/

#endif



/*��غ���*/
uchar read_data(uchar channel,uchar address);
void write_data(uchar channel,uchar address, uchar value );
uchar  can_init(uchar *args); /*��ʼ��SJA1000*/
uchar can_send(uchar channel,uchar *tdata); /*���������ӳ���*/
uchar can_recv(uchar channel,uchar *rdata); /*���������ӳ���*/


#endif
