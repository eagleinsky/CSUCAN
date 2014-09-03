#ifndef _HARDWARE_INCLUDED
#define _HARDWARE_INCLUDED


// 定义宏以方便位操作
#define setbit(address,bit) ((address) |= (1<<(bit)))
#define clearbit(address,bit) ((address) &= ~(1<<(bit)))
#define togglebit(address,bit) ((address) ^= (1<<(bit)))
#define checkbit(address,bit) ((address) & (1<<(bit)))

// 与输入相关的宏
#define get_inputs()		(~PINA)
#define read_bcd()		(~PINC & 0x0F)
// 与输出相关的宏
#define set_outputs(val)	PORTB = ~(val)

#endif


