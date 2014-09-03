 /*****************************************************************
*FileName: global.c
*Author: jiangxiaojiang		Version:V1.0		Date:20/6/2014
*Description: 
*			 该头文件声明了部分用户自定义的全局变量。
******************************************************************/
#include "Main.h"

struct DIO_DATA_S DIO;
struct AD_DATA ADIO;
UINT8 TimerMsFlag = 0;	  //1MS	定时器标志位
UINT8 TFlag = 0; //控制周期定时器标志	10MS

struct AD_DATA * dpram_data=&ADIO;	   //AD板双口RAM数据
struct DIO_DATA_S  * DIO_ALL=&DIO;	   //IO板双口输入输出数据
UINT16 can_nod=0;					   //编码器值
UINT8 can1_recv_flag=0;			   //CAN1通信有接收数据标志位
UINT8 can2_recv_flag=0;		   	   //CAN2通信有接收数据标志位
UINT8 recv_buf1[13]={0};
UINT8 recv_buf2[13]={0};


