//****************************************************************************
// @Module        Capture / Compare Unit 2 (CAPCOM2)
// @Filename      CC2.C
// @Project       EBCU_CPU.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XC164CS-16F20
//
// @Compiler      Keil
//
// @Codegenerator 3.0
//
// @Description   This file contains functions that use the CC2 module.
//
//----------------------------------------------------------------------------
// @Date          2014/9/3 17:56:09
//
//****************************************************************************

// USER CODE BEGIN (CC2_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.H"

// USER CODE BEGIN (CC2_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (CC2_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (CC2_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (CC2_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (CC2_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (CC2_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (CC2_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (CC2_General,9)

// USER CODE END


//****************************************************************************
// @Function      void CC2_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the initialization function of the CAPCOM2 function 
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

void CC2_vInit(void)
{
  // USER CODE BEGIN (Init,2)

  // USER CODE END

  ///  -----------------------------------------------------------------------
  ///  Configuration of CAPCOM2 Control:
  ///  -----------------------------------------------------------------------
  ///  - the contents of the port register is changed by the CAPCOM2 unit
  ///  - staggered mode is enabled

  CC2_IOC        =  0x0000;      // load CAPCOM2 I/O control register

  ///  -----------------------------------------------------------------------
  ///  Configuration of CAPCOM2 Timer 7:
  ///  -----------------------------------------------------------------------
  ///  - timer 7 works in timer mode
  ///  - prescaler factor is 8
  ///  - timer 7 run bit is reset

  ///  -----------------------------------------------------------------------
  ///  Configuration of CAPCOM2 Timer 8:
  ///  -----------------------------------------------------------------------
  ///  - timer 8 works in timer mode
  ///  - prescaler factor is 8
  ///  - timer 8 run bit is reset


  CC2_T78CON     =  0x0000;      // load CAPCOM2 timer 7 and timer 8 control 
                                 // register

  CC2_T7         =  0x0000;      // load CAPCOM2 timer 7 register

  CC2_T7REL      =  0x0000;      // load CAPCOM2 timer 7 reload register

  CC2_T8         =  0x0000;      // load CAPCOM2 timer 8 register

  CC2_T8REL      =  0x0000;      // load CAPCOM2 timer 8 reload register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Timer Port Pins:
  ///  -----------------------------------------------------------------------


  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Timer Interrupts:
  ///  -----------------------------------------------------------------------


  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 16:
  ///  -----------------------------------------------------------------------
  ///  - capture on positive transition (falling edge) at pin CC16IO (P9.0)
  ///  - CC16 allocated to CAPCOM2 timer 7
  ///  - single event mode is enabled
  ///  - single event is disabled


  CC2_CC16       =  0x0000;      // load CAPCOM2 channel 16 register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 17:
  ///  -----------------------------------------------------------------------
  ///  - capture on positive transition (falling edge) at pin CC17IO (P9.1)
  ///  - CC17 allocated to CAPCOM2 timer 7
  ///  - single event mode is enabled
  ///  - single event is enabled


  CC2_CC17       =  0x0000;      // load CAPCOM2 channel 17 register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 18:
  ///  -----------------------------------------------------------------------
  ///  - channel 18 is disabled

  CC2_CC18       =  0x0000;      // load CAPCOM2 channel 18 register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 19:
  ///  -----------------------------------------------------------------------
  ///  - channel 19 is disabled

  CC2_CC19       =  0x0000;      // load CAPCOM2 channel 19 register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 20:
  ///  -----------------------------------------------------------------------
  ///  - channel 20 is disabled

  CC2_CC20       =  0x0000;      // load CAPCOM2 channel 20 register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 21:
  ///  -----------------------------------------------------------------------
  ///  - channel 21 is disabled

  CC2_CC21       =  0x0000;      // load CAPCOM2 channel 21 register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 22:
  ///  -----------------------------------------------------------------------
  ///  - channel 22 is disabled

  CC2_CC22       =  0x0000;      // load CAPCOM2 channel 22 register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 23:
  ///  -----------------------------------------------------------------------
  ///  - channel 23 is disabled

  CC2_CC23       =  0x0000;      // load CAPCOM2 channel 23 register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 24:
  ///  -----------------------------------------------------------------------
  ///  - channel 24 is disabled

  CC2_CC24       =  0x0000;      // load CAPCOM2 channel 24 register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 25:
  ///  -----------------------------------------------------------------------
  ///  - channel 25 is disabled

  CC2_CC25       =  0x0000;      // load CAPCOM2 channel 25 register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 26:
  ///  -----------------------------------------------------------------------
  ///  - channel 26 is disabled

  CC2_CC26       =  0x0000;      // load CAPCOM2 channel 26 register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 27:
  ///  -----------------------------------------------------------------------
  ///  - channel 27 is disabled

  CC2_CC27       =  0x0000;      // load CAPCOM2 channel 27 register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 28:
  ///  -----------------------------------------------------------------------
  ///  - channel 28 is disabled

  CC2_CC28       =  0x0000;      // load CAPCOM2 channel 28 register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 29:
  ///  -----------------------------------------------------------------------
  ///  - channel 29 is disabled

  CC2_CC29       =  0x0000;      // load CAPCOM2 channel 29 register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 30:
  ///  -----------------------------------------------------------------------
  ///  - channel 30 is disabled

  CC2_CC30       =  0x0000;      // load CAPCOM2 channel 30 register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel 31:
  ///  -----------------------------------------------------------------------
  ///  - channel 31 is disabled

  CC2_CC31       =  0x0000;      // load CAPCOM2 channel 31 register

  CC2_M4         =  0x0022;      // load CAPCOM2 mode register 4
  CC2_M5         =  0x0000;      // load CAPCOM2 mode register 5
  CC2_M6         =  0x0000;      // load CAPCOM2 mode register 6
  CC2_M7         =  0x0000;      // load CAPCOM2 mode register 7

  CC2_DRM        =  0x0000;      // load CAPCOM2 double-register mode register

  CC2_SEM        =  0x0003;      // load CAPCOM2 single event mode register

  CC2_SEE        =  0x0002;      // load CAPCOM2 single event enable register

  CC2_OUT        =  0x0000;      // load CAPCOM2 compare output register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channel Port Pins:
  ///  -----------------------------------------------------------------------
  ///  - P9.0 is used for CAPCOM2 Input (CC16IO)
  ///  - P9.1 is used for CAPCOM2 Input (CC17IO)


  ///  -----------------------------------------------------------------------
  ///  Configuration of the used CAPCOM2 Channels Interrupts:
  ///  -----------------------------------------------------------------------
  ///  CC16 service request node configuration:
  ///  - CC16 interrupt priority level (ILVL) = 7
  ///  - CC16 interrupt group level (GLVL) = 0
  ///  - CC16 group priority extension (GPX) = 0

  CC2_CC16IC     =  0x005C;     


  ///  CC17 service request node configuration:
  ///  - CC17 interrupt priority level (ILVL) = 8
  ///  - CC17 interrupt group level (GLVL) = 0
  ///  - CC17 group priority extension (GPX) = 0

  CC2_CC17IC     =  0x0060;     



  // USER CODE BEGIN (Init,3)

  // USER CODE END

} //  End of function CC2_vInit


//****************************************************************************
// @Function      void CC2_viCC16(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine for the CAPCOM2 
//                register CC16. If the content of the corresponding compare 
//                timer (configurable) equals the content of the 
//                capture/compare register CC16 or if a capture event occurs 
//                at the associated port pin, the interrupt request flag is 
//                set and an interrupt is triggered (only if enabled).
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

// USER CODE BEGIN (CC16,1)

// USER CODE END

void CC2_viCC16(void) interrupt CC2_CC16INT using RB_LEVEL7
{
  // USER CODE BEGIN (CC16,2)
	can1_recv_flag=1;
  // USER CODE END

} //  End of function CC2_viCC16


//****************************************************************************
// @Function      void CC2_viCC17(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine for the CAPCOM2 
//                register CC17. If the content of the corresponding compare 
//                timer (configurable) equals the content of the 
//                capture/compare register CC17 or if a capture event occurs 
//                at the associated port pin, the interrupt request flag is 
//                set and an interrupt is triggered (only if enabled).
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

// USER CODE BEGIN (CC17,1)

// USER CODE END

void CC2_viCC17(void) interrupt CC2_CC17INT using RB_LEVEL8
{
  // USER CODE BEGIN (CC17,2)
  can2_recv_flag=1;	
  // USER CODE END

} //  End of function CC2_viCC17




// USER CODE BEGIN (CC2_General,10)

// USER CODE END

