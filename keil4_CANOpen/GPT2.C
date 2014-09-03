//****************************************************************************
// @Module        General Purpose Timer Unit (GPT2)
// @Filename      GPT2.C
// @Project       EBCU_CPU.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XC164CS-16F20
//
// @Compiler      Keil
//
// @Codegenerator 3.0
//
// @Description   This file contains functions that use the GPT2 module.
//
//----------------------------------------------------------------------------
// @Date          2014/9/3 17:56:09
//
//****************************************************************************

// USER CODE BEGIN (GPT2_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.H"

// USER CODE BEGIN (GPT2_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (GPT2_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (GPT2_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (GPT2_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (GPT2_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (GPT2_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (GPT2_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (GPT2_General,9)

// USER CODE END


//****************************************************************************
// @Function      void GPT2_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the initialization function of the GPT2 function 
//                library. It is assumed that the SFRs used by this library 
//                are in its reset state. 
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2014/9/3
//
//****************************************************************************

// USER CODE BEGIN (Init,1)

// USER CODE END

void GPT2_vInit(void)
{
  // USER CODE BEGIN (Init,2)

  // USER CODE END

  ///  -----------------------------------------------------------------------
  ///  Configuration of Timer Block Prescaler 2:
  ///  -----------------------------------------------------------------------
  ///  - prescaler for timer block 2 is 4


  ///  -----------------------------------------------------------------------
  ///  Configuration of the GPT2 Core Timer 5:
  ///  -----------------------------------------------------------------------
  ///  - timer 5 works in timer mode
  ///  - prescaler factor is 32
  ///  - up/down control bit is reset
  ///  - external up/down control is disabled
  ///  - timer 5 remote control is disabled

  GPT12E_T5CON   =  0x0003;      // load timer 5 control register
  GPT12E_T5      =  0xE796;      // load timer 5 register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the GPT2 Core Timer 6:
  ///  -----------------------------------------------------------------------
  ///  - timer 6 works in timer mode
  ///  - prescaler factor is 4
  ///  - up/down control bit is reset
  ///  - external up/down control is disabled
  ///  - alternate output function T6OUT (P3.1) is disabled
  ///  - timer 6 output toggle latch (T6OTL) is set to 0
  ///  - timer 6 run bit is reset
  ///  - timer 6 is not cleared on a capture

  GPT12E_T6CON   =  0x0000;      // load timer 6 control register
  GPT12E_T6      =  0x0000;      // load timer 6 register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the GPT2 CAPREL:
  ///  -----------------------------------------------------------------------
  ///  - capture T5 into CAPREL is disabled
  ///  - capture trigger from pin CAPIN
  ///  - capure is disabled
  ///  - timer 5 is not cleared on a capture
  ///  - timer 5 is just captured without any correction

  GPT12E_T5CON  |=  0x0000;      // load timer 5 control register
  GPT12E_CAPREL  =  0x0000;      // load CAPREL register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used GPT2 Port Pins:
  ///  -----------------------------------------------------------------------


  ///  -----------------------------------------------------------------------
  ///  Configuration of the used GPT2 Interrupts:
  ///  -----------------------------------------------------------------------
  ///  timer 5 service request node configuration:
  ///  - timer 5 interrupt priority level (ILVL) = 5
  ///  - timer 5 interrupt group level (GLVL) = 0
  ///  - timer 5 group priority extension (GPX) = 0

  GPT12E_T5IC    =  0x0054;     


  // USER CODE BEGIN (GPT2_Function,3)

  // USER CODE END

  GPT12E_T5CON_T5R  =  1;        // set timer 5 run bit

} //  End of function GPT2_vInit

//****************************************************************************
// @Function      void GPT2_viTmr5(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine for the GPT2 timer 5. 
//                It is called up in the case of over or underflow of the 
//                timer 5 register.
//                
//                Please note that you have to add application specific code 
//                to this function.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          2014/9/3
//
//****************************************************************************

// USER CODE BEGIN (Tmr5,1)

// USER CODE END

void GPT2_viTmr5(void) interrupt T5INT using RB_LEVEL5
{
  // USER CODE BEGIN (Tmr5,2)
	GPT12E_T3 = 0xE796;   
  TFlag = 1;

  // USER CODE END

} //  End of function GPT2_viTmr5




// USER CODE BEGIN (GPT2_General,10)

// USER CODE END

