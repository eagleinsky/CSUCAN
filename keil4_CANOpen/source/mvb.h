#ifndef _MVB_H_
#define _MVB_H_

//MVB板 FPGA 双口RAM 偏移地址
//#define PORT1 0x162
//#define PORT2 0x184
//#define PORT3 0x1A6
//#define PORT4 0x1C8
#define p_mvb_mem (unsigned char volatile far *)0x1000 

void mvb_init(unsigned int source1,unsigned int source2,unsigned int sink1,unsigned int sink2);		//MVB初始化函数  依次为源端口1 源端口2 宿端口1 宿端口2
void write_source_port(unsigned char port_num,unsigned char * src_buffer);							//向源端口1或者2写数据
void read_sink_port(unsigned char port_num,unsigned char * dst_buffer);								//从宿端口1或者2读数据

#endif 