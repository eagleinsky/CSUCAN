 /*****************************************************************
*FileName: dpram.h
*Author: jiangxiaojiang		Version:V1.0		Date:20/6/2014
*Description: 
*			 双口RAM相关读写
******************************************************************/

#ifndef __DPRAM_H
#define __DPRAM_H

#define DRAM_BUSY P4_P7 

struct AD_DATA 		  //交换数据的结构体
{
	unsigned int aout[2];	//模拟量输出值
	unsigned int  ain[9];	//模拟量采样值	
	UINT16 Speed[4];		//速度传感器采样值
    UINT16 Pwm_width;		//PWM采样值
};

#define ram_data_ad ((struct AD_DATA volatile far *) 0xD8000) //双口RAM交换数据的地址 ,映射到双口RAM的地址0000开始

void write_AD_ram(struct AD_DATA *adram);		  //向ADI板双口RAM写两路电流输出的数据
void read_AD_ram(struct AD_DATA *adram);		  //读ADI板双口RAM的9路模拟量电流  4路速度采集 1路PWM采样数据

#endif
