#include "hardware.h"
#include "canfestival.h"
#include "can_AVR.h"
#include "objdict.h"
#include "ds401.h"


unsigned char timer_interrupt = 0;
unsigned char inputs;

// ����
unsigned char nodeID;
unsigned char digital_input[1] = {0};
unsigned char digital_output[1] = {0};

static Message m = Message_Initializer; // �õ�һ��CAN��Ϣ

void sys_init();

// ʱ��
#define sys_timer           timer_interrupt
#define reset_sys_timer()       timer_interrupt = 0
#define CYCLE_TIME              1000        // ��λΪus

int main(void)
{
  sys_init();    // ϵͳ��ʼ��
  canInit(250);  // ���߳�ʼ���Լ�����������
  initTimer();   // ��ʱ����ʼ��
  nodeID = 0x01; // ��ȡNode ID
  setNodeId (&ObjDict_Data, nodeID);
  setState(&ObjDict_Data, Initialisation);  // Э��״̬��ʼ��

  for(;;)  // ������ѭ��
  {
    if (sys_timer)
    {
      reset_sys_timer();    // Reset timer
      digital_input[0] = get_inputs();
      digital_input_handler(&ObjDict_Data, digital_input, sizeof(digital_input));
      digital_output_handler(&ObjDict_Data, digital_output, sizeof(digital_output));
      set_outputs(digital_output[0]);

    if (canReceive(&m))         // �յ���Ϣ
    {
      canDispatch(&ObjDict_Data, &m);       // ������Ϣ
      PORTB = 0x00;                         // ����LED
    DDRB  = 0xFF;
     }
    else
    {
      // ˯��ģʽ
      PORTB = 0x55;
      DDRB  = 0xFF;     
      #ifdef WD_SLEEP       // ���Ź�
      wdt_reset();
      sleep_enable();
      sleep_cpu();
      #endif
    }
  }
}

void sys_init()
/******************************************************************************
Initialize the relays, the main states and the modbus protocol stack.
INPUT   LOCK_STATES *lock_states
OUTPUT  void
******************************************************************************/
{
  //OSCCAL = 0x43;                        // adjust the RC oszillator
  OSCCAL = 0xA6;
  PORTA = 0xFF;                         // Inputs (Keys, low active) with pullup
  DDRA  = 0x00;                     // 
  PORTB = 0xFF;                         // Outputs (LEDs, low active) all 1
  DDRB  = 0xFF;                     // 
  PORTC = 0xFF;                         // 1 BCD switch with pullup
  DDRC  = 0x00;                     // 
  PORTD = 0x2C;                         // 2xCOM, unused, CAN, unused
  DDRD  = 0x2A;                     // All init 0 or without pullup
  PORTE = 0x00;                         // Output
  DDRE  = 0x3C;                     // 2x not used, 2x not used
  PORTF = 0x00;                         // Not used
  DDRF  = 0xFF;                     // All output
  PORTG = 0x00;                         // Not used
  DDRG  = 0x1F;                     // Output for debug (only 5 pins)

// Set timer 0 for main schedule time
  TCCR0A |= 1 << WGM01 | 1 << CS01 | 1 << CS00;// Timer 0 CTC , Timer 0 mit CK/64 starten
  TIMSK0 = 1 << OCIE0A;             // Timer Interrupts: Timer 0 Compare
  OCR0A = (unsigned char)(F_CPU / 64 * CYCLE_TIME/1000000 - 1); // Reloadvalue for timer 0
  #ifdef WD_SLEEP       // Watchdog and Sleep
  wdt_reset();
  wdt_enable(WDTO_15MS);    // Watchdogtimer start with 16 ms timeout
  #endif            // Watchdog and Sleep
  sei();         // Enable Interrupts
}


#ifdef  __IAR_SYSTEMS_ICC__
#pragma type_attribute = __interrupt
#pragma vector=TIMER0_COMP_vect
void TIMER0_COMP_interrupt(void)
#else   // GCC
ISR(TIMER0_COMP_vect)
#endif  // GCC
/******************************************************************************
Interruptserviceroutine Timer 2 Compare A for the main cycle
******************************************************************************/

{
  timer_interrupt = 1;  // Set flag
}
