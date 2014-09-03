 /*****************************************************************
*FileName: 8255.c
*Author: jiangxiaojiang		Version:V1.0		Date:20/6/2014
*Description:
*			 该头文件定义了8255控制函数。
******************************************************************/
#include "main.h"
#define UNSELECTCS 0x80  //所有片选置位



//============= 8255读写函数 ===================================
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
//============= 输出板辅助引脚 =================================


//============= 输入输出板读写函数 =============================


void write_Data(UINT8 BoardID,UINT8 ByteID,UINT8 Wdata)   //给输出板写数据
{	 
	 UINT8 ByteData[8] = {0,1,2,3,4,5,6,7}; 	 
	 write_8255('S',w_cmd_8255);	  //设置A口方向为输出
	 write_8255('C',0x80);			  //OUTOC OUTPE 
	 DelayMs(1);
	 write_8255('C',0x00);

	 write_8255('B',UNSELECTCS);      //所有片选置位

     write_8255('A',Wdata);			  //给数据	  
	 write_8255('B',BoardID|ByteData[ByteID]);  //138数据选择//选通相关CS

	 delay(5);
	 write_8255('B',0x80);      //所有片选置位
	 write_8255('A',0x00);
}


UINT8 read_Data(UINT8 BoardID,UINT8 ByteID)   //读数据
{	 
	 UINT8 rData = 0;
	 UINT8 ByteData[8] = {0,1,2,3,4,5,6,7};
 	 write_8255('S',r_cmd_8255);	  //设置A口方向为输入
	 write_8255('B',UNSELECTCS);      //所有片选置位	 
	 write_8255('B',BoardID|ByteData[ByteID]);  //138数据选择//选通相关CS

	 rData = read_8255('A');		  //读数据
	 
	 write_8255('B',UNSELECTCS);      //所有片选置位
	 write_8255('S',w_cmd_8255);
	 write_8255('B',UNSELECTCS);      //所有片选置位
	 write_8255('A',0x00);
	 return rData;
}



