 /*****************************************************************
*FileName: 8255.c
*Author: jiangxiaojiang		Version:V1.0		Date:20/6/2014
*Description:
*			 ��ͷ�ļ�������8255���ƺ�����
******************************************************************/
#include "main.h"
#define UNSELECTCS 0x80  //����Ƭѡ��λ



//============= 8255��д���� ===================================
void write_8255(UINT8 portID,UINT8 Wdata_8255)		 // write 8255
{

	switch(portID)
	{
	 case 'A':
	 	  w8255_PA->data = Wdata_8255;break;
	 case 'B':			 
	 	  w8255_PB->data = Wdata_8255;break;
	 case 'C':
	 	  w8255_PC->data = Wdata_8255;break;
	 case 'S':
		 w8255_CMD->data = Wdata_8255;break;
	}

}

UINT8 read_8255(UINT8 portID)		 // read 8255
{
  
  UINT8 Rdata_8255;
  	
  switch(portID)
	{
	 case 'A':
	 	  Rdata_8255 = w8255_PA->data;break;
	 case 'B':			 
	 	  Rdata_8255 = w8255_PB->data;break;
	 case 'C':
	 	  Rdata_8255 = w8255_PC->data;break;
	 default :
	 	  Rdata_8255 = 0;break;
	}

  return (Rdata_8255); 

}
//============= ����帨������ =================================


//============= ����������д���� =============================


void write_Data(UINT8 BoardID,UINT8 ByteID,UINT8 Wdata)   //�������д����
{	 
	 UINT8 ByteData[8] = {0,1,2,3,4,5,6,7}; 	 
	 write_8255('S',w_cmd_8255);	  //����A�ڷ���Ϊ���
	 write_8255('C',0x80);			  //OUTOC OUTPE 
	 DelayMs(1);
	 write_8255('C',0x00);

	 write_8255('B',UNSELECTCS);      //����Ƭѡ��λ

     write_8255('A',Wdata);			  //������	  
	 write_8255('B',BoardID|ByteData[ByteID]);  //138����ѡ��//ѡͨ���CS

	 delay(5);
	 write_8255('B',0x80);      //����Ƭѡ��λ
	 write_8255('A',0x00);
}


UINT8 read_Data(UINT8 BoardID,UINT8 ByteID)   //������
{	 
	 UINT8 rData = 0;
	 UINT8 ByteData[8] = {0,1,2,3,4,5,6,7};
 	 write_8255('S',r_cmd_8255);	  //����A�ڷ���Ϊ����
	 write_8255('B',UNSELECTCS);      //����Ƭѡ��λ	 
	 write_8255('B',BoardID|ByteData[ByteID]);  //138����ѡ��//ѡͨ���CS

	 rData = read_8255('A');		  //������
	 
	 write_8255('B',UNSELECTCS);      //����Ƭѡ��λ
	 write_8255('S',w_cmd_8255);
	 write_8255('B',UNSELECTCS);      //����Ƭѡ��λ
	 write_8255('A',0x00);
	 return rData;
}



