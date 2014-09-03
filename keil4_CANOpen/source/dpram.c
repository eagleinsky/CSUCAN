 /*****************************************************************
*FileName: dpram.c
*Author: jiangxiaojiang		Version:V1.0		Date:20/6/2014
*Description: 
*			 Ë«¿ÚRAMÏà¹Ø¶ÁÐ´¡£
******************************************************************/
#include "MAIN.h"

void write_AD_ram(struct AD_DATA *adram)
{
		int i=0;
		for(i=0;i<2;i++)
		{
		while(DRAM_BUSY==0); 	
		ram_data_ad->aout[i]=adram->aout[i];
	 	}
}

void read_AD_ram(struct AD_DATA *adram)
{
		int i=0;
		for(i=0;i<9;i++)
		{
		while(DRAM_BUSY==0);
	 	adram->ain[i]=ram_data_ad->ain[i];
		}
		for(i=0;i<4;i++)
		{
		while(DRAM_BUSY==0);
	 	adram->Speed[i]=ram_data_ad->Speed[i];
		}
		while(DRAM_BUSY==0);
	 	adram->Pwm_width=ram_data_ad->Pwm_width;

}