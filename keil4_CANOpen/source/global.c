 /*****************************************************************
*FileName: global.c
*Author: jiangxiaojiang		Version:V1.0		Date:20/6/2014
*Description: 
*			 ��ͷ�ļ������˲����û��Զ����ȫ�ֱ�����
******************************************************************/
#include "Main.h"

struct DIO_DATA_S DIO;
struct AD_DATA ADIO;
UINT8 TimerMsFlag = 0;	  //1MS	��ʱ����־λ
UINT8 TFlag = 0; //�������ڶ�ʱ����־	10MS

struct AD_DATA * dpram_data=&ADIO;	   //AD��˫��RAM����
struct DIO_DATA_S  * DIO_ALL=&DIO;	   //IO��˫�������������
UINT16 can_nod=0;					   //������ֵ
UINT8 can1_recv_flag=0;			   //CAN1ͨ���н������ݱ�־λ
UINT8 can2_recv_flag=0;		   	   //CAN2ͨ���н������ݱ�־λ
UINT8 recv_buf1[13]={0};
UINT8 recv_buf2[13]={0};


