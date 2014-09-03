 /*****************************************************************
*FileName: 8255.h
*Author: jiangxiaojiang		Version:V1.0		Date:20/6/2014
*Description:
*			 该头文件声明了8255控制函数。
******************************************************************/
#ifndef __8255_H
#define __8255_H


struct w8255 		          //片外数据结构体
{	
	unsigned char data;	
};

#define w8255_CMD ((struct w8255 volatile far *) 0x0306)	     //8255控制字地址  11
#define w8255_PA  ((struct w8255 volatile far *) 0x0300)	 	 //8255端口A地址   00
#define w8255_PB  ((struct w8255 volatile far *) 0x0302)		 //8255端口B地址   01
#define w8255_PC  ((struct w8255 volatile far *) 0x0304)		 //8255端口C地址   10

#define  w_cmd_8255  0x80    //1000 0000		//A口数据输出,写数据控制字
#define  r_cmd_8255  0x90    //1001 0000		//A口数据读入,读数据控制字

extern void write_8255(UINT8 portID,UINT8 Wdata_8255);
extern UINT8 read_8255(UINT8 portID);

extern void write_Data(UINT8 BoardID,UINT8 ByteID,UINT8 Wdata);        //写数据
extern UINT8 read_Data(UINT8 BoardID,UINT8 ByteID);   //读数据

#endif
