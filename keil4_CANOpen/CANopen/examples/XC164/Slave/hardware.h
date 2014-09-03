#ifndef _HARDWARE_INCLUDED
#define _HARDWARE_INCLUDED


// ������Է���λ����
#define setbit(address,bit) ((address) |= (1<<(bit)))
#define clearbit(address,bit) ((address) &= ~(1<<(bit)))
#define togglebit(address,bit) ((address) ^= (1<<(bit)))
#define checkbit(address,bit) ((address) & (1<<(bit)))

// ��������صĺ�
#define get_inputs()		(~PINA)
#define read_bcd()		(~PINC & 0x0F)
// �������صĺ�
#define set_outputs(val)	PORTB = ~(val)

#endif


