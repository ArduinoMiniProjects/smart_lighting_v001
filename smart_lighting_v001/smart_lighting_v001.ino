#include <IRremote.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>

// IRremote.h library uses Timer1
// PWM pins 5 (PD5; OC0B) and 6 (PD6; OC0A) controlled by Timer0
// PWM pins 9 (PB1; OC1A) and 10 (PB2; OC1B) controlled by Timer1
// PWM pins 11 (PB3; OC2A) and 3 (PD3; OC2B) controlled by Timer2

// !!! ALL TIMERS ARE USED by LIBRARIES
// Timer0 8-bit
// Timer1 16-bit
// Timer2 8-bit

// pins 0-7: PROT D [0:7]
// pins 8-13: PORT B [0:5]
// pins 14-19: PROT C [0:5] (Arduino analog pins 0-5)

// digital pins 0 and 1 are RX and TX for serial communication

// digital pin 13 connected to the base board LED

/*
 * LCD RS pin to digital pin 10
 * LCD Enable pin to digital pin 9
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 0
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V 
*/

IRsend irsend;
// IR LED must be connected to Arduino PWM pin 3

const int rs = 10, en = 9, d4 = 5, d5 = 4, d6 = 0, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//unsigned int commands[8][67]; // 8 commands: ON, OFF, Brighter, Darker, White, red, Blue, pink

// command_on LG  (28 bits)  0xFFA25
unsigned int command_on[67] = {8850,4400, 600,550, 550,600, 550,550, 600,550, 600,550, 550,600, 
                             550,550, 600,550, 600,1600, 600,1600, 600,1600, 600,1600, 600,1600, 
                             600,1600, 600,1600, 600, 1600, 600,1600, 600,550, 600,1600, 600,550, 
                             550,600, 550,550, 600,1600, 600,550, 600,550, 550,1650, 550,600, 550,
                             1650, 550,1650, 550,1650, 550,550, 600,1600, 600};

// 0xFF629
unsigned int command_off[67] = {8900,4400, 600,550, 600,500, 600,550, 600,550, 600,550, 600,550,
                                600,500, 600,550, 600,1600, 600,1600, 600,1600, 600,1600, 600,1650,
								                600,1600, 600,1600, 600,1600, 600,550, 600,1600, 600,1600, 600,550,
								                600,500, 600,550, 600,1600, 600,550, 600,1600, 600,550, 600,550, 600,
								                1600, 600,1600, 600,1600, 600,550, 600,1600, 600};

// 0xFFE01
unsigned int command_brighter[67] = {8850,4450, 550,550, 600,550, 600,550, 550,600, 550,550, 600,550,
                                     600,550, 550,600, 550,1650, 550,1650, 550,1650, 550,1650, 550,1650, 
                                     550,1650, 600,1600, 600,1600, 600,1600, 600,1600, 600,1600, 600,550, 
                                     600,550, 550,600, 550,550, 600,550, 600,550, 550,600, 550,550, 600,
                                     1650, 550,1650, 550,1650, 550,1650, 550,1650, 550};

// 0xFFA85
unsigned int command_darker[67] = {8900,4400, 600,550, 600,500, 650,500, 600,550, 600,550, 600,550, 600,500,
                                   600,550, 600,1600, 600,1600, 600,1600, 600,1600, 600,1600, 600,1650, 600,
                                   1600, 600,1600, 600,1600, 600,500, 650,1600, 600,500, 600,1600, 600,550, 
                                   600,550, 600,550, 600,500, 600,1600, 650,500, 600,1600, 600,550, 600,1600,
                                   600,1600, 600,1600, 600};

// 0xFF906
unsigned int command_white[67] = {8850,4450, 550,550, 600,550, 600,550, 550,600, 550,600, 550,550, 600,550, 
                                  600,550, 550,1650, 550,1650, 550,1650, 550,1650, 600,1600, 600,1600, 600,
                                  1600, 600,1600, 600,1600, 600,550, 600,550, 550,1650, 550,600, 550,550, 600,
                                  550, 600,550, 550,600, 550,1650, 550,1650, 550,600, 550,1650, 550,1650, 550,
                                  1650, 550,1650, 550};

// 0xFF689
unsigned int command_red[67] = {8900,4400, 600,550, 600,550, 550,600, 550,550, 600,550, 600,550, 550,600, 550,
                                550, 600,1650, 550,1650, 550,1650, 550,1650, 550,1650, 550,1650, 550,1650, 550,
                                1650, 550,600, 550,1650, 550,1650, 550,600, 550,1650, 550,550, 600,550, 600,550,
                                550,1650, 600,550, 550,600, 600,1600, 600,500, 600,1600, 600,1600, 650,1600, 600};

// 0xFF7A8
unsigned int command_blue[67] = {8900,4400, 600,550, 600,550, 550,600, 550,550, 600,550, 600,550, 550,600, 550,
                                 550,600,1600, 600,1650, 550,1650, 550,1650, 550,1650, 550,1650, 550,1650, 550,
                                 1650, 550, 600, 550,1650, 550,1650, 550,1650, 550,1650, 600,550, 550,1650, 550,600,
                                 550,1650,550,550, 600,550, 600,550, 600,550, 550,1650, 550,600, 550,1650, 550};

// 0xFF52A
unsigned int command_pink[67] = {8850,4450, 550,550, 600,550, 600,550, 550,600, 550,550, 600,550, 600,550, 550,600,
                                 550,1650, 550,1650, 550,1650, 550,1650, 550,1650, 550,1650, 600,1600, 600,1600, 600,
                                 550, 550,1650, 600,550, 550,1650, 550,600, 550,550, 600,1600, 600,550, 600,1600, 600,
                                 550, 600,1600, 600,550, 550,1650, 550,1650, 550,600, 550,1650, 550};

int khz = 38; // frequency

// structure that contains led light parameters for each hour
struct lights_param 
{
  int color; // 0=off; 1=white; 2=red; 3=blue; 4=pink;
  int brightness; // 1=dark; 2=bright;
};

lights_param hour_par[24]; // parameters for each hour

int i; // for loops
int j; // for loops

int menu = 1;

int hours = 0;   // of clock
int minutes = 0; // of clock
int seconds = 0; // of clock

// !!! All timers are used by libraries
float t0=0;  // variable for time calculations
float t1=0; // variable for time calculations
float t3=0; // variable for time calculations

char char_arrow = 0b01111111; // symbol of an arrow
char char_accept = 0b11111111; // symbol of accept

int b_up = 12; // button up, Pin 12, PB4
int b_enter = 11; // button enter, Pin 11, PB3 
int b_down = 8; // button down, Pin 8, PB0

int current_hour = 0; // menu parameters

//void timer_ini(void);
void increase_time(void);
void print_time(void);
void print_color(int hour);
void print_brightness(int hour);
void increase_color(int hour);
void decrease_color(int hour);
void increase_brightness(int hour);
void decrease_brightness(int hour);
void print_menu(void);
void send_command(int hour);
void send_command_on(void);


void  setup ( )
{
  for(i=0; i<24; i++)
  {
    hour_par[i].color = 0; // off at beginning
    //eeprom_write_word(4+i*2, hour_par[i].color);
    hour_par[i].brightness = 1; // dark at beginnig
    //eeprom_write_word(52+i*2, hour_par[i].brightness);
  }
  
  for(i=0; i<24; i++) // reading parameters from eeprom memory
  {
    hour_par[i].color = eeprom_read_word(4+i*2); 
    hour_par[i].brightness = eeprom_read_word(52+i*2);
  }

  //eeprom_write_word(0, hours);
  //eeprom_write_word(2, minutes);

  hours = eeprom_read_word(0);
  minutes = eeprom_read_word(2);
  
  lcd.begin(20, 4);
  lcd.setCursor(0, 0);  
  print_time();
  print_menu();
  
  cli(); // interrupts forbidden

  //timer_ini();

  pinMode(b_up, INPUT); // Pin 12, PB4
  pinMode(b_enter, INPUT); // Pin 11, PB3
  pinMode(b_down, INPUT); // Pin 8, PB0

  // pull up resistors for PB4, PB3, PB0 inputs
  PORTB |= (1 << PORTB4) | (1 << PORTB3) | (1 << PORTB0);

  // inputs as Pin Change interrupts
  PCMSK0 |= (1 << PCINT4) | (1 << PCINT3) | (1 << PCINT0);
  
  // Pin Change interrupts enabled PCINT4, PCINT3, PCINT0
  PCICR |= (1 << PCIE0);
  
  sei(); // interrupts are enabled
}



void  loop ( )
{ 
  //
  // !!! All timers are used by libraries
  t0=(millis()-t1);
  t1=millis();
  delay(350); // probably better 330ms, three cycles=1000ms
       
  switch(menu) // menu blinking
  {
    case 2:
    lcd.setCursor(0,0);
    lcd.print(' ');
    delay(350); 
    lcd.setCursor(0,0);
    lcd.print(hours/10);
    send_command(hours); // send command for selected hour
    break;

    case 3:
    lcd.setCursor(1,0);
    lcd.print(' ');
    delay(350);
    lcd.setCursor(1,0);
    lcd.print(hours%10);
    send_command(hours); // send command for selected hour
    break;

    case 4:
    lcd.setCursor(3,0);
    lcd.print(' ');
    delay(350);
    lcd.setCursor(3,0);
    lcd.print(minutes/10);
    break;

    case 5:
    lcd.setCursor(4,0);
    lcd.print(' ');
    delay(350);
    lcd.setCursor(4,0);
    lcd.print(minutes%10);
    break;  

    case 6: // 00:00-01:00
    case 9: // 01:00-02:00
    case 12: // 02:00-03:00
    break;

    case 7:
    case 10:
    case 13:
    lcd.setCursor(12, current_hour + 1);
    lcd.print("    ");
    delay(350);
    lcd.setCursor(12, current_hour + 1);
    print_color(current_hour); 
    send_command(hours); // send command if color is changed
    break;
    
    case 8:
    case 11:
    case 14:
    lcd.setCursor(17, current_hour + 1);
    lcd.print("  ");
    delay(350);
    lcd.setCursor(17, current_hour + 1);
    print_brightness(current_hour);
    send_command(hours); // send command if brightness is changed
    break;

    case 15: // 03:00-04:00
    case 18: // 04:00-05:00
    case 21: // 05:00-06:00
    case 24: // 06:00-07:00
    break;

    case 16:
    case 19:
    case 22:
    case 25:
    lcd.setCursor(12, current_hour - 3);
    lcd.print("    ");
    delay(350);
    lcd.setCursor(12, current_hour - 3);
    print_color(current_hour); 
    send_command(hours); // send command if brightness is changed
    break;

    case 17:
    case 20:
    case 23:
    case 26:
    lcd.setCursor(17, current_hour - 3);
    lcd.print("  ");
    delay(350);
    lcd.setCursor(17, current_hour - 3);
    print_brightness(current_hour);
    send_command(hours); // send command if brightness is changed
    break;

    case 27: // for 07:00-08:00
    case 30: // for 08:00-09:00
    case 33: // for 09:00-10:00
    case 36: // for 10:00-11:00
    break;

    case 28:
    case 31:
    case 34:
    case 37:
    lcd.setCursor(12, current_hour - 7);
    lcd.print("    ");
    delay(350);
    lcd.setCursor(12, current_hour - 7);
    print_color(current_hour); 
    send_command(hours); // send command if brightness is changed
    break;

    case 29:
    case 32:
    case 35:
    case 38:
    lcd.setCursor(17, current_hour - 7);
    lcd.print("  ");
    delay(350);
    lcd.setCursor(17, current_hour - 7);
    print_brightness(current_hour);
    send_command(hours); // send command if brightness is changed
    break;

    case 39: // for 11:00-12:00
    case 42: // for 12:00-13:00
    case 45: // for 13:00-14:00
    case 48: // for 14:00-15:00
    break;

    case 40:
    case 43:
    case 46:
    case 49:
    lcd.setCursor(12, current_hour - 11);
    lcd.print("    ");
    delay(350);
    lcd.setCursor(12, current_hour - 11);
    print_color(current_hour); 
    send_command(hours); // send command if brightness is changed
    break;

    case 41:
    case 44:
    case 47:
    case 50:
    lcd.setCursor(17, current_hour - 11);
    lcd.print("  ");
    delay(350);
    lcd.setCursor(17, current_hour - 11);
    print_brightness(current_hour);
    send_command(hours); // send command if brightness is changed
    break;

    case 51: // for 15:00-16:00
    case 54: // for 16:00-17:00
    case 57: // for 17:00-18:00
    case 60: // for 18:00-19:00
    break;

    case 52:
    case 55:
    case 58:
    case 61:
    lcd.setCursor(12, current_hour - 15);
    lcd.print("    ");
    delay(350);
    lcd.setCursor(12, current_hour - 15);
    print_color(current_hour); 
    send_command(hours); // send command if brightness is changed
    break;

    case 53:
    case 56:
    case 59:
    case 62:
    lcd.setCursor(17, current_hour - 15);
    lcd.print("  ");
    delay(350);
    lcd.setCursor(17, current_hour - 15);
    print_brightness(current_hour);
    send_command(hours); // send command if brightness is changed
    break;

    case 63: // for 19:00-20:00
    case 66: // for 20:00-21:00
    case 69: // for 21:00-22:00
    case 72: // for 22:00-23:00
    break;

    case 64:
    case 67:
    case 70:
    case 73:
    lcd.setCursor(12, current_hour - 19);
    lcd.print("    ");
    delay(350);
    lcd.setCursor(12, current_hour - 19);
    print_color(current_hour); 
    send_command(hours); // send command if brightness is changed
    break;

    case 65:
    case 68:
    case 71:
    case 74:
    lcd.setCursor(17, current_hour - 19);
    lcd.print("  ");
    delay(350);
    lcd.setCursor(17, current_hour - 19);
    print_brightness(current_hour);
    send_command(hours); // send command if brightness is changed
    break;

    case 75: // for 23:00-00:00
    break;

    case 76:
    lcd.setCursor(12, 0);
    lcd.print("    ");
    delay(350);
    lcd.setCursor(12, 0);
    print_color(current_hour); 
    send_command(hours); // send command if brightness is changed
    break;

    case 77:
    lcd.setCursor(17, 0);
    lcd.print("  ");
    delay(350);
    lcd.setCursor(17, 0);
    print_brightness(current_hour);
    send_command(hours); // send command if brightness is changed
    break;

    default:
    break;
  }
      
  // !!! All timers are used by libraries
  t3 += t0; // summs up time of loop iteration
  if(t3 > 1000) // if one second passed
  {
    t3 -= 1000; //  time -1000ms
    if( !(menu >=2 and menu<=5) )
    {
      increase_time();
      if(menu >= 1 and  menu <= 14) // window 1
      {
         print_time();
      }
      print_menu();
      if(seconds == 0)
      {
        send_command(hours); // send command each minute
      } 
    }
  }
      
}


void increase_time(void)
{
  seconds++;
  if(seconds == 60)
  {
    seconds = 0;
    minutes++;
    
    if(minutes == 60)
    {
      minutes = 0;
      hours++;
      if(hours == 24)
      {
        hours = 0;
      }
    }
    eeprom_write_word(0, hours);
    eeprom_write_word(2, minutes);
  }
}


void print_time(void)
{
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  //lcd.setCursor(0, 1);
  lcd.setCursor(0, 0);
  lcd.print(hours/10); // print first digit of hours
  lcd.print(hours%10); // print second digit of hours
  lcd.print(':');
  lcd.print(minutes/10);
  lcd.print(minutes%10);
  lcd.print(':');
  lcd.print(seconds/10);
  lcd.print(seconds%10);
}


/*
void timer_ini(void)
{
  TCCR0A |= (1<<WGM01); // CTC mode for timer 0
  TCCR0A &= ~(1<<WGM00);// set to zero
  TCCR0B &= ~(1<<WGM02); // set to zero
  TIMSK0 |= (1 << OCIE0A); // Output compare A match interrupt enabled
  OCR0A = 0xFE; //
  TCCR0B |= (1 << CS12) | (1 << CS10); // prescaler 1024 for 0. timer 
  TCCR0B &= ~(1 << CS11); // set CS11 to zero
}
*/


void increase_color(int hour)
{
  hour_par[hour].color += 1;
  if(hour_par[hour].color > 4)
  {
    hour_par[hour].color = 4;
  }
  eeprom_write_word(4+hour*2, hour_par[hour].color); // save to memory
}


void decrease_color(int hour)
{
  hour_par[hour].color -= 1;
  if(hour_par[hour].color < 0)
  {
    hour_par[hour].color = 0;
  }
  eeprom_write_word(4+hour*2, hour_par[hour].color); // save to memory
}


void increase_brightness(int hour)
{
  hour_par[hour].brightness += 1;
  if(hour_par[hour].brightness > 2)
  {
    hour_par[hour].brightness = 2;
  }
  eeprom_write_word(52+hour*2, hour_par[hour].brightness); // save to memory
}


void decrease_brightness(int hour)
{
  hour_par[hour].brightness -= 1;
  if(hour_par[hour].brightness < 1)
  {
    hour_par[hour].brightness = 1;
  }
  eeprom_write_word(52+hour*2, hour_par[hour].brightness); // save to memory
}


void print_color(int hour)
{
  switch(hour_par[hour].color) // 0=off; 1=white; 2=red; 3=blue; 4=pink;
  {
    case 0:
    lcd.print("off  ");
    break;

    case 1:
    lcd.print("whit ");
    break;

    case 2:
    lcd.print("red  ");
    break;

    case 3:
    lcd.print("blue ");
    break;

    case 4:
    lcd.print("pink ");
    break;

    default:
    break;
  }
}


void print_brightness(int hour)
{
  if(hour_par[hour].color == 0)
  {
    lcd.print("  ");
  }
  else
  {
    switch(hour_par[hour].brightness)
    {
      case 1:
      lcd.print("b1");
      break;

      case 2:
      lcd.print("b2");
      break;

      default:
      break;
    }
  }
}


void send_command(int hour)
{
  switch( hour_par[hour].color ) // 0=off; 1=white; 2=red; 3=blue; 4=pink;
  {
    case 0:
    irsend.sendRaw(command_off, sizeof(command_off)/sizeof(command_off[0]), khz);
    irsend.sendRaw(command_off, sizeof(command_off)/sizeof(command_off[0]), khz);
    irsend.sendRaw(command_off, sizeof(command_off)/sizeof(command_off[0]), khz);
    delay(100);
    break;

    case 1:
    send_command_on();
    irsend.sendRaw(command_white, sizeof(command_white)/sizeof(command_white[0]), khz);
    irsend.sendRaw(command_white, sizeof(command_white)/sizeof(command_white[0]), khz);
    irsend.sendRaw(command_white, sizeof(command_white)/sizeof(command_white[0]), khz);
    delay(100);
    break;

    case 2:
    send_command_on();
    irsend.sendRaw(command_red, sizeof(command_red)/sizeof(command_red[0]), khz);
    irsend.sendRaw(command_red, sizeof(command_red)/sizeof(command_red[0]), khz);
    irsend.sendRaw(command_red, sizeof(command_red)/sizeof(command_red[0]), khz);
    delay(100);
    break;

    case 3:
    send_command_on();
    irsend.sendRaw(command_blue, sizeof(command_blue)/sizeof(command_blue[0]), khz);
    irsend.sendRaw(command_blue, sizeof(command_blue)/sizeof(command_blue[0]), khz);
    irsend.sendRaw(command_blue, sizeof(command_blue)/sizeof(command_blue[0]), khz);
    delay(100);
    break;

    case 4:
    send_command_on();
    irsend.sendRaw(command_pink, sizeof(command_pink)/sizeof(command_pink[0]), khz);
    irsend.sendRaw(command_pink, sizeof(command_pink)/sizeof(command_pink[0]), khz);
    irsend.sendRaw(command_pink, sizeof(command_pink)/sizeof(command_pink[0]), khz);
    delay(100);
    break;
  }

  if(hour_par[hour].color != 0)
  {
    switch( hour_par[hour].brightness )
    {
      case 1:
      irsend.sendRaw(command_darker, sizeof(command_darker)/sizeof(command_darker[0]), khz);
      irsend.sendRaw(command_darker, sizeof(command_darker)/sizeof(command_darker[0]), khz);
      irsend.sendRaw(command_darker, sizeof(command_darker)/sizeof(command_darker[0]), khz);
      delay(100);
      break;

      case 2:
      irsend.sendRaw(command_brighter, sizeof(command_brighter)/sizeof(command_brighter[0]), khz);
      irsend.sendRaw(command_brighter, sizeof(command_brighter)/sizeof(command_brighter[0]), khz);
      irsend.sendRaw(command_brighter, sizeof(command_brighter)/sizeof(command_brighter[0]), khz);
      delay(100);
      break;

      default:
      break;      
    }
  }
}


void send_command_on(void)
{
  irsend.sendRaw(command_on, sizeof(command_on)/sizeof(command_on[0]), khz);
  irsend.sendRaw(command_on, sizeof(command_on)/sizeof(command_on[0]), khz);
  irsend.sendRaw(command_on, sizeof(command_on)/sizeof(command_on[0]), khz);
  delay(100);
}
