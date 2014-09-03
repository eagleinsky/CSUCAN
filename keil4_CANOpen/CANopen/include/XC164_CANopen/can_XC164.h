#ifndef __CAN_XC164__
#define __CAN_XC164__

// 与硬件相关的宏定义
#include "PELI.H"
#include "can.h"

//声明用户函数
//unsigned char canInit(unsigned int bitrate);
unsigned char canSend(CAN_PORT notused, Message *m);
unsigned char canReceive(CAN_PORT notused, Message *m);
//unsigned char canChangeBaudRate_driver( CAN_HANDLE fd, char* baud);
#endif
