 /*****************************************************************
*FileName: global.h
*Author: jiangxiaojiang		Version:V1.0		Date:20/6/2014
*Description: 
*			 该头文件声明了部分用户自定义的全局变量。
******************************************************************/

#ifndef __GLOBAL_H
#define __GLOBAL_H

/*××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××
×××××××××××××××用于交换数据的固定的全局变量*********************
*********************************************×××××××××××××××××*/

extern UINT8 TimerMsFlag;			     //1MS	定时器标志位
extern UINT8 TFlag; 					 //控制周期定时器标志  10MS

extern struct AD_DATA * dpram_data;		 //ADI板双口RAM数据
extern struct DIO_DATA_S  * DIO_ALL;	 //IO板输入输出数据				  
extern UINT16 can_nod;					 //编码器值
extern UINT8 can1_recv_flag;				 //CAN1通信有接收数据标志位
extern UINT8 can2_recv_flag;				 //CAN2通信有接收数据标志位
extern UINT8 recv_buf1[13];				 //CAN1通信数组
extern UINT8 recv_buf2[13];				 //CAN2通信数组

/*××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××××
×××××××××××××××用于交换数据的固定的全局变量*********************
*********************************************×××××××××××××××××*/
extern unsigned char mvb_buf_so1[32],mvb_buf_so2[32],mvb_buf_si[32],mvb_buf_si2[32];
void can_debug(int candeal);

#endif
