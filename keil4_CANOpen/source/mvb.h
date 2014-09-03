#ifndef _MVB_H_
#define _MVB_H_

//MVB�� FPGA ˫��RAM ƫ�Ƶ�ַ
//#define PORT1 0x162
//#define PORT2 0x184
//#define PORT3 0x1A6
//#define PORT4 0x1C8
#define p_mvb_mem (unsigned char volatile far *)0x1000 

void mvb_init(unsigned int source1,unsigned int source2,unsigned int sink1,unsigned int sink2);		//MVB��ʼ������  ����ΪԴ�˿�1 Դ�˿�2 �޶˿�1 �޶˿�2
void write_source_port(unsigned char port_num,unsigned char * src_buffer);							//��Դ�˿�1����2д����
void read_sink_port(unsigned char port_num,unsigned char * dst_buffer);								//���޶˿�1����2������

#endif 