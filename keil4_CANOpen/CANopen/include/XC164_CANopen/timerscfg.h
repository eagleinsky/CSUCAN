#ifndef __TIMERSCFG_H__
#define __TIMERSCFG_H__

// ע��TIMEVAL�������32λ
#define TIMEVAL UNS32

// ��ʱ����CTCģʽ��0000��FFFF����ͨ������OCR3A�ı�����ʱ��
#define TIMEVAL_MAX 0xFFFF

// ÿ8us����һ��
#define MS_TO_TIMEVAL(ms) ((ms) * 125)
#define US_TO_TIMEVAL(us) ((us)>>3)

#endif
