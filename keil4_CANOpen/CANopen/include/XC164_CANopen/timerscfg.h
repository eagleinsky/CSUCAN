#ifndef __TIMERSCFG_H__
#define __TIMERSCFG_H__

// 注意TIMEVAL必须大于32位
#define TIMEVAL UNS32

// 定时器以CTC模式从0000到FFFF，可通过设置OCR3A改变周期时间
#define TIMEVAL_MAX 0xFFFF

// 每8us增加一次
#define MS_TO_TIMEVAL(ms) ((ms) * 125)
#define US_TO_TIMEVAL(us) ((us)>>3)

#endif
