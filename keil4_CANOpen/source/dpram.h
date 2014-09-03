 /*****************************************************************
*FileName: dpram.h
*Author: jiangxiaojiang		Version:V1.0		Date:20/6/2014
*Description: 
*			 ˫��RAM��ض�д
******************************************************************/

#ifndef __DPRAM_H
#define __DPRAM_H

#define DRAM_BUSY P4_P7 

struct AD_DATA 		  //�������ݵĽṹ��
{
	unsigned int aout[2];	//ģ�������ֵ
	unsigned int  ain[9];	//ģ��������ֵ	
	UINT16 Speed[4];		//�ٶȴ���������ֵ
    UINT16 Pwm_width;		//PWM����ֵ
};

#define ram_data_ad ((struct AD_DATA volatile far *) 0xD8000) //˫��RAM�������ݵĵ�ַ ,ӳ�䵽˫��RAM�ĵ�ַ0000��ʼ

void write_AD_ram(struct AD_DATA *adram);		  //��ADI��˫��RAMд��·�������������
void read_AD_ram(struct AD_DATA *adram);		  //��ADI��˫��RAM��9·ģ��������  4·�ٶȲɼ� 1·PWM��������

#endif
