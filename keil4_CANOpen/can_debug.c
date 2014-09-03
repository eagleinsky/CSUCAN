#include "main.h"

static unsigned char j = 0, k = 0;
uchar send_buf[] = {0x08,0xa0,0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,110,120};
void can_debug(int candeal)
{
 	if(candeal==0x10a0)
			{
			j++;
			DIO_ALL->do_out = recv_buf1[4];			
			if(j==100)
			{
			j=0;
			send_buf[1] = 0xa0;
			send_buf[3] = DIO_ALL->dio1_in;
			send_buf[4] = DIO_ALL->dio2_in;
			can_send(1,send_buf);
			}
			}

			if(candeal==0x10a1)
			{
			j++;
			
			dpram_data->aout[0]=((UINT16)recv_buf1[4]<<8)+recv_buf1[5];
  			dpram_data->aout[1]=((UINT16)recv_buf1[6]<<8)+recv_buf1[7];			
			if(j==100)
			{
			j=0;
			send_buf[1] = 0xa1;
			send_buf[3] = (UINT8)(dpram_data->ain[0]>>8);
			send_buf[4] = (UINT8)dpram_data->ain[0];
			send_buf[5] = (UINT8)(dpram_data->ain[1]>>8);
			send_buf[6] = (UINT8)dpram_data->ain[1];
			send_buf[7] = (UINT8)(dpram_data->ain[2]>>8);
			send_buf[8] = (UINT8)dpram_data->ain[2];
			send_buf[9] = (UINT8)(dpram_data->ain[3]>>8);
			send_buf[10] = (UINT8)dpram_data->ain[4];
			can_send(1,send_buf);
			}
			}
			if(candeal==0x10a3)
			{
			j++;
			for(k=0;k<8;k++)
			{mvb_buf_so1[k]=recv_buf1[k+4]; }
						
			if(j==100)
			{
			j=0;
			send_buf[1] = 0xa3;
			send_buf[3] = mvb_buf_si[0];
			send_buf[4] = mvb_buf_si[1];
			send_buf[5] = mvb_buf_si[2];
			send_buf[6] = mvb_buf_si[3];
			send_buf[7] = mvb_buf_si[4];
			send_buf[8] = mvb_buf_si[5];
			send_buf[9] = mvb_buf_si[6];
			send_buf[10] = mvb_buf_si[7];
			can_send(1,send_buf);
			}
			}
			if(candeal==0x10a4)
			{
			j++;
			for(k=0;k<8;k++)
			{mvb_buf_so2[k]=recv_buf1[k+4]; }
						
			if(j==100)
			{
			j=0;
			send_buf[1] = 0xa4;
			send_buf[3] = mvb_buf_si2[0];
			send_buf[4] = mvb_buf_si2[1];
			send_buf[5] = mvb_buf_si2[2];
			send_buf[6] = mvb_buf_si2[3];
			send_buf[7] = mvb_buf_si2[4];
			send_buf[8] = mvb_buf_si2[5];
			send_buf[9] = mvb_buf_si2[6];
			send_buf[10] = mvb_buf_si2[7];
			can_send(1,send_buf);
			}
			}
			if(candeal==0x10a5)
			{
			j++;
									
			if(j==100)
			{
			j=0;
			send_buf[1] = 0xa5;
			send_buf[3] =(UINT8)can_nod;			
			can_send(1,send_buf);
			}
			}
}