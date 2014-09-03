#include "can_XC164.h"
#include "canfestival.h"

#define  REG_TXFMINFO_EFF 0x80   // CAN��������������չ֡
#define  REG_TXFMINFO_SFF 0x00   // CAN�����������ͱ�׼֡

#define  REG_TXFMINFO_RTR 0x40   // CAN������������Զ��֡
#define  REG_TXFMINFO_DAT 0x00   // CAN����������������֡



/*
************************************************************************************************************************
**����ԭ��:     UNS8 canSend(CAN_PORT port, Message *m)
**����˵��:     port  �˿ںţ���1��2��Ч
**              Message ������Ϣ����CAN.h
**����ֵ:
**              
**
**˵��:         ����׼֡
************************************************************************************************************************
*/
UNS8 canSend(CAN_PORT port, Message *m)
{
 UNS8 databuf[13] = {0};
 UNS8 i,state;
 
 databuf[0] = 0;   //TX֡��Ϣ
 if(m->rtr)
		{databuf[0] |= REG_TXFMINFO_RTR;}
 databuf[0] |= (m->len & 0x0f);
 
 databuf[1] = (UNS8)(m->cob_id >> 3);  //TXʶ����_�߰�λ
 databuf[2] = (UNS8)(m->cob_id << 5);  //TXʶ����_����λ

 for(i=0;i<8;i++)
	{
		databuf[i+3] = m->data[i];
  }
	
	state = SJASendData(port,databuf,TR_BIT);

	return state;
}

unsigned char canReceive(CAN_PORT port, Message *m)
{
  UNS8 databuf[13] = {0};
  UNS8 i,state;

	state = SJARcvData(port,databuf);
  
  if(state)
			return state;

  m->len = databuf[0] & 0x0f;

  if(databuf[0] & REG_TXFMINFO_RTR)
			m->rtr = 1;
	else
		  m->rtr = 0;
  
 for(i=0;i<8;i++)
	{
		m->data[i] = databuf[i+3];
  }
	m->cob_id = databuf[1];
	m->cob_id = m->cob_id << 3;
	m->cob_id += (databuf[2] >> 5) &0x07;
	
	return state;
}

//typedef struct {
//  UNS16 cob_id;	/**< message's ID */
//  UNS8 rtr;		/**< remote transmission request. (0 if not rtr message, 1 if rtr message) */
//  UNS8 len;		/**< message's length (0 to 8) */
//  UNS8 data[8]; /**< message's datas */
//} Message;
