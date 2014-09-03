 /*****************************************************************
*FileName: 8255.h
*Author: jiangxiaojiang		Version:V1.0		Date:20/6/2014
*Description:
*			 ��ͷ�ļ�������8255���ƺ�����
******************************************************************/
#ifndef __8255_H
#define __8255_H


struct w8255 		          //Ƭ�����ݽṹ��
{	
	unsigned char data;	
};

#define w8255_CMD ((struct w8255 volatile far *) 0x0306)	     //8255�����ֵ�ַ  11
#define w8255_PA  ((struct w8255 volatile far *) 0x0300)	 	 //8255�˿�A��ַ   00
#define w8255_PB  ((struct w8255 volatile far *) 0x0302)		 //8255�˿�B��ַ   01
#define w8255_PC  ((struct w8255 volatile far *) 0x0304)		 //8255�˿�C��ַ   10

#define  w_cmd_8255  0x80    //1000 0000		//A���������,д���ݿ�����
#define  r_cmd_8255  0x90    //1001 0000		//A�����ݶ���,�����ݿ�����

extern void write_8255(UINT8 portID,UINT8 Wdata_8255);
extern UINT8 read_8255(UINT8 portID);

extern void write_Data(UINT8 BoardID,UINT8 ByteID,UINT8 Wdata);        //д����
extern UINT8 read_Data(UINT8 BoardID,UINT8 ByteID);   //������

#endif
