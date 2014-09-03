//****************************************************************************
// @Module        Capture / Compare Unit 2 (CAPCOM2)
// @Filename      CC2.H
// @Project       EBCU_CPU.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XC164CS-16F20
//
// @Compiler      Keil
//
// @Codegenerator 3.0
//
// @Description   This file contains all function prototypes and macros for 
//                the CC2 module.
//
//----------------------------------------------------------------------------
// @Date          2014/7/1 15:42:51
//
//****************************************************************************

// USER CODE BEGIN (CC2_Header,1)

// USER CODE END



#ifndef _CC2_H_
#define _CC2_H_

//****************************************************************************
// @Project Includes
//****************************************************************************

// USER CODE BEGIN (CC2_Header,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (CC2_Header,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

//   This parameter identifies CAPCOM2 timer 7
#define CC2_TIMER_7 7

//   This parameter identifies CAPCOM2 timer 8
#define CC2_TIMER_8 8

//   This parameter identifies CAPCOM2 channel 16
#define CC2_CC_16 16

//   This parameter identifies CAPCOM2 channel 17
#define CC2_CC_17 17


// USER CODE BEGIN (CC2_Header,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (CC2_Header,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (CC2_Header,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (CC2_Header,7)

// USER CODE END


//****************************************************************************
// @Prototypes Of Global Functions
//****************************************************************************

void CC2_vInit(void);


// USER CODE BEGIN (CC2_Header,8)

// USER CODE END


//****************************************************************************
// @Interrupt Vectors
//****************************************************************************

#define CC2_CC16INT    0x30
#define CC2_CC17INT    0x31


// USER CODE BEGIN (CC2_Header,8)

// USER CODE END


#endif  // ifndef _CC2_H_
