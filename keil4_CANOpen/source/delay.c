 /*****************************************************************
*FileName: delay.c
*Author: jiangxiaojiang		Version:V1.0		Date:20/6/2014
*Description: 
*			 该头文件声明了部分用户自定义的全局变量。
******************************************************************/
#include "MAIN.h"

void DelayMs(UINT16 Num)
{UINT16 i = 0;

 for(i=0;i<Num;i++)
 	{TimerMsFlag = 0; 	        //计时标志清零
	 GPT1_vStartTmr(GPT1_TIMER_2);   //开始计时
	 while(!TimerMsFlag);       //等待计时结束
	}
}

void delay(UINT8 n)    //delay一小段时间
{
 UINT16 i,j;

 for(i=0;i<n;i++)
 	{
	 for(j=0;j<10;j++);
	}
}