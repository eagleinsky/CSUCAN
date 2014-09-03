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
// @Description   This file contains functions that use the IO module.
//
//----------------------------------------------------------------------------
// @Date          2014/9/3 17:56:08
//
//****************************************************************************

// USER CODE BEGIN (IO_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.H"

// USER CODE BEGIN (IO_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (IO_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (IO_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (IO_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (IO_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (IO_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (IO_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (IO_General,9)

// USER CODE END


//****************************************************************************
// @Function      void IO_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the initialization function of the IO function 
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

// USER CODE BEGIN (IO_Function,1)

// USER CODE END

void IO_vInit(void)
{
  // USER CODE BEGIN (IO_Function,2)

  // USER CODE END

  ///  -----------------------------------------------------------------------
  ///  General Port Settings:
  ///  -----------------------------------------------------------------------
  PICON          =  0x0000;      // load input configuration register

  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P0H:
  ///  -----------------------------------------------------------------------
  ///  P0H.3 is used as general purpose output
  ///  - the pin status is low level
  ///  P0H.4 is used as general purpose output
  ///  - the pin status is low level

  ///  P0H.0 - P0H.3 output driver characteristic: strong driver
  ///  P0H.4 - P0H.7 output driver characteristic: strong driver

  ///  P0H.0 - P0H.3 output edge characteristic: sharp edge mode
  ///  P0H.4 - P0H.7 output edge characteristic: sharp edge mode

  P0H            =  0x0000;      // load data register
  POCON0H        =  0x0000;      // load output control register
  DP0H           =  0x0018;      // load direction register

  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P0L:
  ///  -----------------------------------------------------------------------
  ///  P0L.0 is used as alternate output for the Port Pin (AD0)
  ///  P0L.1 is used as alternate output for the Port Pin (AD1)
  ///  P0L.2 is used as alternate output for the Port Pin (AD2)
  ///  P0L.3 is used as alternate output for the Port Pin (AD3)
  ///  P0L.4 is used as alternate output for the Port Pin (AD4)
  ///  P0L.5 is used as alternate output for the Port Pin (AD5)
  ///  P0L.6 is used as alternate output for the Port Pin (AD6)
  ///  P0L.7 is used as alternate output for the Port Pin (AD7)

  ///  P0L.0 - P0L.3 output driver characteristic: strong driver
  ///  P0L.4 - P0L.7 output driver characteristic: strong driver

  ///  P0L.0 - P0L.3 output edge characteristic: sharp edge mode
  ///  P0L.4 - P0L.7 output edge characteristic: sharp edge mode

  P0L            =  0x0000;      // load data register
  POCON0L        =  0x0000;      // load output control register
  DP0L           =  0x0000;      // load direction register

  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P1H:
  ///  -----------------------------------------------------------------------
  ///  P1H.0 is used as alternate output for the Port Pin (A8)
  ///  P1H.1 is used as alternate output for the Port Pin (A9)
  ///  P1H.2 is used as alternate output for the Port Pin (A10)
  ///  P1H.3 is used as alternate output for the Port Pin (A11)
  ///  P1H.4 is used as alternate output for the Port Pin (A12)
  ///  P1H.5 is used as alternate output for the Port Pin (A13)
  ///  P1H.6 is used as alternate output for the Port Pin (A14)
  ///  P1H.7 is used as alternate output for the Port Pin (A15)

  ///  P1H.0 - P1H.3 output driver characteristic: strong driver
  ///  P1H.4 - P1H.7 output driver characteristic: strong driver

  ///  P1H.0 - P1H.3 output edge characteristic: sharp edge mode
  ///  P1H.4 - P1H.7 output edge characteristic: sharp edge mode

  P1H            =  0x0000;      // load data register
  ALTSEL0P1H     =  0x0000;      // load alternate output function select 
                                 // register 0
  POCON1H        =  0x0000;      // load output control register
  DP1H           =  0x0000;      // load direction register

  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P1L:
  ///  -----------------------------------------------------------------------
  ///  P1L.0 is used as alternate output for the Port Pin (A0)
  ///  P1L.1 is used as alternate output for the Port Pin (A1)
  ///  P1L.1 is used as alternate output for the Port Pin (A1)
  ///  P1L.2 is used as alternate output for the Port Pin (A2)
  ///  P1L.3 is used as alternate output for the Port Pin (A3)
  ///  P1L.4 is used as alternate output for the Port Pin (A4)
  ///  P1L.5 is used as alternate output for the Port Pin (A5)
  ///  P1L.6 is used as alternate output for the Port Pin (A6)
  ///  P1L.7 is used as alternate output for the Port Pin (A7)

  ///  P1L.0 - P1L.3 output driver characteristic: strong driver
  ///  P1L.4 - P1L.7 output driver characteristic: strong driver

  ///  P1L.0 - P1L.3 output edge characteristic: sharp edge mode
  ///  P1L.4 - P1L.7 output edge characteristic: sharp edge mode

  P1L            =  0x0000;      // load data register
  ALTSEL0P1L     =  0x0000;      // load alternate output function select 
                                 // register 0
  POCON1L        =  0x0000;      // load output control register
  DP1L           =  0x0000;      // load direction register

  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P3:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P3 is used

  ODP3           =  0x0000;      // load open-drain register
  P3             =  0x0000;      // load data register
  ALTSEL0P3      =  0x0000;      // load alternate output function select 
                                 // register 0
  ALTSEL1P3      =  0x0000;      // load alternate output function select 
                                 // register 1
  POCON3         =  0x0000;      // load output control register
  DP3            =  0x0000;      // load direction register

  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P4:
  ///  -----------------------------------------------------------------------
  ///  P4.0 is used as alternate input for the Port Pin (A16)
  ///  P4.1 is used as alternate input for the Port Pin (A17)
  ///  P4.2 is used as alternate input for the Port Pin (A18)
  ///  P4.3 is used as alternate input for the Port Pin (A19)
  ///  P4.6 is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  P4.7 is used as general input

  ///  P4.0 - P4.7 threshold type: TTL input

  ///  P4.0 - P4.3 output driver characteristic: strong driver
  ///  P4.4 - P4.7 output driver characteristic: strong driver

  ///  P4.0 - P4.3 output edge characteristic: sharp edge mode
  ///  P4.4 - P4.7 output edge characteristic: sharp edge mode

  ODP4           =  0x0000;      // load open-drain register
  P4             =  0x0000;      // load data register
  ALTSEL0P4      =  0x0000;      // load alternate output function select 
                                 // register 0
  ALTSEL1P4      =  0x0000;      // load alternate output function select 
                                 // register 1
  POCON4         =  0x0000;      // load output control register
  DP4            =  0x0040;      // load direction register

  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P5:
  ///  -----------------------------------------------------------------------
  ///  P5.0 is used as general input
  ///  P5.1 is used as general input
  ///  P5.2 is used as general input
  ///  P5.3 is used as general input
  ///  P5.4 is used as general input


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P9:
  ///  -----------------------------------------------------------------------
  ///  P9.0 is used as alternate input for the CAPCOM2 Input (CC16IO)
  ///  P9.1 is used as alternate input for the CAPCOM2 Input (CC17IO)

  ///  P9.0 - P9.7 threshold type: TTL input

  ///  P9.0 - P9.3 output driver characteristic: strong driver
  ///  P9.4 - P9.7 output driver characteristic: strong driver

  ///  P9.0 - P9.3 output edge characteristic: sharp edge mode
  ///  P9.4 - P9.7 output edge characteristic: sharp edge mode

  ODP9           =  0x0000;      // load open-drain register
  P9             =  0x0000;      // load data register
  ALTSEL0P9      =  0x0000;      // load alternate output function select 
                                 // register 0
  ALTSEL1P9      =  0x0000;      // load alternate output function select 
                                 // register 1
  POCON9         =  0x0000;      // load output control register
  DP9            =  0x0000;      // load direction register

  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P20:
  ///  -----------------------------------------------------------------------
  ///  P20.12 is used as general purpose output
  ///  - the pin status is low level

  ///  P20.0 - P20.7 threshold type: TTL input
  ///  P20.8 - P20.15 threshold type: TTL input

  ///  P20.0 - P20.3 output driver characteristic: strong driver
  ///  P20.4 - P20.7 output driver characteristic: strong driver
  ///  P20.12 - P20.15 output driver characteristic: strong driver

  ///  P20.0 - P20.3 output edge characteristic: sharp edge mode
  ///  P20.4 - P20.7 output edge characteristic: sharp edge mode
  ///  P20.12 - P20.15 output edge characteristic: sharp edge mode

  P20            =  0x0000;      // load data register
  POCON20        =  0x0000;      // load output control register
  DP20           =  0x1000;      // load direction register


  // USER CODE BEGIN (IO_Function,3)

  // USER CODE END

} //  End of function IO_vInit




// USER CODE BEGIN (IO_General,10)

// USER CODE END

