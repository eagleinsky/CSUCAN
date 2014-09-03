 /*****************************************************************
*FileName: dio.c
*Author: jiangxiaojiang		Version:V1.0		Date:20/6/2014
*Description: 
*			 ���������������
******************************************************************/
#include "MAIN.h"
void DOUT(struct DIO_DATA_S  * dio_data)
{
	write_Data(DIO1,0,dio_data->dio1_out);	//���������1  ���
	delay(10);
	write_Data(DIO2,0,dio_data->dio2_out);	 //���������2  ���
	delay(10);
	write_Data(DOUT1,1,dio_data->do_out);		 //�����  ���
	delay(10);
}

void DIN(struct DIO_DATA_S  * dio_data)
{
	dio_data->dio1_in = read_Data(DIO1,2);	  	//���������1  ����
	delay(10);
    dio_data->dio2_in = read_Data(DIO2,2);	   //���������2  ����
	delay(10);
}

void DERROR(struct DIO_DATA_S  * dio_data)
{
	dio_data->dio1_err = read_Data(DIO1,1);	  	//���������1  ����
	delay(10);
    dio_data->dio2_err = read_Data(DIO2,1);	   //���������2  ����
	delay(10);
	dio_data->do_err = read_Data(DOUT1,0);	   //���������2  ����
	delay(10);
}