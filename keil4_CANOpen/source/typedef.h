/*****************************************************************
*FileName: typedef.h
*Author: llrsnake		Version:V1.0		Date:8/29/2011
*Description: 
*			 该头文件包含了所有用户自定义的数据类型。
******************************************************************/

#ifndef __TYPEDEF_H
#define __TYPEDEF_H

//===========常用数据类型===============
typedef signed char     SINT8;
typedef unsigned char   UINT8;
typedef int             SINT16;
typedef unsigned int    UINT16;
typedef long            SINT32;
typedef unsigned long   UINT32;


//===========常量=======================
typedef unsigned char  const UC8;   /* Read Only */
typedef unsigned int   const UC16;  /* Read Only */
typedef unsigned long  const UC32;  /* Read Only */

//===========易变变量===================
typedef volatile signed   char   VS8;
typedef volatile unsigned char   VU8;	
typedef volatile signed   int    VS16;
typedef volatile unsigned int    VU16;
typedef volatile signed   long   VS32;
typedef volatile unsigned long   VU32;

//===========布尔变量===================
typedef enum {FALSE = 0, TRUE = !FALSE} BOOL;

//=========== 485 数据包 ===============
typedef struct S_485_FMT//485接收数据包，从上位机接收数据	  
{
	UINT8 Addr;
	UINT8 Len;       //数据包长度:总数据量+2（地址和长度）
	UINT8 DAData[8][2];
	UINT8 Check;
}S_485_FMT; 

typedef union U_485_PCKT
{
	S_485_FMT _485_pckt;
	UINT8 data[30];
}U_485_PCKT;


typedef struct S_485_ACK//485应答包，应答上位机数据	  
{
	UINT8 Addr;
	UINT8 Len;        //数据包长度:总数据量+2（地址和长度）
	UINT8 resv[10];
}S_485_ACK; 

typedef union U_485_ACK
{
	S_485_ACK _485_pckt;
	UINT8 data[12];
}U_485_ACK;


#endif
