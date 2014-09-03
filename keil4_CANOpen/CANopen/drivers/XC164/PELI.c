/*
 ********************************************************************************************************************
 *������    ������CAN ������SJA1000pelicanģʽӦ�ú����ļ�
 *�ļ���:   SJA_PELI.C
 *Ӧ������: KEIL C166
 *�汾 :    V1.01
  ********************************************************************************************************************
 */
#define		_SJA_PELICAN_MODE_
#define		_GLOBAL_SJA1000_PELI_APP_

/*
************************************************************************************************************************
**                           ����ͷ�ļ�
************************************************************************************************************************
*/
#include	"PELI.H"

/*
************************************************************************************************************************
**                           ����ԭ��˵��
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
**����ԭ��:     char   SJATestInterface(unsigned char  testvalue)
**����˵��:     Value  ����ֵ
**����ֵ:
**              SJA_OK            ; ��ʾSJA1000�ӿ�����
**              SJA_INTERFACE_ERR ; ��ʾSJA1000�봦�����ӿڳ���
**
**˵��:         �ú������ڼ��CAN�������Ľӿ��Ƿ�����
************************************************************************************************************************
*/
 char    SJATestInterface(unsigned char  testvalue)
 {
        char		status=0;
	bit		ErrorFlag =1;
	unsigned char 	ErrorCount = 0x20;							//32�α���
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
**����ԭ��:  char   SJAEntryResetMode(void)
**����˵��:  ��
**����ֵ:
**           SJA_OK             ; ��ʾSJA1000���븴λģʽ�ɹ�
**           SJA_ENTRYRESET_ERR ; ��ʾSJA1000���븴λģʽʧ��
**
**˵��:     �ú�������ʹsja1000���븴λģʽ
************************************************************************************************************************
*/
char   SJAEntryResetMode(void)
{
   	char			status=0;
   	unsigned	char		ErrorFlag =1;
	unsigned	char 	ErrorCount = 0x20;							//32�α���
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
//       basicCanģʽ   ���븴λģʽ
char   SJAEntryResetMode_BCan(void)
{
   	char			status=0;
   	unsigned	char		ErrorFlag =1;
	unsigned	char 	ErrorCount = 0x20;							//32�α���
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
**����ԭ��:  char   SJAQuitResetMode(void)
**����˵��:  ��
**����ֵ:
**           SJA_OK             ; ��ʾSJA1000�˳���λģʽ�ɹ�
**           SJA_QUITRESET_ERR  ; ��ʾSJA1000�˳���λģʽʧ��
**
**˵��:     �ú�������ʹsja1000�˳���λģʽ�����빤��ģʽ
************************************************************************************************************************
*/
char   SJAQuitResetMode(void)
{
    char			status=0;
   	unsigned	char		ErrorFlag =1;
	unsigned	char 	ErrorCount = 0x20;							//32�α���
	while(--ErrorCount){
		if((status=ClearBitMask(REG_CAN_MOD,RM_RR_BIT)) == 0){
			ErrorFlag =0;
			break;
		}
	}
	if(ErrorFlag){
          status  = SJA_QUITRESET_ERR;
//            status  = 1��
	}
    return (status);
}

char   SJAQuitResetMode_BCan(void)
{
    char			status=0;
   	unsigned	char		ErrorFlag =1;
	unsigned	char 	ErrorCount = 0x20;							//32�α���
	while(--ErrorCount){
		if((status=ClearBitMask(REG_CR,0x01)) == 0){
			ErrorFlag =0;
			break;
		}
	}
	if(ErrorFlag){
          status  = SJA_QUITRESET_ERR;
//            status  = 1��
	}
    return (status);
}

/*
************************************************************************************************************************
**����ԭ��:  char   SJAEntryPeliCANMode(void)
**����˵��:  ��
**����ֵ:
**           SJA_OK         ; ��ʾSJA1000����PeliCANģʽ �ɹ�
**           SJA_INIT_ERR   ; ��ʾSJA1000����PeliCANģʽ ʧ��
**
**˵��:     �ú�������ʹsja1000����PeliCANģʽ
************************************************************************************************************************
*/
char   SJAEntryPeliCANMode(void)
{
    char			status=0;
    if(SJATestRstMode()){                                //���ڹ���ģʽ
       status = SJAEntryResetMode();
    }
    if(status == 0){									 //���ڸ�λģʽ
       status = SetBitMask(REG_CAN_CDR,CANMode_BIT);    //��λsja1000ģʽ����λ
    }
    return (status);
}

/*
************************************************************************************************************************
**����ԭ��:  char  SetBitMask(unsigned char RegAdr,unsigned char BitValue)
**����˵��:  RegAdr     Ҫ����λ�ļĴ�����ַ
**           BitValue   Ҫ���õ�ֵ
**����ֵ:
**           SJA_OK(0)      ; ��ʾ����ֵ �ɹ�
**           SJA_INIT_ERR(1) ; ��ʾ����ֵ ʧ��
**
**˵��:     �ú���������λsja1000ĳ�Ĵ�����ĳλ
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
**����ԭ��:  char  ClearBitMask(unsigned char RegAdr,unsigned char BitValue)
**����˵��:  RegAdr     Ҫ���λ�ļĴ�����ַ
**           BitValue   Ҫ�����ֵ
**����ֵ:
**           SJA_OK       ; ��ʾλ��� �ɹ�
**           SJA_INIT_ERR ; ��ʾλ��� ʧ��
**
**˵��:     �ú����������sja1000ĳ�Ĵ�����ĳλ
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
**����ԭ��:  char   SJATestRstMode(void)
**����˵��:  ��
**����ֵ:
**           0   ; ��ʾSJA1000���ڸ�λģʽ
**           1   ; ��ʾSJA1000���ڹ���ģʽ
**
**˵��:     �ú������ڲ���SJA1000 ���ڸ�λģʽ���ǹ���ģʽ
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
**����ԭ��:  char		SJASetOutControl(unsigned char	OutCtrl)
**����˵��:  OutCtrl	������ƼĴ������趨ֵ
**����ֵ:
**           0				    ; ����������ƼĴ����ɹ�
**			 SJA_SETOCR_ERR		; ����������ƼĴ�����
**			 SJA_NOTRSTMODE     ; sja1000���ڸ�λģʽ
**
**˵��:     �ú��������趨sja1000���������
************************************************************************************************************************
*/
char		SJASetOutControl(unsigned char	OutCtrl)
{
	char			status=0;
	bit			ErrorFlag=1;
	unsigned	char 	ErrorCount =0x20;				//32�Σ�����
	if(SJATestRstMode()){                                //���ڹ���ģʽ
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
**����ԭ��:  char		SJASetClockDivision(unsigned	char  clockdiv)
**����˵��:  clockdiv	ʱ�ӷ�Ƶ�Ĵ������趨ֵ
**����ֵ:
**           0				    ; ����ʱ�ӷ�Ƶ�Ĵ����ɹ�
**			 SJA_SETCDR_ERR		; ����ʱ�ӷ�Ƶ�Ĵ�����
**			 SJA_NOTRSTMODE     ; sja1000���ڸ�λģʽ
**
**˵��:     �ú��������趨sja1000��ʱ�ӷ�Ƶ�Ĵ���
************************************************************************************************************************
*/
char		SJASetClockDivision(unsigned	char  clockdiv)
{
	char		status=0,temp = 0, temp1 = 0;
	bit			ErrorFlag=1;
	unsigned	char 	ErrorCount =0x20;				//32�Σ�����
	if(SJATestRstMode()){                                //���ڹ���ģʽ
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
**����ԭ��:  char	SJASetAccCode(unsigned char	acr0,unsigned char acr1,
**							  unsigned char	acr2,unsigned char acr3
**							  )
**����˵��:  acr0	�������ռĴ���0���趨ֵ
**			 acr1	�������ռĴ���1���趨ֵ
**			 acr2	�������ռĴ���2���趨ֵ
**			 acr3	�������ռĴ���3���趨ֵ
**����ֵ:
**           0				      ; ���ô������ռĴ����ɹ�
**			 SJA_SETACR_ERR	  ; ���ô������ռĴ�����
**			 SJA_NOTRSTMODE       ; sja1000���ڸ�λģʽ
**
**˵��:     �ú��������趨�����˲��Ĵ��������˲���
************************************************************************************************************************
*/
char	SJASetAccCode(unsigned char	acr0,unsigned char acr1,
				  unsigned char	acr2,unsigned char acr3
				  )
{
	char		status=0;
	bit			ErrorFlag=1;
	unsigned	char  	ErrorCount =0x20;				//32�Σ�����
	if(SJATestRstMode()){                                //���ڹ���ģʽ
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
**����ԭ��:  char	SJASetAccMask(unsigned char	amr0,unsigned char amr1,
**							      unsigned char	amr2,unsigned char amr3
**							      )
**����˵��:  amr0	�������μĴ���0���趨ֵ
**			 amr1	�������μĴ���1���趨ֵ
**			 amr2	�������μĴ���2���趨ֵ
**			 amr3	�������μĴ���3���趨ֵ
**����ֵ:
**           0					  ; �����������μĴ����ɹ�
**			 SJA_SETAMR_ERR	  ; �����������μĴ�����
**			 SJA_NOTRSTMODE		  ; sja1000���ڸ�λģʽ
**
**˵��:     �ú��������趨�����˲����������μĴ���
************************************************************************************************************************
*/
char	SJASetAccMask(unsigned char	amr0,unsigned char amr1,
 				      unsigned char	amr2,unsigned char amr3
				      )
{
	char		status=0;
	bit			ErrorFlag=1;
	unsigned	char  	ErrorCount =0x20;				//32�Σ�����
	if(SJATestRstMode()){                                //���ڹ���ģʽ
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
**����ԭ��:  char	SJASetBandRateStandard(unsigned char	BandRateSize)
**����˵��:  BandRateSize		  ��׼���ò�����(Kbps)
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
**����ֵ:
**           0					  ; �������߶�ʱ���ɹ�
**			 SJA_SETBTR_ERR		  ; �������߶�ʱ����
**			 SJA_NOBTRSIZE		  ;�����ʲ�����Ϊ��ֵ
**
**˵��:     �ú��������趨��ϵͳ����Ϊ16MHZʱ�����õı�׼�����ʵ�ֵ��
**			����BandRateSizeֻ��Ϊ0~12��������ֵ�᷵��SJA_NOBTRSIZE����
**			������ֻ�����ڸ�λģʽ
************************************************************************************************************************
*/
unsigned  char	SJA_BTR_CODETAB[]={
	  0xbf,0xff,						//;5KBPS��Ԥ��ֵ
	  0x67,0x2f,						//;10KBPS��Ԥ��ֵ
    0x53,0x2F,		               //;20KBPS��Ԥ��ֵ
    0x87,0xFF,                     //;40KBPS��Ԥ��ֵ
    0x47,0x2F,                     //;50KBPS��Ԥ��ֵ
    0x83,0xFF,                     //;80KBPS��Ԥ��ֵ
    0x43,0x2f,                     //;100KBPS��Ԥ��ֵ
    0x03,0x1c,                     //;125KBPS��Ԥ��ֵ
    0x81,0xfa,                     //;200KBPS��Ԥ��ֵ
    0x01,0x1c,                     //;250KBPS��Ԥ��ֵ
    0x80,0xfa,                     //;400KBPS��Ԥ��ֵ
    0x00,0x1c,                     //;500KBPS��Ԥ��ֵ
    0x80,0xb6,                     //;666KBPS��Ԥ��ֵ
    0x00,0x16,                     //;800KBPS��Ԥ��ֵ
    0x00,0x14                      //;1000KBPS��Ԥ��ֵ
  };
char	SJASetBandRateStandard(unsigned char	BandRateSize)
{
	char 	status=0;
	bit		ErrorFlag =1;
	unsigned	char 	ErrorCount = 0x20;				//32�α���
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

		}//while����
		if(ErrorFlag){
			status =SJA_SETBTR_ERR;
		}
	}
	return	status;
}

/*
************************************************************************************************************************
**����ԭ��:  char	SJASystemPrgCMD(unsigned char cmd)
**����˵��:  cmd	SJA1000 ��PeliCAN ������ʽ������
**����ֵ:
**           0				  ; ��ʾ����ִ�гɹ�
**			 SJA_IMPCMD_ERR	  ; ��ʾ����ִ�г���
**			 SJA_NOTHISCMD    ; û�д�����
**
**˵��:     �ú�������ִ��sja1000������
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
**����ԭ��:  char	SJASendData(unsigned	char			*databuf,
**									unsigned	char	cmd
**									)
**����˵��:  databuf	���Ҫ���͵����ߵ��ض�֡��ʽ�����ݵĻ������׵�ַ
**			 cmd		sj1000��������
**����ֵ:
**           0				  ; ��ʾ�����ݳɹ��ķ��͵�can����
**			 SJA_TXBUFLOCK	  ; sja1000���ͻ���������
**           SJA_WTXBUF_ERR   ; ��ʾд���ͻ�����ʧ��
**			 SJA_IMPCMD_ERR	  ; ��ʾ����ִ�г���
**
**˵����	������������can���߷�������
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

	if( (ReadSJAReg(REG_CAN_SR)&TCS_BIT) ==0){//sja1000���ͻ���������
		status =	SJA_TXBUFLOCK;
	}
	else if( (ReadSJAReg(REG_CAN_SR)&RS_BIT) !=0){//���ڽ���
		status =	SJA_WTXBUF_ERR;
	}

	else{
		switch(*databuf&0xC0) {
			case	0x00://��׼֡������֡
					len = (unsigned char)(STD_FRAMEID_LENTH+temp+1);
					WriteSJARegBlock(REG_CAN_TXFMINFO,databuf,len);
					status=SJASystemPrgCMD(cmd);
					break;
			case	0x40://��׼֡��Զ��֡
					len=STD_FRAMEID_LENTH+1;
					WriteSJARegBlock(REG_CAN_TXFMINFO,databuf,len);
					status=SJASystemPrgCMD(cmd);
					break;
			case	0x80://��չ֡������֡
					len=(unsigned char)(EXT_FRAMEID_LENTH+temp+1);
					WriteSJARegBlock(REG_CAN_TXFMINFO,databuf,len);
					status=SJASystemPrgCMD(cmd);
					break;
			case	0xC0://��չ֡��Զ��֡
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
**����ԭ��:  char	SJARcvData(unsigned	char			*databuf)
**����˵��:  databuf	���Ҫ�������ݻ������׵�ַ
**
**����ֵ:
**           0				  ; ��ʾ����ȡ���ݳɹ�
**			 SJA_RXBUFEMPTY	  ; sja1000���ջ�����Ϊ��
**           SJA_RRXVUF_ERR   ; sja1000�������ݴ�
**
**˵����	���������ڽ���can��������
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

	if( (ReadSJAReg(REG_CAN_SR)&RBS_BIT ) ==0){//sja1000���ջ�����Ϊ��
		status =	SJA_RXBUFEMPTY	;
	}

	else{
		switch(*databuf&0xC0) {
			case	0x00://��׼֡������֡
					len=STD_FRAMEID_LENTH+temp;
					ReadSJARegBlock(REG_CAN_RXBUF1,databuf+1,len);
					status=	SJASystemPrgCMD(RELEASE_RX_BUF);
					break;
			case	0x40://��׼֡��Զ��֡

					ReadSJARegBlock(REG_CAN_RXBUF1,databuf+1,STD_FRAMEID_LENTH);
					status=	SJASystemPrgCMD(RELEASE_RX_BUF);
					break;
			case	0x80://��չ֡������֡
					len=EXT_FRAMEID_LENTH+temp;
					ReadSJARegBlock(REG_CAN_RXBUF1,databuf+1,len);
					status=SJASystemPrgCMD(RELEASE_RX_BUF);
					break;
			case	0xC0://��չ֡��Զ��֡

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
**����ԭ��:     unsigned	char	ReadALCReg(void)
**����˵��:     ��
**����ֵ:		�����ٲüĴ���(alc)������
**
**˵��:         �ú������ڶ�ȡ�����ٲüĴ���(alc)������
************************************************************************************************************************
*/
unsigned	char	ReadALCReg(void)
{
	return(ReadSJAReg(REG_CAN_ALC));
}

/*
************************************************************************************************************************
**����ԭ��:     unsigned	char	ReadECCReg(void)
**����˵��:     ��
**����ֵ:		����׽�Ĵ���(ecc)������
**
**˵��:         �ú������ڶ�ȡ����׽�Ĵ���(ecc)������
************************************************************************************************************************
*/
unsigned	char	ReadECCReg(void)
{
	return(ReadSJAReg(REG_CAN_ECC));
}

/*
************************************************************************************************************************
**����ԭ��:     void	SJA1000_Config(SJAConfigStruct ChipConfig)
**����˵��:     
**����ֵ:		
**
**˵��:         SJA1000������Ϣ
************************************************************************************************************************
*/
void	SJA1000_Config(SJAConfigStruct ChipConfig)
{
	unsigned char ACR[4];
	unsigned char AMR[4];
	
 select_chip(ChipConfig.ChipNum);  //ѡ��оƬ
 SJAEntryResetMode();   //���븴λģʽ
 SJAEntryPeliCANMode(); //ѡ��peliCANģʽ
 SJASetClockDivision(8); //ʱ�ӹر�
	
 if(!ChipConfig.ExtendedFrame) //����Ǳ�׼֡
	 {ACR[0] = (unsigned char)((ChipConfig.ACR >> 3) & 0xff); //�߰�λ
		ACR[1] = (unsigned char)((ChipConfig.ACR << 5) & 0xE0); //����λ
		ACR[2] = 0; 
		ACR[3] = 0;
		SJASetAccCode(ACR[0],ACR[1],ACR[2],ACR[3]);
		AMR[0] = (unsigned char)((ChipConfig.AMR >> 3) & 0xff); //�߰�λ
		AMR[1] = (unsigned char)((ChipConfig.AMR << 5) & 0xE0); //����λ
		AMR[2] = 0xff; 
		AMR[3] = 0xff;
    SJASetAccMask(AMR[0],AMR[1]|0x0F,AMR[2],AMR[3]); 
	 }
 else   											//�������չ֡
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
	SJASetBandRateStandard(ChipConfig.BaudRate);  //������
	SJASetOutControl(Tx1Float|Tx0PshPull|NormalMode); //OCR��������ƼĴ�����TX1���գ�TX0���죻�������ģʽ

	WriteSJAReg(REG_CAN_IER,0x01);	/////ʹ��SJA1000�����ж�
	SJAQuitResetMode();
	WriteSJAReg(REG_CAN_MOD,0x08);
}
	