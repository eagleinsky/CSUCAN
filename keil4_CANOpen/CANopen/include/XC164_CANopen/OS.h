/*
 ********************************************************************************************************************
 *描述：    独立的CAN 控制器SJA1000系统应用常量定义头文件
 *文件名:   SJA1000OS.H
 *应用语言: KEIL C51
 *版本 :    V1.01
 *广州周立功单片机发展有限公司 保留所有的版权
 ********************************************************************************************************************
 */
#ifndef		_SJA1000OS_H
#define		_SJA1000OS_H

/*
 ********************************************************************************************************************
 * 定义标准帧或扩展帧的报文识别码的长度
 ********************************************************************************************************************
 */
#define		STD_FRAMEID_LENTH	  	0x02
#define		EXT_FRAMEID_LENTH	  	0x04

/*
 ********************************************************************************************************************
 * 定义标准帧或扩展帧的长度
 ********************************************************************************************************************
 */
#define		STD_FRAME_LENTH	  		11
#define		EXT_FRAME_LENTH	  		13

/*
 ********************************************************************************************************************
 *                      SJA1000 的PeliCAN 工作方式命令字定义
 *      每一个命令字都通过将该命令字写入命令寄存器，两条命令之间必须至少间隔一个内部时钟
 *  周期（内部时钟频率为外部振荡器频率的1/2）
 ********************************************************************************************************************
*/
#define     NORMAL_SEND             0x01        //SJA1000正常发送命令，允许自动重发
#define	    STOP_SEND   	        0x02	    //中止发送位
#define     SINGLE_SEND             0X03        //单次发送，不自动重发
#define     RELEASE_RX_BUF	        0x04	    //释放接收缓冲器
#define     CLR_DATA_OVER  	        0x08	    //清除数据溢出
#define     SELF_RCV_REQUEST        0x10        //自身接收请求
#define     SELF_SINGLE_RCVSEND     0X12        //单次自接收性质的信息发送

/*
 ********************************************************************************************************************
 *                      SJA1000 的PeliCAN 工作方式 错误代码定义
 *      每一个PeliCAN 工作方式下的函数都将产生一个返回值，该值应该符合下面的代码定义
 ********************************************************************************************************************
*/
#define     SJA_OK                  0x00

#define     SJA_INTERFACE_ERR       (-1)        //与微处理器接口错
#define     SJA_ENTRYRESET_ERR      (-2)        //进复位状态错
#define     SJA_QUITRESET_ERR       (-3)        //退出复位状态错
#define     SJA_INIT_ERR            (-4)        //SJA1000初始化错
#define     SJA_CODE_ERR            (-5)        //SJA1000代码错
#define     SJA_FRAME_ERR           (-6)        //帧格式错
#define     SJA_WTXBUF_ERR          (-7)        //写sja1000发送缓冲区错

#define     SJA_CANBUS_ERR          (-8)        //总线错误 （关闭）

#define		SJA_TXBUFLOCK			(-9)		//sja1000发送缓冲区锁定
#define		SJA_RXBUFEMPTY			(-10)		//sja1000接收缓冲区为空
#define		SJA_RRXVUF_ERR			(-11)		//sja1000接收数据错

#define		SJA_SETACR_ERR			(-12)		//设置代码验收寄存器错
#define		SJA_NOTRSTMODE          	(-13)		//sja1000不在复位模式，却调用了初始化函数

#define		SJA_SETBTR_ERR			(-14)		//设置总线定时器错
#define		SJA_NOBTRSIZE			(-15)		//波特率不能设为此值

#define		SJA_SETAMR_ERR			(-16)		//设置验收屏蔽寄存器错

#define		SJA_SETOCR_ERR			(-17)		//设置输出控制寄存器错
#define     SJA_SETCDR_ERR			(-18)		//设置时钟分频寄存器错

#define     SJA_IMPCMD_ERR			(-19)		//命令执行出错
#define		SJA_NOTHISCMD			(-20)		//没有此命令

/*
 ********************************************************************************************************************
 *                     定义16M的晶体下，CAN总线通用波特率代表的数值   
 ********************************************************************************************************************
*/
#define         ByteRate_5k      	0x00          //波特率5kbps
#define         ByteRate_10k      	0x01          //波特率10kbps
#define         ByteRate_20k      	0x02          //波特率20kbps
#define         ByteRate_40k      	0x03          //波特率40kbps
#define         ByteRate_50k      	0x04          //波特率50kbps
#define         ByteRate_80k      	0x05          //波特率80kbps
#define         ByteRate_100k     	0x06          //波特率100kbps
#define         ByteRate_125k     	0x07          //波特率125kbps
#define         ByteRate_200k     	0x08          //波特率200kbps
#define         ByteRate_250k     	0x09          //波特率250kbps
#define         ByteRate_400k     	0x0A          //波特率400kbps
#define         ByteRate_500k     	0x0B          //波特率500kbps
#define         ByteRate_666k     	0x0C          //波特率666kbps
#define         ByteRate_800k     	0x0D          //波特率800kbps
#define         ByteRate_1000k    	0x0E          //波特率1000kbps


/*
 ********************************************************************************************************************
 *                        SJA1000OS定义结束
 ********************************************************************************************************************
 */
#endif
