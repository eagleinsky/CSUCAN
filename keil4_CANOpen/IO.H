//****************************************************************************
// @Module        Parallel Ports
// @Filename      IO.C
// @Project       EBCU_CPU.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XC164CS-16F20
//
// @Compiler      Keil
//
// @Codegenerator 3.0
//
// @Description   This file contains all function prototypes and macros for 
//                the IO module.
//
//----------------------------------------------------------------------------
// @Date          2014/9/3 17:56:08
//
//****************************************************************************

// USER CODE BEGIN (IO_Header,1)

// USER CODE END



#ifndef _IO_H_
#define _IO_H_

//****************************************************************************
// @Project Includes
//****************************************************************************

// USER CODE BEGIN (IO_Header,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (IO_Header,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

//----------------------------------------------------------------------------
// Defines for the parameter PinName
//----------------------------------------------------------------------------

//   
#define IO_P0H_0 P0H_P0

//   
#define IO_P0H_1 P0H_P1

//   
#define CPLD_RST_L P0H_P2

//   
#define WDTIN P0H_P3

//   
#define IO_P0H_4 P0H_P4

//   
#define IO_P0H_5 P0H_P5

//   
#define IO_P0H_6 P0H_P6

//   
#define IO_P0H_7 P0H_P7


//   
#define IO_P0L_0 P0L_P0

//   
#define IO_P0L_1 P0L_P1

//   
#define IO_P0L_2 P0L_P2

//   
#define IO_P0L_3 P0L_P3

//   
#define IO_P0L_4 P0L_P4

//   
#define IO_P0L_5 P0L_P5

//   
#define IO_P0L_6 P0L_P6

//   
#define IO_P0L_7 P0L_P7


//   
#define IO_P1H_0 P1H_P0

//   
#define IO_P1H_1 P1H_P1

//   
#define IO_P1H_2 P1H_P2

//   
#define IO_P1H_3 P1H_P3

//   
#define IO_P1H_4 P1H_P4

//   
#define IO_P1H_5 P1H_P5

//   
#define IO_P1H_6 P1H_P6

//   
#define IO_P1H_7 P1H_P7


//   
#define IO_P1L_0 P1L_P0

//   
#define IO_P1L_1 P1L_P1

//   
#define IO_P1L_2 P1L_P2

//   
#define IO_P1L_3 P1L_P3

//   
#define IO_P1L_4 P1L_P4

//   
#define IO_P1L_5 P1L_P5

//   
#define IO_P1L_6 P1L_P6

//   
#define IO_P1L_7 P1L_P7


//   
#define IO_P3_1 P3_P1

//   
#define IO_P3_2 P3_P2

//   
#define IO_P3_3 P3_P3

//   
#define IO_P3_4 P3_P4

//   
#define IO_P3_5 P3_P5

//   
#define IO_P3_6 P3_P6

//   
#define IO_P3_7 P3_P7

//   
#define IO_P3_8 P3_P8

//   
#define IO_P3_9 P3_P9

//   
#define IO_P3_10 P3_P10

//   
#define IO_P3_11 P3_P11

//   
#define IO_P3_12 P3_P12

//   
#define IO_P3_13 P3_P13

//   
#define IO_P3_15 P3_P15


//   
#define IO_P4_0 P4_P0

//   
#define IO_P4_1 P4_P1

//   
#define IO_P4_2 P4_P2

//   
#define IO_P4_3 P4_P3

//   
#define IO_P4_4 P4_P4

//   
#define IO_P4_5 P4_P5

//   
#define relay_control P4_P6

//   
#define IOCHR0 P4_P7


//   
#define IO_P5_0 P5_P0

//   
#define IO_P5_1 P5_P1

//   
#define IO_P5_2 P5_P2

//   
#define IO_P5_3 P5_P3

//   
#define IO_P5_4 P5_P4

//   
#define IO_P5_5 P5_P5

//   
#define IO_P5_6 P5_P6

//   
#define IO_P5_7 P5_P7

//   
#define IO_P5_10 P5_P10

//   
#define IO_P5_11 P5_P11

//   
#define IO_P5_12 P5_P12

//   
#define IO_P5_13 P5_P13

//   
#define IO_P5_14 P5_P14

//   
#define IO_P5_15 P5_P15


//   
#define IO_P9_0 P9_P0

//   
#define IO_P9_1 P9_P1

//   
#define IO_P9_2 P9_P2

//   
#define IO_P9_3 P9_P3

//   
#define IO_P9_4 P9_P4

//   
#define IO_P9_5 P9_P5


//   
#define IO_P20_0 P20_P0

//   
#define IO_P20_1 P20_P1

//   
#define IO_P20_4 P20_P4

//   
#define IO_P20_5 P20_P5

//   
#define IO_P20_12 P20_P12



//----------------------------------------------------------------------------
// Defines used by DAvE
//----------------------------------------------------------------------------

#define INIO_P0H_0       P0H_P0
#define INIO_P0H_1       P0H_P1
#define INCPLD_RST_L       P0H_P2
#define INWDTIN       P0H_P3
#define INIO_P0H_4       P0H_P4
#define INIO_P0H_5       P0H_P5
#define INIO_P0H_6       P0H_P6
#define INIO_P0H_7       P0H_P7

#define DIO_P0H_0       DP0H_P0
#define DIO_P0H_1       DP0H_P1
#define DCPLD_RST_L       DP0H_P2
#define DWDTIN       DP0H_P3
#define DIO_P0H_4       DP0H_P4
#define DIO_P0H_5       DP0H_P5
#define DIO_P0H_6       DP0H_P6
#define DIO_P0H_7       DP0H_P7

#define INIO_P0L_0       P0L_P0
#define INIO_P0L_1       P0L_P1
#define INIO_P0L_2       P0L_P2
#define INIO_P0L_3       P0L_P3
#define INIO_P0L_4       P0L_P4
#define INIO_P0L_5       P0L_P5
#define INIO_P0L_6       P0L_P6
#define INIO_P0L_7       P0L_P7

#define DIO_P0L_0       DP0L_P0
#define DIO_P0L_1       DP0L_P1
#define DIO_P0L_2       DP0L_P2
#define DIO_P0L_3       DP0L_P3
#define DIO_P0L_4       DP0L_P4
#define DIO_P0L_5       DP0L_P5
#define DIO_P0L_6       DP0L_P6
#define DIO_P0L_7       DP0L_P7

#define INIO_P1H_0       P1H_P0
#define INIO_P1H_1       P1H_P1
#define INIO_P1H_2       P1H_P2
#define INIO_P1H_3       P1H_P3
#define INIO_P1H_4       P1H_P4
#define INIO_P1H_5       P1H_P5
#define INIO_P1H_6       P1H_P6
#define INIO_P1H_7       P1H_P7

#define DIO_P1H_0       DP1H_P0
#define DIO_P1H_1       DP1H_P1
#define DIO_P1H_2       DP1H_P2
#define DIO_P1H_3       DP1H_P3
#define DIO_P1H_4       DP1H_P4
#define DIO_P1H_5       DP1H_P5
#define DIO_P1H_6       DP1H_P6
#define DIO_P1H_7       DP1H_P7

#define INIO_P1L_0       P1L_P0
#define INIO_P1L_1       P1L_P1
#define INIO_P1L_2       P1L_P2
#define INIO_P1L_3       P1L_P3
#define INIO_P1L_4       P1L_P4
#define INIO_P1L_5       P1L_P5
#define INIO_P1L_6       P1L_P6
#define INIO_P1L_7       P1L_P7

#define DIO_P1L_0       DP1L_P0
#define DIO_P1L_1       DP1L_P1
#define DIO_P1L_2       DP1L_P2
#define DIO_P1L_3       DP1L_P3
#define DIO_P1L_4       DP1L_P4
#define DIO_P1L_5       DP1L_P5
#define DIO_P1L_6       DP1L_P6
#define DIO_P1L_7       DP1L_P7

#define INIO_P3_1       P3_P1
#define INIO_P3_2       P3_P2
#define INIO_P3_3       P3_P3
#define INIO_P3_4       P3_P4
#define INIO_P3_5       P3_P5
#define INIO_P3_6       P3_P6
#define INIO_P3_7       P3_P7
#define INIO_P3_8       P3_P8
#define INIO_P3_9       P3_P9
#define INIO_P3_10       P3_P10
#define INIO_P3_11       P3_P11
#define INIO_P3_12       P3_P12
#define INIO_P3_13       P3_P13
#define INIO_P3_15       P3_P15

#define DIO_P3_1       DP3_P1
#define DIO_P3_2       DP3_P2
#define DIO_P3_3       DP3_P3
#define DIO_P3_4       DP3_P4
#define DIO_P3_5       DP3_P5
#define DIO_P3_6       DP3_P6
#define DIO_P3_7       DP3_P7
#define DIO_P3_8       DP3_P8
#define DIO_P3_9       DP3_P9
#define DIO_P3_10       DP3_P10
#define DIO_P3_11       DP3_P11
#define DIO_P3_12       DP3_P12
#define DIO_P3_13       DP3_P13
#define DIO_P3_15       DP3_P15

#define INIO_P4_0       P4_P0
#define INIO_P4_1       P4_P1
#define INIO_P4_2       P4_P2
#define INIO_P4_3       P4_P3
#define INIO_P4_4       P4_P4
#define INIO_P4_5       P4_P5
#define INrelay_control       P4_P6
#define INIOCHR0       P4_P7

#define DIO_P4_0       DP4_P0
#define DIO_P4_1       DP4_P1
#define DIO_P4_2       DP4_P2
#define DIO_P4_3       DP4_P3
#define DIO_P4_4       DP4_P4
#define DIO_P4_5       DP4_P5
#define Drelay_control       DP4_P6
#define DIOCHR0       DP4_P7

#define INIO_P5_0       P5_P0
#define INIO_P5_1       P5_P1
#define INIO_P5_2       P5_P2
#define INIO_P5_3       P5_P3
#define INIO_P5_4       P5_P4
#define INIO_P5_5       P5_P5
#define INIO_P5_6       P5_P6
#define INIO_P5_7       P5_P7
#define INIO_P5_10       P5_P10
#define INIO_P5_11       P5_P11
#define INIO_P5_12       P5_P12
#define INIO_P5_13       P5_P13
#define INIO_P5_14       P5_P14
#define INIO_P5_15       P5_P15


#define INIO_P9_0       P9_P0
#define INIO_P9_1       P9_P1
#define INIO_P9_2       P9_P2
#define INIO_P9_3       P9_P3
#define INIO_P9_4       P9_P4
#define INIO_P9_5       P9_P5

#define DIO_P9_0       DP9_P0
#define DIO_P9_1       DP9_P1
#define DIO_P9_2       DP9_P2
#define DIO_P9_3       DP9_P3
#define DIO_P9_4       DP9_P4
#define DIO_P9_5       DP9_P5

#define INIO_P20_0       P20_P0
#define INIO_P20_1       P20_P1
#define INIO_P20_4       P20_P4
#define INIO_P20_5       P20_P5
#define INIO_P20_12       P20_P12

#define DIO_P20_0       DP20_P0
#define DIO_P20_1       DP20_P1
#define DIO_P20_4       DP20_P4
#define DIO_P20_5       DP20_P5
#define DIO_P20_12       DP20_P12

// USER CODE BEGIN (IO_Header,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (IO_Header,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (IO_Header,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (IO_Header,7)

// USER CODE END


//****************************************************************************
// @Prototypes Of Global Functions
//****************************************************************************

void IO_vInit(void);


// USER CODE BEGIN (IO_Header,8)

// USER CODE END


//****************************************************************************
// @Macro         IO_vSetPin(PinName) 
//
//----------------------------------------------------------------------------
// @Description   This macro sets the chosen portpin to '1'.
//                Note:
//                See the 'Defines for the parameter PinName' section in this 
//                header file for the available definitions for the parameter 
//                PinName.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    PinName: 
//                Pin to be set to '1'
//
//----------------------------------------------------------------------------
// @Date          2014/9/3
//
//****************************************************************************

#define IO_vSetPin(PinName) PinName = 1


//****************************************************************************
// @Macro         IO_vResetPin(PinName) 
//
//----------------------------------------------------------------------------
// @Description   This macro sets the chosen portpin to '0'. 
//                Note: 
//                See the 'Defines for the parameter PinName' section in this 
//                header file for the available definitions for the parameter 
//                PinName.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    PinName: 
//                Pin to be set to '0'
//
//----------------------------------------------------------------------------
// @Date          2014/9/3
//
//****************************************************************************

#define IO_vResetPin(PinName) PinName = 0


//****************************************************************************
// @Macro         IO_vSetPortOut(PortName, uwMask) 
//
//----------------------------------------------------------------------------
// @Description   This macro makes it possible to reconfigure the selected 
//                port. The parameter usMask determines which individual port 
//                pins are to be used as outputs. Every bit position in the 
//                parameter usMask corresponds to a port pin.
//                The following definitions for PortName are available:
//                P0H, P0L, P1H, P1L, P3, P4, P5, P9, P20, 
//                Example:
//                IO_vSetPortOut(P0,0x0204);  // sets P0.9 and P0.2 to output
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    PortName: 
//                Port to be configured
// @Parameters    uwMask: 
//                Mask for port pins to be configured
//
//----------------------------------------------------------------------------
// @Date          2014/9/3
//
//****************************************************************************

#define IO_vSetPortOut(PortName, uwMask) D##PortName |= uwMask


//****************************************************************************
// @Interrupt Vectors
//****************************************************************************

// USER CODE BEGIN (IO_Header,9)

// USER CODE END


#endif  // ifndef _IO_H_
