//****************************************************************************
// @Module        Project Settings
// @Filename      MAIN.C
// @Project       EBCU_CPU.dav
//----------------------------------------------------------------------------
// @Controller    Infineon XC164CS-16F20
//
// @Compiler      Keil
//
// @Codegenerator 3.0
//
// @Description   This file contains the project initialization function.
//
//----------------------------------------------------------------------------
// @Date          2014/9/3 17:56:08
//
//****************************************************************************

// USER CODE BEGIN (MAIN_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.H"

// USER CODE BEGIN (MAIN_General,2)
#include "canfestival.h"

#include "ObjDict.h"
#include "ds401.h"

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (MAIN_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (MAIN_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (MAIN_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (MAIN_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (MAIN_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (MAIN_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (MAIN_General,9)

// USER CODE END


//****************************************************************************
// @Function      void MAIN_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This function initializes the microcontroller.
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

void MAIN_vInit(void)
{
  // USER CODE BEGIN (Init,2)

  // USER CODE END

  ///  -----------------------------------------------------------------------
  ///  Configuration of the System Clock:
  ///  -----------------------------------------------------------------------
  ///  - VCO clock used, input clock is connected
  ///  - input frequency is 8 MHz
  ///  - VCO output frequency 100 .. 150 MHz
  ///  - system clock is 20 MHz

  MAIN_vUnlockProtecReg();       // unlock write security
  PLLCON         =  0x7814;      // load PLL control register


  //// -----------------------------------------------------------------------
  //// Begin of Important Settings for the Start-Up File
  //// -----------------------------------------------------------------------
  ///  All following settings must be set in the start-up file. You can use 
  ///  DAvE's project file (*.dpt) to include this register values into your 
  ///  compiler EDE.

    ///  ---------------------------------------------------------------------
    ///  Initialization of the CPUCON1 Register:
    ///  ---------------------------------------------------------------------
    ///  - space between two vectors is 2 words
    ///  - DISWDT executable until End of Init
    ///  - segmentation is enabled
    ///  - switch context is interruptible
    ///  - branch prediction is enabled
    ///  - zero cycle jump function is enabled

    //// this register must be set in the start-up file
    //// CPUCON1  =  0x0007

    ///  ---------------------------------------------------------------------
    ///  Initialization of the VECSEG Register:
    ///  ---------------------------------------------------------------------
    ///  - start from internal program memory

    //// this register must be set in the start-up file
    //// VECSEG  =  0x00C0

    ///  ---------------------------------------------------------------------
    ///  Initialization of the SYSCON0 Register:
    ///  ---------------------------------------------------------------------

    //// this register must be set in the start-up file
    //// SYSCON0  =  0x0000

    ///  ---------------------------------------------------------------------
    ///  Initialization of the SYSCON1 Register:
    ///  ---------------------------------------------------------------------
    ///  clock prescaler for system is fpll / 1

    //// this register must be set in the start-up file
    //// SYSCON1  =  0x0000

    ///  ---------------------------------------------------------------------
    ///  Initialization of the SYSCON3 Register:
    ///  ---------------------------------------------------------------------

    //// this register must be set in the start-up file
    //// SYSCON3  =  0x0000

    ///  ---------------------------------------------------------------------
    ///  Initialization of EBC
    ///  ---------------------------------------------------------------------

    //// this register must be set in the start-up file
    //// EBCMOD1  =  0x0040

    ///  EBC is enabled
    ///  pin #BHE is disabled
    ///  pin ALE is disabled
    ///  as segment address are 4 pins enabled ( A[19] .. A[16] )
    ///  no chip select pin enabled
    ///  pin #READY is disabled
    ///  bus arbitration is disabled, P6.7 .. P6.5 may used for general 
    ///  purpose IO

    //// this register must be set in the start-up file
    //// EBCMOD0  =  0x7004

    ///  ---------------------------------------------------------------------
    ///  ---------- chip select 0 is enabled ----------
    ///  ---------------------------------------------------------------------
    ///  - 8-bit Demultiplexed Bus
    ///  access time is controlled by bitfield PHE0

    //// this register must be set in the start-up file
    //// FCONCS0  =  0x0001

    ///  Phase A: 3 clock cycles
    ///  Phase B: 2 clock cycles
    ///  Phase C: 1 clock cycles
    ///  Phase D: 1 clock cycles
    ///  Phase E: 15 clock cycles
    ///  Read Phase F: 1 clock cycles
    ///  Write Phase F: 3 clock cycles

    //// this register must be set in the start-up file
    //// TCONCS0  =  0x6BAF

    ///  ---------------------------------------------------------------------
    ///  ---------- chip select 1 is disabled ----------
    ///  ---------------------------------------------------------------------


    ///  ---------------------------------------------------------------------
    ///  ---------- chip select 2 is disabled ----------
    ///  ---------------------------------------------------------------------


    ///  ---------------------------------------------------------------------
    ///  ---------- chip select 3 is disabled ----------
    ///  ---------------------------------------------------------------------


  //// -----------------------------------------------------------------------
  //// End of Important Settings for the Start-Up File
  //// -----------------------------------------------------------------------


  //   -----------------------------------------------------------------------
  //   Initialization of the Peripherals:
  //   -----------------------------------------------------------------------

  //   initializes the Parallel Ports
  IO_vInit();

  //   initializes the General Purpose Timer Unit (GPT1)
  GPT1_vInit();

  //   initializes the General Purpose Timer Unit (GPT2)
  GPT2_vInit();

  //   initializes the Capture / Compare Unit 2 (CAPCOM2)
  CC2_vInit();

  // USER CODE BEGIN (Init,3)

  // USER CODE END

  //   globally enable interrupts
  PSW_IEN        =  1;          

} //  End of function MAIN_vInit


//****************************************************************************
// @Function      void MAIN_vUnlockProtecReg(void) 
//
//----------------------------------------------------------------------------
// @Description   This function makes it possible to write one protected 
//                register. After calling of this function and write on the 
//                protected register is the security level set to low 
//                protected mode.
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

// USER CODE BEGIN (UnlockProtecReg,1)

// USER CODE END

void MAIN_vUnlockProtecReg(void)
{
  uword uwPASSWORD;

  if((SCUSLS & 0x1800) == 0x0800)      // if low protected mode
  {

    uwPASSWORD = SCUSLS & 0x00FF;
    uwPASSWORD = (~uwPASSWORD) & 0x00FF;
    SCUSLC = 0x8E00 | uwPASSWORD;      // command 4

  }  // end if low protected mode

  if((SCUSLS & 0x1800) == 0x1800)      // if write protected mode
  {
    SCUSLC = 0xAAAA;                   // command 0
    SCUSLC = 0x5554;                   // command 1

    uwPASSWORD = SCUSLS & 0x00FF;
    uwPASSWORD = (~uwPASSWORD) & 0x00FF;

    SCUSLC = 0x9600 | uwPASSWORD;      // command 2
    SCUSLC = 0x0800;                   // command 3; new PASSWOR is 0x00

    uwPASSWORD = SCUSLS & 0x00FF;
    uwPASSWORD = (~uwPASSWORD) & 0x00FF;
    SCUSLC = 0x8E00 | uwPASSWORD;      // command 4

  }  // end if write protected mode

} //  End of function MAIN_vUnlockProtecReg


//****************************************************************************
// @Function      void main(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the main function.
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

// USER CODE BEGIN (Main,1)
	unsigned char mvb_buf_so1[32] = {0},mvb_buf_so2[32] = {0},mvb_buf_si[32] = {0},mvb_buf_si2[32] = {0};
// USER CODE END

void main(void)
{
  // USER CODE BEGIN (Main,2)
  SJAConfigStruct Chip1_cfg = {1,4,0,0x1,0xffffffff};
  Message Sendm={0x200,0,1,0xaa};
  Message Rcvm ={0x000,0,1,0xaa};
  char i=0;
	unsigned char digital_input[1] = {0};
  // USER CODE END

  MAIN_vInit();

  // USER CODE BEGIN (Main,4)
	
	SJA1000_Config(Chip1_cfg);

	//setState(&ObjDict_Data, Operational);  // ???????

	while(1)
	{
		if(TFlag)
		{
			TFlag=0;
	    i++;
			
			//Rcvm.data[0] = i;
			//canSend(1,&Sendm);		
			
			//digital_input[0] = i;
			//digital_input_handler(&ObjDict_Data, digital_input, sizeof(digital_input));
			
			proceedPDO(&ObjDict_Data,&Rcvm);
		}
  if(can1_recv_flag)
		{
      can1_recv_flag = 0;
			if(!canReceive(1,&Rcvm)) //接受成功
			{
			 Sendm = Rcvm;
			 delay(10);
			 canSend(1,&Sendm);		
			}
		}
	 
	}

  // USER CODE END

} //  End of function main



// USER CODE BEGIN (MAIN_General,10)

// USER CODE END

