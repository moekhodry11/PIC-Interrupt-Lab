unsigned short kp;
char key;
char password[20];
char My_pass[4] = {'1','2','3','4'};
int count =0, flag = 1,i=0;

// Keypad module connections
char  keypadPort at PORTD;

// LCD module connections
sbit LCD_RS at RC4_bit;
sbit LCD_EN at RC5_bit;
sbit LCD_D4 at RC0_bit;
sbit LCD_D5 at RC1_bit;
sbit LCD_D6 at RC2_bit;
sbit LCD_D7 at RC3_bit;

sbit LCD_RS_Direction at TRISC4_bit;
sbit LCD_EN_Direction at TRISC5_bit;
sbit LCD_D4_Direction at TRISC0_bit;
sbit LCD_D5_Direction at TRISC1_bit;
sbit LCD_D6_Direction at TRISC2_bit;
sbit LCD_D7_Direction at TRISC3_bit;

//Motor
sbit Motor_Pin at RB7_bit;
sbit Motor_Direction at TRISB7_bit;


// LED pin
sbit LED_Pin at RB6_bit;
sbit LED_Direction at TRISB6_bit;

 //timer
  int time,counter=0;



void initialize_timer_Interrupt(void){
    TMR0IE_bit=1;       // Enable timer 0 interrupt
    GIE_bit=1;          //Enable Global Interrupt
    T0CS_bit=0;                  // Select f/4 clock for the TMR0
    PSA_bit=0;                 // Prescaler is assigned to the Timer0 module
    PS0_bit=0;                // Set pre-scaler to 32
    PS1_bit=1;                // PS2,PS1,PS0 = 100
    PS2_bit=0;
    TMR0=6;                  //counter starting value
}

void main() {
  Motor_Direction = 0;  // Set MOTOR pin as output
  LED_Direction = 0;  // Set LED pin as output
  TRISB.B1=0;
  PORTB.B1=0;
  Keypad_Init();
  Lcd_Init();
  Lcd_Cmd(_LCD_CLEAR);
  Lcd_Cmd(_LCD_CURSOR_OFF);
  Lcd_Out(1, 1, "Enter Pass:");

while(1){
           LED_Pin = 1;  // Turn on the LED
           Delay_ms(100);  // Delay for 1 seconds
           LED_Pin = 0;  // Turn on the LED
           Delay_ms(100);  // Delay for 1 seconds
if(counter>=3000){  // check if the counter reaches 125
                   Motor_Pin = 0;  // Turn ff the Motor

            //time=time++;    // increase time one second
           }
           

    kp = 0;
    //do
      kp = Keypad_Key_Click();             // Store key code in kp variable
    //while (!kp);
 if (kp && Motor_Pin==0) {

      switch (kp) {
      case  1: kp = '1'; break; // 1        // Uncomment this block for keypad4x4
      case  2: kp = '2'; break; // 2
      case  3: kp = '3'; break; // 3
      case  5: kp = '4'; break; // 4
      case  6: kp = '5'; break; // 5
      case  7: kp = '6'; break; // 6
      case  9: kp = '7'; break; // 7
      case 10: kp = '8'; break; // 8
      case 11: kp = '9'; break; // 9
      case 13: kp = '*'; break; // *
      case 14: kp = '0'; break; // 0
      case 15: kp = '#'; break; // #
  }

if(kp == '*')
   {    //clear
   }
else if (kp == '#'){
       for( i=0 ; i <4 ; i++){
         if(password[i] != My_pass[i]){
                   Lcd_Cmd(_LCD_CLEAR);
                   LCD_Out_CP("WRONG");
                   flag = 0;
                   break;
         }
        }
        if(flag)
         {         Lcd_Cmd(_LCD_CLEAR);
                   LCD_Out_CP("CORRECT");
                   Motor_Pin = 1;  // Turn on the Motor
            counter=0;      // start counter from the beginning
                   initialize_timer_Interrupt();   // invoke timer interrupt initialization function
                   //Motor_Pin = 0;  // Turn off the Motor
         }
}else{
  password[count] = kp;
  count++;
  Lcd_Chr_CP('*');
    }
      }
  }
}

void interrupt() {        // Interrupt handler
  if (INTCON.TMR0IF==1) {     // check for timer 0 interrupt flag
    counter++;                // increment 1 every interrupt
    INTCON.TMR0IF=0;          // reset the TMR0IF flag
    TMR0=6;                   // store 6 in the TMR0 register
  }
}