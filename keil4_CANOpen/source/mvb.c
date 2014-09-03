#include "MAIN.H"

void mvb_init(unsigned int source1,unsigned int source2,unsigned int sink1,unsigned int sink2)
{
	unsigned int i;
	for(i = 0; i < 0x400; i++)
	{
		*(p_mvb_mem + i) = 0x00;
		delay(1);
	}	
	*(p_mvb_mem+0x150) = 2;       // 2个源端口 2个宿端口
	*(p_mvb_mem+0x160) = (unsigned char) source1;    //源端口1地址低八位
	*(p_mvb_mem+0x161) =  (unsigned char)(source1>>8);    //源端口1地址高八位
	
	*(p_mvb_mem+0x182) =  (unsigned char)source2;    //源端口2地址低八位
	*(p_mvb_mem+0x183) =  (unsigned char)(source2>>8);	  //源端口2口地址高八位

	*(p_mvb_mem+0x1A4) = (unsigned char)sink1;;    //宿端口1地址低八位
	*(p_mvb_mem+0x1A5) = (unsigned char)(sink1>>8);    //宿端口1地址高八位
	
	*(p_mvb_mem+0x1C6) = (unsigned char)sink2;    //宿端口2地址低八位
	*(p_mvb_mem+0x1C7) = (unsigned char)(sink1>>8);	  //宿端口2地址高八位
	
	
}

void write_source_port(unsigned char port_num,unsigned char * src_buffer)
{	
	unsigned char i = 0;	
	if(port_num==1)
	{
	for(i = 0; i < 32; i++)
 	{
		*(p_mvb_mem + 0x162 + i) = *(src_buffer + i);  
	  delay(1);
	}
	}
	else if(port_num==2)
	{
	for(i = 0; i < 32; i++)
 	{
		*(p_mvb_mem + 0x184 + i) = *(src_buffer + i);  
	  delay(1);
	}
	}
	
}

void read_sink_port(unsigned char port_num,unsigned char * dst_buffer)
{
	unsigned char i = 0;
	if(port_num==1)
	{
	for(i = 0; i < 32; i++)
 	{
	  *(dst_buffer + i) = *(p_mvb_mem + 0x1a6 + i);   
	  delay(1);
	}
	}
	else if(port_num==2)
	for(i = 0; i < 32; i++)
 	{
	*(dst_buffer + i) = *(p_mvb_mem + 0x1c8 + i);   
	  delay(1);
	}
}


