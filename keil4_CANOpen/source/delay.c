 /*****************************************************************
*FileName: delay.c
*Author: jiangxiaojiang		Version:V1.0		Date:20/6/2014
*Description: 
*			 ��ͷ�ļ������˲����û��Զ����ȫ�ֱ�����
******************************************************************/
#include "MAIN.h"

void DelayMs(UINT16 Num)
{UINT16 i = 0;

 for(i=0;i<Num;i++)
 	{TimerMsFlag = 0; 	        //��ʱ��־����
	 GPT1_vStartTmr(GPT1_TIMER_2);   //��ʼ��ʱ
	 while(!TimerMsFlag);       //�ȴ���ʱ����
	}
}

void delay(UINT8 n)    //delayһС��ʱ��
{
 UINT16 i,j;

 for(i=0;i<n;i++)
 	{
	 for(j=0;j<10;j++);
	}
}