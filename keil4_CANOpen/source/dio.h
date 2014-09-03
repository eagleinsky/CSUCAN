 /*****************************************************************
*FileName: dio.h
*Author: jiangxiaojiang		Version:V1.0		Date:20/6/2014
*Description: 
*			 ���������������
******************************************************************/

#ifndef __DIO_H
#define __DIO_H

struct DIO_DATA_S 		  //�������ݵĽṹ��
{
	unsigned char dio1_out;	//DIO1�� ���������  24V
	unsigned char dio2_out;	//DIO2�� ���������  24V
	unsigned char do_out;		//DO�� ���������  110V
	unsigned char dio1_in;	//DIO1�� ����������  110V
	unsigned char dio2_in;	//DIO2�� ����������  110V
	unsigned char dio1_err;	//DIO1�� �����·���������ź�
	unsigned char dio2_err;	//DIO2�� �����·���������ź�
	unsigned char do_err;	//DO�� �����·���������ź�    
};

#define  DIO1  0x70
#define  DIO2  0x08
#define  DOUT1  0x78  
				
void DOUT(struct DIO_DATA_S  * dio_data);	//���������
void DIN(struct DIO_DATA_S  * dio_data);	//����������
void DERROR(struct DIO_DATA_S  * dio_data);	//���������ź�


#endif