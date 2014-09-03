 /*****************************************************************
*FileName: dio.h
*Author: jiangxiaojiang		Version:V1.0		Date:20/6/2014
*Description: 
*			 数字量输入输出。
******************************************************************/

#ifndef __DIO_H
#define __DIO_H

struct DIO_DATA_S 		  //交换数据的结构体
{
	unsigned char dio1_out;	//DIO1板 数字量输出  24V
	unsigned char dio2_out;	//DIO2板 数字量输出  24V
	unsigned char do_out;		//DO板 数字量输出  110V
	unsigned char dio1_in;	//DIO1板 数字量输人  110V
	unsigned char dio2_in;	//DIO2板 数字量输人  110V
	unsigned char dio1_err;	//DIO1板 输出短路过流保护信号
	unsigned char dio2_err;	//DIO2板 输出短路过流保护信号
	unsigned char do_err;	//DO板 输出短路过流保护信号    
};

#define  DIO1  0x70
#define  DIO2  0x08
#define  DOUT1  0x78  
				
void DOUT(struct DIO_DATA_S  * dio_data);	//数字量输出
void DIN(struct DIO_DATA_S  * dio_data);	//数字量输入
void DERROR(struct DIO_DATA_S  * dio_data);	//过流保护信号


#endif