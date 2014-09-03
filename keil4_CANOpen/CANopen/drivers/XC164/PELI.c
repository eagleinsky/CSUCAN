/*
 ********************************************************************************************************************
 *描述：    独立的CAN 控制器SJA1000pelican模式应用函数文件
 *文件名:   SJA_PELI.C
 *应用语言: KEIL C166
 *版本 :    V1.01
  ********************************************************************************************************************
 */
#define		_SJA_PELICAN_MODE_
#define		_GLOBAL_SJA1000_PELI_APP_

/*
************************************************************************************************************************
**                           导入头文件
************************************************************************************************************************
*/
#include	"PELI.H"

/*
************************************************************************************************************************
**                           函数原型说明
************************************************************************************************************************
*/
#include "main.h"

unsigned short can_select;
unsigned short can_data;


uchar ReadSJAReg(uchar address)
{  uchar candata=0;
*(can_addr+can_select)=address;
candata= *(can_addr+can_data);
return candata;
}
void WriteSJAReg(uchar address, uchar value )
{
*(can_addr+can_select)=address;
*(can_addr+can_data)=value;
}
void select_chip(uchar ChipNum)
{
 	if (ChipNum == 2)
	{
		can_select = SELECT_ADDR2;
		can_data = DATA_ADDR2;
	}
	else
	{
		can_select = SELECT_ADDR1;
		can_data = DATA_ADDR1;
	}
	//select_chip(ChipMum);
}

/*
************************************************************************************************************************
**????:     char   WriteSJARegBlock(unsigned char RegAdr,unsigned char  *ValueBuf,
**									   unsigned char len)
**????:     ValueValueBuf  	?????????????
**				RegAdr 			???sja1000????????
**				len				???sja1000????????
**???:       SJA_OK    		????
**				!SJA_OK        ?????
**??:         ?????????????sja1000???????
************************************************************************************************************************
*/
char   WriteSJARegBlock(unsigned char RegAdr,unsigned char  *ValueBuf, unsigned char len)

{
	unsigned	char	i;
    if(len != 0){
		for(i=0;i<len;i++){
		//	WriteRawIO(RegAdr+i,ValueBuf+i);
		//	*(SJA_CS_Point + RegAdr+i) = *(ValueBuf+i);
			WriteSJAReg(RegAdr+i,*(ValueBuf+i));
		}
	}
	return 0x00;
}

/*
************************************************************************************************************************
**????:     char   ReadSJAReg(unsigned char RegAdr,unsigned char  *ValueBuf,
**									   unsigned char len)
**????:     ValueValueBuf  	???????????????
**				RegAdr 			???sja1000????????
**				len				???sja1000????????
**???:       SJA_OK    		????
**				!SJA_OK        ?????
**??:         ???????sja1000???????
************************************************************************************************************************
*/
char   ReadSJARegBlock(unsigned char RegAdr,unsigned char  *ValueBuf,
									   unsigned char len)
{
	unsigned	char	i;
	if(len != 0){
		for(i=0;i<len;i++){
			//*(ValueBuf+i)=*(SJA_CS_Point + RegAdr+i);
			*(ValueBuf+i)=ReadSJAReg(RegAdr+i);
		}
	}
	return 0x00;
}
/*
************************************************************************************************************************
**函数原型:     char   SJATestInterface(unsigned char  testvalue)
**参数说明:     Value  测试值
**返回值:
**              SJA_OK            ; 表示SJA1000接口正常
**              SJA_INTERFACE_ERR ; 表示SJA1000与处理器接口出错
**
**说明:         该函数用于检测CAN控制器的接口是否正常
************************************************************************************************************************
*/
 char    SJATestInterface(unsigned char  testvalue)
 {
        char		status=0;
	bit		ErrorFlag =1;
	unsigned char 	ErrorCount = 0x20;							//32次报错
	unsigned char  	temp = testvalue;
	while(--ErrorCount){
    	//WriteSJAReg(REG_CAN_TEST,testvalue);
		WriteSJAReg(REG_CAN_TEST,temp);
    	if(ReadSJAReg(REG_CAN_TEST) ==  temp){
			temp =~temp ;
			WriteSJAReg(REG_CAN_TEST,temp);
			if(ReadSJAReg(REG_CAN_TEST) ==  temp){
						temp =0;
            			WriteSJAReg(REG_CAN_TEST,temp);
						ErrorFlag =0;
						break;
			}
			else	continue;
    	}
	}
    if(ErrorFlag){
       status  =  SJA_INTERFACE_ERR ;

    }
    return (status);
 }

/*
************************************************************************************************************************
**函数原型:  char   SJAEntryResetMode(void)
**参数说明:  无
**返回值:
**           SJA_OK             ; 表示SJA1000进入复位模式成功
**           SJA_ENTRYRESET_ERR ; 表示SJA1000进入复位模式失败
**
**说明:     该函数用于使sja1000进入复位模式
************************************************************************************************************************
*/
char   SJAEntryResetMode(void)
{
   	char			status=0;
   	unsigned	char		ErrorFlag =1;
	unsigned	char 	ErrorCount = 0x20;							//32次报错
	while(--ErrorCount){
		if((status = SetBitMask(REG_CAN_MOD,RM_RR_BIT)) == 0){
			ErrorFlag =0;
			break;
		}
    }
	if(ErrorFlag){
//       status  = SJA_ENTRYRESET_ERR;
       status  = 1;
	}
    return (status);
}
//       basicCan模式   进入复位模式
char   SJAEntryResetMode_BCan(void)
{
   	char			status=0;
   	unsigned	char		ErrorFlag =1;
	unsigned	char 	ErrorCount = 0x20;							//32次报错
	while(--ErrorCount){
		if((status = SetBitMask(REG_CR,0x01)) == 0){
			ErrorFlag =0;
			break;
		}
    }
	if(ErrorFlag){
//       status  = SJA_ENTRYRESET_ERR;
       status  = 1;
	}
    return (status);
}
/*
************************************************************************************************************************
**函数原型:  char   SJAQuitResetMode(void)
**参数说明:  无
**返回值:
**           SJA_OK             ; 表示SJA1000退出复位模式成功
**           SJA_QUITRESET_ERR  ; 表示SJA1000退出复位模式失败
**
**说明:     该函数用于使sja1000退出复位模式，进入工作模式
************************************************************************************************************************
*/
char   SJAQuitResetMode(void)
{
    char			status=0;
   	unsigned	char		ErrorFlag =1;
	unsigned	char 	ErrorCount = 0x20;							//32次报错
	while(--ErrorCount){
		if((status=ClearBitMask(REG_CAN_MOD,RM_RR_BIT)) == 0){
			ErrorFlag =0;
			break;
		}
	}
	if(ErrorFlag){
          status  = SJA_QUITRESET_ERR;
//            status  = 1；
	}
    return (status);
}

char   SJAQuitResetMode_BCan(void)
{
    char			status=0;
   	unsigned	char		ErrorFlag =1;
	unsigned	char 	ErrorCount = 0x20;							//32次报错
	while(--ErrorCount){
		if((status=ClearBitMask(REG_CR,0x01)) == 0){
			ErrorFlag =0;
			break;
		}
	}
	if(ErrorFlag){
          status  = SJA_QUITRESET_ERR;
//            status  = 1；
	}
    return (status);
}

/*
************************************************************************************************************************
**函数原型:  char   SJAEntryPeliCANMode(void)
**参数说明:  无
**返回值:
**           SJA_OK         ; 表示SJA1000进入PeliCAN模式 成功
**           SJA_INIT_ERR   ; 表示SJA1000进入PeliCAN模式 失败
**
**说明:     该函数用于使sja1000进入PeliCAN模式
************************************************************************************************************************
*/
char   SJAEntryPeliCANMode(void)
{
    char			status=0;
    if(SJATestRstMode()){                                //处于工作模式
       status = SJAEntryResetMode();
    }
    if(status == 0){									 //处于复位模式
       status = SetBitMask(REG_CAN_CDR,CANMode_BIT);    //置位sja1000模式控制位
    }
    return (status);
}

/*
************************************************************************************************************************
**函数原型:  char  SetBitMask(unsigned char RegAdr,unsigned char BitValue)
**参数说明:  RegAdr     要设置位的寄存器地址
**           BitValue   要设置的值
**返回值:
**           SJA_OK(0)      ; 表示设置值 成功
**           SJA_INIT_ERR(1) ; 表示设置值 失败
**
**说明:     该函数用于置位sja1000某寄存器的某位
************************************************************************************************************************
*/
char  SetBitMask(unsigned char RegAdr,unsigned char BitValue)
{
    char            status=0;
    unsigned char   temp;
    unsigned char   temp1;
    unsigned char   temp2;
    temp1 = ReadSJAReg(RegAdr);
    temp = ReadSJAReg(RegAdr)|BitValue;
    WriteSJAReg(RegAdr,temp);
    temp2 = ReadSJAReg(RegAdr);
    if(ReadSJAReg(RegAdr) == temp){
//        status  =  SJA_OK;
        status  =  0;
    }
    else{
//        status  =  SJA_INIT_ERR ;
        status  =  1 ;
    }
    return (status);
}

/*
************************************************************************************************************************
**函数原型:  char  ClearBitMask(unsigned char RegAdr,unsigned char BitValue)
**参数说明:  RegAdr     要清除位的寄存器地址
**           BitValue   要清除的值
**返回值:
**           SJA_OK       ; 表示位清除 成功
**           SJA_INIT_ERR ; 表示位清除 失败
**
**说明:     该函数用于清除sja1000某寄存器的某位
************************************************************************************************************************
*/
char  ClearBitMask(unsigned char RegAdr,unsigned char BitValue)
{
    char			status=0;
    unsigned char   temp;
    unsigned char   m;
    temp = ReadSJAReg(RegAdr)&(~BitValue);
    WriteSJAReg(RegAdr,temp);
    m = ReadSJAReg(RegAdr);
    if(ReadSJAReg(RegAdr) == temp){
    //    status  =  SJA_OK;
          status  =  0;
    }
    else{
    //    status  =  SJA_INIT_ERR ;
          status  =  1;
    }
    return (status);
}

/*
************************************************************************************************************************
**函数原型:  char   SJATestRstMode(void)
**参数说明:  无
**返回值:
**           0   ; 表示SJA1000处于复位模式
**           1   ; 表示SJA1000处于工作模式
**
**说明:     该函数用于测试SJA1000 处于复位模式还是工作模式
************************************************************************************************************************
*/
char   SJATestRstMode(void)
{
    char    SjaFlag;
    if((ReadSJAReg(REG_CAN_MOD)&RM_RR_BIT) ==  RM_RR_BIT){
        SjaFlag  =  0;
    }
    else{
        SjaFlag  = 1 ;
    }
    return (SjaFlag);
}

/*
************************************************************************************************************************
**函数原型:  char		SJASetOutControl(unsigned char	OutCtrl)
**参数说明:  OutCtrl	输出控制寄存器的设定值
**返回值:
**           0				    ; 设置输出控制寄存器成功
**			 SJA_SETOCR_ERR		; 设置输出控制寄存器错
**			 SJA_NOTRSTMODE     ; sja1000不在复位模式
**
**说明:     该函数用于设定sja1000的输出控制
************************************************************************************************************************
*/
char		SJASetOutControl(unsigned char	OutCtrl)
{
	char			status=0;
	bit			ErrorFlag=1;
	unsigned	char 	ErrorCount =0x20;				//32次，报错
	if(SJATestRstMode()){                                //处于工作模式
		status = SJA_NOTRSTMODE;
	}
	else{
		while(--ErrorCount){
			WriteSJAReg(REG_CAN_OCR,OutCtrl);
			if(ReadSJAReg(REG_CAN_OCR) == OutCtrl){
				ErrorFlag=0;
				break;
			}
		}
		if(ErrorFlag){
			status = SJA_SETOCR_ERR;
		}
	}
	return	status;
}

/*
************************************************************************************************************************
**函数原型:  char		SJASetClockDivision(unsigned	char  clockdiv)
**参数说明:  clockdiv	时钟分频寄存器的设定值
**返回值:
**           0				    ; 设置时钟分频寄存器成功
**			 SJA_SETCDR_ERR		; 设置时钟分频寄存器错
**			 SJA_NOTRSTMODE     ; sja1000不在复位模式
**
**说明:     该函数用于设定sja1000的时钟分频寄存器
************************************************************************************************************************
*/
char		SJASetClockDivision(unsigned	char  clockdiv)
{
	char		status=0,temp = 0, temp1 = 0;
	bit			ErrorFlag=1;
	unsigned	char 	ErrorCount =0x20;				//32次，报错
	if(SJATestRstMode()){                                //处于工作模式
		status = SJA_NOTRSTMODE;
	}
	else{
		while(--ErrorCount){
			temp1 = ReadSJAReg(REG_CAN_CDR);
			temp = (temp1 & 0xf0) | (clockdiv & 0x0f);
			WriteSJAReg(REG_CAN_CDR,temp);
			if((ReadSJAReg(REG_CAN_CDR) & 0x0f) == clockdiv){
				ErrorFlag=0;
				break;
			}
		}
		if(ErrorFlag){
			status = SJA_SETCDR_ERR;
		}
	}
	return	status;
}

/*
************************************************************************************************************************
**函数原型:  char	SJASetAccCode(unsigned char	acr0,unsigned char acr1,
**							  unsigned char	acr2,unsigned char acr3
**							  )
**参数说明:  acr0	代码验收寄存器0的设定值
**			 acr1	代码验收寄存器1的设定值
**			 acr2	代码验收寄存器2的设定值
**			 acr3	代码验收寄存器3的设定值
**返回值:
**           0				      ; 设置代码验收寄存器成功
**			 SJA_SETACR_ERR	  ; 设置代码验收寄存器错
**			 SJA_NOTRSTMODE       ; sja1000不在复位模式
**
**说明:     该函数用于设定报文滤波的代码验收滤波器
************************************************************************************************************************
*/
char	SJASetAccCode(unsigned char	acr0,unsigned char acr1,
				  unsigned char	acr2,unsigned char acr3
				  )
{
	char		status=0;
	bit			ErrorFlag=1;
	unsigned	char  	ErrorCount =0x20;				//32次，报错
	if(SJATestRstMode()){                                //处于工作模式
		status = SJA_NOTRSTMODE;
	}
	else{
		while(--ErrorCount){
		 	WriteSJAReg(REG_CAN_ACR0,acr0);
		 	WriteSJAReg(REG_CAN_ACR1,acr1);
		 	WriteSJAReg(REG_CAN_ACR2,acr2);
		 	WriteSJAReg(REG_CAN_ACR3,acr3);
			if(ReadSJAReg(REG_CAN_ACR0) != acr0)continue;
			if(ReadSJAReg(REG_CAN_ACR1) != acr1)continue;
			if(ReadSJAReg(REG_CAN_ACR2) != acr2)continue;
			if(ReadSJAReg(REG_CAN_ACR3) != acr3)continue;
			ErrorFlag=0;
			break;
		}
		if(ErrorFlag){
			status =SJA_SETACR_ERR;
		}
	}
		return	status;
	
}

/*
************************************************************************************************************************
**函数原型:  char	SJASetAccMask(unsigned char	amr0,unsigned char amr1,
**							      unsigned char	amr2,unsigned char amr3
**							      )
**参数说明:  amr0	验收屏蔽寄存器0的设定值
**			 amr1	验收屏蔽寄存器1的设定值
**			 amr2	验收屏蔽寄存器2的设定值
**			 amr3	验收屏蔽寄存器3的设定值
**返回值:
**           0					  ; 设置验收屏蔽寄存器成功
**			 SJA_SETAMR_ERR	  ; 设置验收屏蔽寄存器错
**			 SJA_NOTRSTMODE		  ; sja1000不在复位模式
**
**说明:     该函数用于设定报文滤波的验收屏蔽寄存器
************************************************************************************************************************
*/
char	SJASetAccMask(unsigned char	amr0,unsigned char amr1,
 				      unsigned char	amr2,unsigned char amr3
				      )
{
	char		status=0;
	bit			ErrorFlag=1;
	unsigned	char  	ErrorCount =0x20;				//32次，报错
	if(SJATestRstMode()){                                //处于工作模式
		status = SJA_NOTRSTMODE;
	}
	else{
		while(--ErrorCount){
		 	WriteSJAReg(REG_CAN_AMR0,amr0);
		 	WriteSJAReg(REG_CAN_AMR1,amr1);
		 	WriteSJAReg(REG_CAN_AMR2,amr2);
		 	WriteSJAReg(REG_CAN_AMR3,amr3);
			if(ReadSJAReg(REG_CAN_AMR0) != amr0)continue;
			if(ReadSJAReg(REG_CAN_AMR1) != amr1)continue;
			if(ReadSJAReg(REG_CAN_AMR2) != amr2)continue;
			if(ReadSJAReg(REG_CAN_AMR3) != amr3)continue;
			ErrorFlag=0;
			break;
		}
		if(ErrorFlag){
			status =SJA_SETAMR_ERR;
		}
	}
		return	status;
}
/*
************************************************************************************************************************
**函数原型:  char	SJASetBandRateStandard(unsigned char	BandRateSize)
**参数说明:  BandRateSize		  标准常用波特率(Kbps)
**				0					5
**				1					10
**				2					20
**				3					40
**				4					50
**				5					80
**				6					100
**				7					125
**				8					200
**				9					250
**				10					400
**				11					500
**				12					666
**				13					800
**				14					1000
**返回值:
**           0					  ; 设置总线定时器成功
**			 SJA_SETBTR_ERR		  ; 设置总线定时器错
**			 SJA_NOBTRSIZE		  ;波特率不能设为此值
**
**说明:     该函数用于设定在系统晶体为16MHZ时，常用的标准波特率的值。
**			参数BandRateSize只能为0~12，其它的值会返回SJA_NOBTRSIZE错误
**			本函数只能用于复位模式
************************************************************************************************************************
*/
unsigned  char	SJA_BTR_CODETAB[]={
	  0xbf,0xff,						//;5KBPS的预设值
	  0x67,0x2f,						//;10KBPS的预设值
    0x53,0x2F,		               //;20KBPS的预设值
    0x87,0xFF,                     //;40KBPS的预设值
    0x47,0x2F,                     //;50KBPS的预设值
    0x83,0xFF,                     //;80KBPS的预设值
    0x43,0x2f,                     //;100KBPS的预设值
    0x03,0x1c,                     //;125KBPS的预设值
    0x81,0xfa,                     //;200KBPS的预设值
    0x01,0x1c,                     //;250KBPS的预设值
    0x80,0xfa,                     //;400KBPS的预设值
    0x00,0x1c,                     //;500KBPS的预设值
    0x80,0xb6,                     //;666KBPS的预设值
    0x00,0x16,                     //;800KBPS的预设值
    0x00,0x14                      //;1000KBPS的预设值
  };
char	SJASetBandRateStandard(unsigned char	BandRateSize)
{
	char 	status=0;
	bit		ErrorFlag =1;
	unsigned	char 	ErrorCount = 0x20;				//32次报错
	if(BandRateSize>14){
		status = SJA_NOBTRSIZE;
	}
    else{
		while(--ErrorCount){
				WriteSJAReg(REG_CAN_BTR0,SJA_BTR_CODETAB[BandRateSize*2]);
				WriteSJAReg(REG_CAN_BTR1,SJA_BTR_CODETAB[BandRateSize*2+1]);
				if(ReadSJAReg(REG_CAN_BTR0) != SJA_BTR_CODETAB[BandRateSize*2])continue;
				if(ReadSJAReg(REG_CAN_BTR1) != SJA_BTR_CODETAB[BandRateSize*2+1])continue;
				ErrorFlag=0;
				break;

		}//while结束
		if(ErrorFlag){
			status =SJA_SETBTR_ERR;
		}
	}
	return	status;
}

/*
************************************************************************************************************************
**函数原型:  char	SJASystemPrgCMD(unsigned char cmd)
**参数说明:  cmd	SJA1000 的PeliCAN 工作方式命令字
**返回值:
**           0				  ; 表示命令执行成功
**			 SJA_IMPCMD_ERR	  ; 表示命令执行出错
**			 SJA_NOTHISCMD    ; 没有此命令
**
**说明:     该函数用于执行sja1000的命令
************************************************************************************************************************
*/
char	SJASystemPrgCMD(unsigned char cmd)
{
	char 	status=0;

	switch(cmd){
		case	0x01:
		case	0x03:
			    WriteSJAReg(REG_CAN_CMR,cmd);
				break;
		case	0x02:
				if((ReadSJAReg(REG_CAN_SR)&TBS_BIT) == 0){
					status =  SJA_IMPCMD_ERR;
				}
				break;
		case	0x04:
				WriteSJAReg(REG_CAN_CMR,cmd);
				break;
		case	0x08:
				WriteSJAReg(REG_CAN_CMR,cmd);
				break;
		case	0x10:
		case	0x12:
			    WriteSJAReg(REG_CAN_CMR,cmd);
				break;
		default:
				status = SJA_NOTHISCMD;
				break;
	}
    return		status;

}




/*
************************************************************************************************************************
**函数原型:  char	SJASendData(unsigned	char			*databuf,
**									unsigned	char	cmd
**									)
**参数说明:  databuf	存放要发送到总线的特定帧格式的数据的缓冲区首地址
**			 cmd		sj1000发送命令
**返回值:
**           0				  ; 表示将数据成功的发送到can总线
**			 SJA_TXBUFLOCK	  ; sja1000发送缓冲区锁定
**           SJA_WTXBUF_ERR   ; 表示写发送缓冲区失败
**			 SJA_IMPCMD_ERR	  ; 表示命令执行出错
**
**说明：	本函数用于向can总线发送数据
************************************************************************************************************************
*/
char	SJASendData(unsigned	char  port,
									unsigned	char	*databuf,
									unsigned	char	cmd
								 )
{
	char 	status=0;
	unsigned	char	len;
	unsigned	char	temp = (*databuf&0x0f);
	if(temp>8)temp=8;
	
	 select_chip(port);

	if( (ReadSJAReg(REG_CAN_SR)&TCS_BIT) ==0){//sja1000发送缓冲区锁定
		status =	SJA_TXBUFLOCK;
	}
	else if( (ReadSJAReg(REG_CAN_SR)&RS_BIT) !=0){//正在接收
		status =	SJA_WTXBUF_ERR;
	}

	else{
		switch(*databuf&0xC0) {
			case	0x00://标准帧、数据帧
					len = (unsigned char)(STD_FRAMEID_LENTH+temp+1);
					WriteSJARegBlock(REG_CAN_TXFMINFO,databuf,len);
					status=SJASystemPrgCMD(cmd);
					break;
			case	0x40://标准帧、远程帧
					len=STD_FRAMEID_LENTH+1;
					WriteSJARegBlock(REG_CAN_TXFMINFO,databuf,len);
					status=SJASystemPrgCMD(cmd);
					break;
			case	0x80://扩展帧、数据帧
					len=(unsigned char)(EXT_FRAMEID_LENTH+temp+1);
					WriteSJARegBlock(REG_CAN_TXFMINFO,databuf,len);
					status=SJASystemPrgCMD(cmd);
					break;
			case	0xC0://扩展帧、远程帧
					len=EXT_FRAMEID_LENTH+1;
					WriteSJARegBlock(REG_CAN_TXFMINFO,databuf,len);
					status=SJASystemPrgCMD(cmd);
					break;
			default:status = SJA_WTXBUF_ERR;
					break;
		}
	}

	return	status;
}
/*
************************************************************************************************************************
**函数原型:  char	SJARcvData(unsigned	char			*databuf)
**参数说明:  databuf	存放要接收数据缓冲区首地址
**
**返回值:
**           0				  ; 表示将读取数据成功
**			 SJA_RXBUFEMPTY	  ; sja1000接收缓冲区为空
**           SJA_RRXVUF_ERR   ; sja1000接收数据错
**
**说明：	本函数用于接收can总线数据
************************************************************************************************************************
*/
char	SJARcvData(unsigned	char  port,unsigned	char			*databuf)
{
	char 	status=0;
	unsigned	char	len;
	unsigned	char	temp;
	
	select_chip(port);
	
 	*databuf= ReadSJAReg(REG_CAN_RXFMINFO);
	temp = (*databuf&0x0f);
	if(temp>8)temp=8;

	if( (ReadSJAReg(REG_CAN_SR)&RBS_BIT ) ==0){//sja1000接收缓冲区为空
		status =	SJA_RXBUFEMPTY	;
	}

	else{
		switch(*databuf&0xC0) {
			case	0x00://标准帧、数据帧
					len=STD_FRAMEID_LENTH+temp;
					ReadSJARegBlock(REG_CAN_RXBUF1,databuf+1,len);
					status=	SJASystemPrgCMD(RELEASE_RX_BUF);
					break;
			case	0x40://标准帧、远程帧

					ReadSJARegBlock(REG_CAN_RXBUF1,databuf+1,STD_FRAMEID_LENTH);
					status=	SJASystemPrgCMD(RELEASE_RX_BUF);
					break;
			case	0x80://扩展帧、数据帧
					len=EXT_FRAMEID_LENTH+temp;
					ReadSJARegBlock(REG_CAN_RXBUF1,databuf+1,len);
					status=SJASystemPrgCMD(RELEASE_RX_BUF);
					break;
			case	0xC0://扩展帧、远程帧

					ReadSJARegBlock(REG_CAN_RXBUF1,databuf+1,EXT_FRAMEID_LENTH);
					status=	SJASystemPrgCMD(RELEASE_RX_BUF);
					break;
			default:status = SJA_RRXVUF_ERR;
					break;
		}
	}
	return	status;
}

/*
************************************************************************************************************************
**函数原型:     unsigned	char	ReadALCReg(void)
**参数说明:     无
**返回值:		错误仲裁寄存器(alc)的内容
**
**说明:         该函数用于读取错误仲裁寄存器(alc)的内容
************************************************************************************************************************
*/
unsigned	char	ReadALCReg(void)
{
	return(ReadSJAReg(REG_CAN_ALC));
}

/*
************************************************************************************************************************
**函数原型:     unsigned	char	ReadECCReg(void)
**参数说明:     无
**返回值:		错误捕捉寄存器(ecc)的内容
**
**说明:         该函数用于读取错误捕捉寄存器(ecc)的内容
************************************************************************************************************************
*/
unsigned	char	ReadECCReg(void)
{
	return(ReadSJAReg(REG_CAN_ECC));
}

/*
************************************************************************************************************************
**函数原型:     void	SJA1000_Config(SJAConfigStruct ChipConfig)
**参数说明:     
**返回值:		
**
**说明:         SJA1000配置信息
************************************************************************************************************************
*/
void	SJA1000_Config(SJAConfigStruct ChipConfig)
{
	unsigned char ACR[4];
	unsigned char AMR[4];
	
 select_chip(ChipConfig.ChipNum);  //选择芯片
 SJAEntryResetMode();   //进入复位模式
 SJAEntryPeliCANMode(); //选择peliCAN模式
 SJASetClockDivision(8); //时钟关闭
	
 if(!ChipConfig.ExtendedFrame) //如果是标准帧
	 {ACR[0] = (unsigned char)((ChipConfig.ACR >> 3) & 0xff); //高八位
		ACR[1] = (unsigned char)((ChipConfig.ACR << 5) & 0xE0); //低三位
		ACR[2] = 0; 
		ACR[3] = 0;
		SJASetAccCode(ACR[0],ACR[1],ACR[2],ACR[3]);
		AMR[0] = (unsigned char)((ChipConfig.AMR >> 3) & 0xff); //高八位
		AMR[1] = (unsigned char)((ChipConfig.AMR << 5) & 0xE0); //低三位
		AMR[2] = 0xff; 
		AMR[3] = 0xff;
    SJASetAccMask(AMR[0],AMR[1]|0x0F,AMR[2],AMR[3]); 
	 }
 else   											//如果是扩展帧
	 {
		ACR[0] = (unsigned char)((ChipConfig.ACR >> 21) & 0xFF); //ID.28-ID.21
		ACR[1] = (unsigned char)((ChipConfig.ACR >> 13) & 0xFF); //ID.20-ID.13
		ACR[2] = (unsigned char)((ChipConfig.ACR >>  5) & 0xFF); //ID.12-ID.5
		ACR[3] = (unsigned char)((ChipConfig.ACR <<  3) & 0xF8); //ID.4 -ID.0
		SJASetAccCode(ACR[0],ACR[1],ACR[2],ACR[3]);
		AMR[0] = (unsigned char)((ChipConfig.AMR >> 21) & 0xFF); //ID.28-ID.21
		AMR[1] = (unsigned char)((ChipConfig.AMR >> 13) & 0xFF); //ID.20-ID.13
		AMR[2] = (unsigned char)((ChipConfig.AMR >>  5) & 0xFF); //ID.12-ID.5
		AMR[3] = (unsigned char)((ChipConfig.AMR <<  3) & 0xF8); //ID.4 -ID.0
    SJASetAccMask(AMR[0],AMR[1],AMR[2],AMR[3]|0x03); 
	 }
	SJASetBandRateStandard(ChipConfig.BaudRate);  //波特率
	SJASetOutControl(Tx1Float|Tx0PshPull|NormalMode); //OCR，输出控制寄存器；TX1悬空，TX0推挽；正常输出模式

	WriteSJAReg(REG_CAN_IER,0x01);	/////使能SJA1000接收中断
	SJAQuitResetMode();
	WriteSJAReg(REG_CAN_MOD,0x08);
}
	