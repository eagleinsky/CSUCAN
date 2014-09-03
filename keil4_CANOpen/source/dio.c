 /*****************************************************************
*FileName: dio.c
*Author: jiangxiaojiang		Version:V1.0		Date:20/6/2014
*Description: 
*			 数字量输入输出。
******************************************************************/
#include "MAIN.h"
void DOUT(struct DIO_DATA_S  * dio_data)
{
	write_Data(DIO1,0,dio_data->dio1_out);	//输入输出板1  输出
	delay(10);
	write_Data(DIO2,0,dio_data->dio2_out);	 //输入输出板2  输出
	delay(10);
	write_Data(DOUT1,1,dio_data->do_out);		 //输出板  输出
	delay(10);
}

void DIN(struct DIO_DATA_S  * dio_data)
{
	dio_data->dio1_in = read_Data(DIO1,2);	  	//输入输出板1  输入
	delay(10);
    dio_data->dio2_in = read_Data(DIO2,2);	   //输入输出板2  输入
	delay(10);
}

void DERROR(struct DIO_DATA_S  * dio_data)
{
	dio_data->dio1_err = read_Data(DIO1,1);	  	//输入输出板1  输入
	delay(10);
    dio_data->dio2_err = read_Data(DIO2,1);	   //输入输出板2  输入
	delay(10);
	dio_data->do_err = read_Data(DOUT1,0);	   //输入输出板2  输入
	delay(10);
}