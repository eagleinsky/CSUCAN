//****************************************************************************
// @Module        General Purpose Timer Unit (GPT1)
// @Filename      GPT1.C
// @Project       EBCU_CPU.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XC164CS-16F20
//
// @Compiler      Keil
//
// @Codegenerator 3.0
//
// @Description   This file contains functions that use the GPT1 module.
//
//----------------------------------------------------------------------------
// @Date          2014/7/1 15:42:50
//
//****************************************************************************

// USER CODE BEGIN (GPT1_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.H"

// USER CODE BEGIN (GPT1_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (GPT1_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (GPT1_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (GPT1_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (GPT1_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (GPT1_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (GPT1_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (GPT1_General,9)

// USER CODE END


//****************************************************************************
// @Function      void GPT1_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the initialization function of the GPT1 function 
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
// @Date          2014/7/1
//
//****************************************************************************

// USER CODE BEGIN (Init,1)

// USER CODE END

void GPT1_vInit(void)
{
  // USER CODE BEGIN (Init,2)

  // USER CODE END

  ///  -----------------------------------------------------------------------
  ///  Configuration of Timer Block Prescaler 1:
  ///  -----------------------------------------------------------------------
  ///  - prescaler for timer block 1 is 32


  ///  -----------------------------------------------------------------------
  ///  Configuration of the GPT1 Core Timer 3:
  ///  -----------------------------------------------------------------------
  ///  - timer 3 works in timer mode
  ///  - external up/down control is disabled
  ///  - prescaler factor is 32
  ///  - up/down control bit is reset
  ///  - alternate output function T3OUT (P3.3) is disabled
  ///  - timer 3 output toggle latch (T3OTL) is set to 0

  GPT12E_T3CON   =  0x1000;      // load timer 3 control register
  GPT12E_T3      =  0xE796;      // load timer 3 register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the GPT1 Auxiliary Timer 2:
  ///  -----------------------------------------------------------------------
  ///  - timer 2 works in timer mode
  ///  - external up/down control is disabled
  ///  - prescaler factor is 32
  ///  - up/down control bit is reset

  GPT12E_T2CON   =  0x0000;      // load timer 2 control register
  GPT12E_T2      =  0xFD8F;      // load timer 2 register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the GPT1 Auxiliary Timer 4:
  ///  -----------------------------------------------------------------------
  ///  - timer 4 works in timer mode
  ///  - external up/down control is disabled
  ///  - prescaler factor is 32
  ///  - up/down control bit is reset
  ///  - timer 4 run bit is reset

  GPT12E_T4CON   =  0x0000;      // load timer 4 control register
  GPT12E_T4      =  0x0000;      // load timer 4 register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used GPT1 Port Pins:
  ///  -----------------------------------------------------------------------


  ///  -----------------------------------------------------------------------
  ///  Configuration of the used GPT1 Interrupts:
  ///  -----------------------------------------------------------------------
  ///  timer 2 service request node configuration:
  ///  - timer 2 interrupt priority level (ILVL) = 14
  ///  - timer 2 interrupt group level (GLVL) = 0
  ///  - timer 2 group priority extension (GPX) = 0

  GPT12E_T2IC    =  0x0078;     

  ///  Use PEC channel 0 for GPT1 T2 INT:
  ///  - normal interrupt
  ///  - pointers are not modified
  ///  - transfer a word
  ///  - service End of PEC interrrupt by a EOP interrupt node is disabled
  ///  - channel link mode is disabled

  PECC0          =  0x0000;      // load PECC0 control register


  ///  timer 3 service request node configuration:
  ///  - timer 3 interrupt priority level (ILVL) = 13
  ///  - timer 3 interrupt group level (GLVL) = 0
  ///  - timer 3 group priority extension (GPX) = 0

  GPT12E_T3IC    =  0x0074;     


  // USER CODE BEGIN (GPT1_Function,3)

  // USER CODE END

  GPT12E_T2CON_T2R  =  1;        // set timer 2 run bit

  GPT12E_T3CON_T3R  =  1;        // set timer 3 run bit

} //  End of function GPT1_vInit


//****************************************************************************
// @Function      void GPT1_viTmr3(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine for the GPT1 timer 3. 
//                It is called up in the case of over or underflow of the 
//                timer 3 register.
//                If the incremental interface mode is selected it is called 
//                up if count edge or count direction was detected.
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
// @Date          2014/7/1
//
//****************************************************************************

// USER CODE BEGIN (Tmr3,1)

// USER CODE END

void GPT1_viTmr3(void) interrupt T3INT using RB_LEVEL13
{
  // USER CODE BEGIN (Tmr3,2)

  // USER CODE END


  // USER CODE BEGIN (Tmr3,5)  
	 GPT12E_T3      =  0xE796;   
  TFlag = 1;

  // USER CODE END

} //  End of function GPT1_viTmr3


//****************************************************************************
// @Function      void GPT1_viTmr2(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine for the GPT1 timer 2. 
//                It is called up in the case of over or underflow of the 
//                timer 2 register.
//                If the incremental interface mode is selected and the 
//                interrupt for this mode is not disabled it is called up if 
//                count edge or count direction was detected.
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
// @Date          2014/7/1
//
//****************************************************************************

// USER CODE BEGIN (Tmr2,1)

// USER CODE END

void GPT1_viTmr2(void) interrupt T2INT using RB_LEVEL14
{
  // USER CODE BEGIN (Tmr2,2)

  // USER CODE END


  // USER CODE BEGIN (Tmr2,5)
    	GPT1_vStopTmr(GPT1_TIMER_2);
	//	GPT1_vStopTmr_GPT1_TIMER_2();
	 GPT12E_T2  =  0xFD8F;   
	TimerMsFlag = 1;
  // USER CODE END

} //  End of function GPT1_viTmr2




// USER CODE BEGIN (GPT1_General,10)

// USER CODE END
