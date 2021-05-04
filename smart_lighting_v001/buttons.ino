

ISR(PCINT0_vect)
{  
  delay(150);
  
  if( !(PINB & 0x10)) // button up 
  {
    switch(menu)
    {
      case 1:
      menu = 75;
      break;

      case 2:
      hours += 10;
      if(hours > 23)
      {
        hours = 23;
      }
      break;

      case 3:
      hours += 1;
      if(hours > 23)
      {
        hours = 23;
      }
      break;

      case 4:
      minutes += 10;
      if(minutes > 59)
      {
        minutes = 59;
      }
      break;

      case 5:
      minutes += 1;
      if(minutes > 59)
      {
        minutes = 59;
      }
      break;

      case 6:
      menu = 1;
      break;

      case 7: // for 00:00-01:00
      increase_color(0);
      lcd.setCursor(12,1);
      print_color(0);
      lcd.setCursor(17,1);
      print_brightness(0); 
      break;

      case 8:
      increase_brightness(0);
      lcd.setCursor(17,1);
      print_brightness(0);
      break;

      case 9:
      menu = 6;
      break;

      case 10: // for 01:00-02:00
      increase_color(1);
      lcd.setCursor(12,2);
      print_color(1);
      lcd.setCursor(17,2);
      print_brightness(1);
      break;

      case 11:
      increase_brightness(1);
      lcd.setCursor(17,2);
      print_brightness(1);
      break;

      case 12:
      menu = 9;
      break;

      case 13: // for 02:00-03:00
      increase_color(2);
      lcd.setCursor(12,3);
      print_color(2);
      lcd.setCursor(17,3);
      print_brightness(2);
      break;

      case 14:
      increase_brightness(2);
      lcd.setCursor(17,3);
      print_brightness(2);
      break;

      case 15: // for 03:00-04:00
      case 18: // for 04:00-05:00
      case 21: // for 05:00-06:00
      case 24: // for 06:00-07:00
      menu -= 3;
      break;

      case 16: // color for 03:00-04:00
      case 19: // color for 04:00-05:00
      case 22: // color for 05:00-06:00
      case 25: // color for 06:00-07:00
      increase_color(current_hour);
      lcd.setCursor(12, current_hour - 3);
      print_color(current_hour);
      lcd.setCursor(17, current_hour - 3);
      print_brightness(current_hour);
      break;

      case 17: // brightness for 03:00-04:00
      case 20: // brightness for 04:00-05:00
      case 23: // brightness for 05:00-06:00
      case 26: // brightness for 06:00-07:00
      increase_brightness(current_hour);
      lcd.setCursor(17, current_hour - 3);
      print_brightness(current_hour);
      break;

      case 27: // for 07:00-08:00
      case 30: // for 08:00-09:00
      case 33: // for 09:00-10:00
      case 36: // for 10:00-11:00
      menu -= 3;
      break;

      case 28: // color for 07:00-08:00
      case 31: // color for 08:00-09:00
      case 34: // color for 09:00-10:00
      case 37: // color for 10:00-11:00
      increase_color(current_hour);
      lcd.setCursor(12, current_hour - 7);
      print_color(current_hour);
      lcd.setCursor(17, current_hour - 7);
      print_brightness(current_hour);
      break;

      case 29: // brightness for 07:00-08:00
      case 32: // brightness for 08:00-09:00
      case 35: // brightness for 09:00-10:00
      case 38: // brightness for 10:00-11:00
      increase_brightness(current_hour);
      lcd.setCursor(17, current_hour - 7);
      print_brightness(current_hour);
      break;

      case 39: // for 11:00-12:00
      case 42: // for 12:00-13:00
      case 45: // for 13:00-14:00
      case 48: // for 14:00-15:00
      menu -= 3;
      break;

      case 40: // color for 11:00-12:00
      case 43: // color for 12:00-13:00
      case 46: // color for 13:00-14:00
      case 49: // color for 14:00-15:00
      increase_color(current_hour);
      lcd.setCursor(12, current_hour - 11);
      print_color(current_hour);
      lcd.setCursor(17, current_hour - 11);
      print_brightness(current_hour);
      break;

      case 41: // brightness for 11:00-12:00
      case 44: // brightness for 12:00-13:00
      case 47: // brightness for 13:00-14:00
      case 50: // brightness for 14:00-15:00
      increase_brightness(current_hour);
      lcd.setCursor(17, current_hour - 11);
      print_brightness(current_hour);
      break;

      case 51: // for 15:00-16:00
      case 54: // for 16:00-17:00
      case 57: // for 17:00-18:00
      case 60: // for 18:00-19:00
      menu -= 3;
      break;

      case 52: // color for 15:00-16:00
      case 55: // color for 16:00-17:00
      case 58: // color for 17:00-18:00
      case 61: // color for 18:00-19:00
      increase_color(current_hour);
      lcd.setCursor(12, current_hour - 15);
      print_color(current_hour);
      lcd.setCursor(17, current_hour - 15);
      print_brightness(current_hour);
      break;

      case 53: // brightness for 15:00-16:00
      case 56: // brightness for 16:00-17:00
      case 59: // brightness for 17:00-18:00
      case 62: // brightness for 18:00-19:00
      increase_brightness(current_hour);
      lcd.setCursor(17, current_hour - 15);
      print_brightness(current_hour);
      break;

      case 63: // for 19:00-20:00
      case 66: // for 20:00-21:00
      case 69: // for 21:00-22:00
      case 72: // for 22:00-23:00
      menu -= 3;
      break;

      case 64: // color for 19:00-20:00
      case 67: // color for 20:00-21:00
      case 70: // color for 21:00-22:00
      case 73: // color for 22:00-23:00
      increase_color(current_hour);
      lcd.setCursor(12, current_hour - 19);
      print_color(current_hour);
      lcd.setCursor(17, current_hour - 19);
      print_brightness(current_hour);
      break;

      case 65: // brightness 19:00-20:00
      case 68: // brightness 20:00-21:00
      case 71: // brightness 21:00-22:00
      case 74: // brightness 22:00-23:00
      increase_brightness(current_hour);
      lcd.setCursor(17, current_hour - 19);
      print_brightness(current_hour);
      break;

      case 75: // for 23:00-00:00
      menu -= 3; // for 22:00-23:00
      break;

      case 76: // color 23:00-00:00
      increase_color(current_hour);
      lcd.setCursor(12, 0);
      print_color(current_hour);
      lcd.setCursor(17, 0);
      print_brightness(current_hour);
      break;

      case 77: // brightness 23:00-24:00
      increase_brightness(current_hour);
      lcd.setCursor(17, 0);
      print_brightness(current_hour);
      break;

      default:
      break;
    }
  }
  else if( !(PINB & 0x08) ) // button enter 
  {
    switch(menu)
    {
      case 1: // time select
      menu = 2;
      break;

      case 2: // hours +-10
      menu = 3;
      break;

      case 3: //  hours +-1
      menu = 4;
      break;

      case 4: //  minutes +-10
      menu = 5;
      break;

      case 5: //  minutes +-1
      eeprom_write_word(0, hours);
      eeprom_write_word(2, minutes);
      menu = 1;
      break;

      case 6: // 00:00-01:00
      current_hour = 0;
      menu = 7;
      break;

      case 7: // color
      //menu = 8;
      if(hour_par[current_hour].color != 0) // if not off
      {
        menu = 8;
      }
      else
      {
        menu = 6;
      }
      break;

      case 8: // brightness
      menu = 6;
      break;

      case 9: // 01:00-02:00
      current_hour = 1;
      menu = 10;
      break;

      case 10: // color
      //menu = 11;
      if(hour_par[current_hour].color != 0) // if not off
      {
        menu = 11;
      }
      else
      {
        menu = 9;
      }
      break;

      case 11: // brightness
      menu = 9;
      break;

      case 12: // 02:00-03:00
      current_hour = 2;
      menu = 13;
      break;

      case 13: // color
      //menu = 14;
      if(hour_par[current_hour].color != 0) // if not off
      {
        menu = 14;
      }
      else
      {
        menu = 12;
      }
      break;

      case 14: // brightness
      menu = 12;
      break;

      case 15: // 03:00-04:00
      current_hour = 3;
      menu = 16;
      break;

      case 16: // color 03:00-04:00
      case 19: // color 04:00-05:00
      case 22: // color 05:00-06:00
      case 25: // color 06:00-07:00
      if(hour_par[current_hour].color != 0) // if not off
      {
        menu += 1;
      }
      else
      {
        menu -= 1;
      }
      break;

      case 17: // brightness 03:00-04:00
      case 20: // brightness 04:00-05:00
      case 23: // brightness 05:00-06:00
      case 26: // brightness 06:00-07:00
      menu -= 2;
      break;

      case 18: // 04:00-05:00
      current_hour = 4;
      menu = 19;
      break;

      case 21: // 05:00-06:00
      current_hour = 5;
      menu = 22;
      break;

      case 24: // 06:00-07:00
      current_hour = 6;
      menu = 25;
      break;

      case 27: // 07:00-08:00
      current_hour = 7;
      menu = 28;
      break;

      case 28: // color 07:00-08:00
      case 31: // color 08:00-09:00
      case 34: // color 09:00-10:00
      case 37: // color 10:00-11:00
      if(hour_par[current_hour].color != 0) // if not off
      {
        menu += 1;
      }
      else
      {
        menu -= 1;
      }
      break;

      case 29: // brightness 07:00-08:00
      case 32: // brightness 08:00-09:00
      case 35: // brightness 09:00-10:00
      case 38: // brightness 10:00-11:00
      menu -= 2;
      break;

      case 30: // 08:00-09:00
      current_hour = 8;
      menu = 31;
      break;

      case 33: // 09:00-10:00
      current_hour = 9;
      menu = 34;
      break;

      case 36: // 10:00-11:00
      current_hour = 10;
      menu = 37;
      break;

      case 39: // for 11:00-12:00
      current_hour = 11;
      menu = 40;
      break;

      case 40: // color 11:00-12:00
      case 43: // color 12:00-13:00
      case 46: // color 13:00-14:00
      case 49: // color 14:00-15:00
      case 52: // color 15:00-16:00
      case 55: // color 16:00-17:00
      case 58: // color 17:00-18:00
      case 61: // color 18:00-19:00
      case 64: // color 19:00-20:00
      case 67: // color 20:00-21:00
      case 70: // color 21:00-22:00
      case 73: // color 22:00-23:00
      case 76: // color 23:00-00:00
      if(hour_par[current_hour].color != 0) // if not off
      {
        menu += 1;
      }
      else
      {
        menu -= 1;
      }
      break;

      case 41: // brightness 11:00-12:00
      case 44: // brightness 12:00-13:00
      case 47: // brightness 13:00-14:00
      case 50: // brightness 14:00-15:00
      case 53: // brightness 15:00-16:00
      case 56: // brightness 16:00-17:00
      case 59: // brightness 17:00-18:00
      case 62: // brightness 18:00-19:00
      case 65: // brightness 19:00-20:00
      case 68: // brightness 20:00-21:00
      case 71: // brightness 21:00-22:00
      case 74: // brightness 22:00-23:00
      case 77: // brightness 23:00-00:00
      menu -= 2;
      break;

      case 42: // for 12:00-13:00
      current_hour = 12;
      menu += 1;
      break;

      case 45: // for 13:00-14:00
      current_hour = 13;
      menu += 1;
      break;

      case 48: // for 14:00-15:00
      current_hour = 14;
      menu += 1;
      break;

      case 51: // for 15:00-16:00
      current_hour = 15;
      menu += 1;
      break;

      case 54: // for 16:00-17:00
      current_hour = 16;
      menu += 1;
      break;

      case 57: // for 17:00-18:00
      current_hour = 17;
      menu += 1;
      break;

      case 60: // for 18:00-19:00
      current_hour = 18;
      menu += 1;
      break;

      case 63: // for 19:00-20:00
      current_hour = 19;
      menu += 1;
      break;
      
      case 66: // for 20:00-21:00
      current_hour = 20;
      menu += 1;
      break;
      
      case 69: // for 21:00-22:00
      current_hour = 21;
      menu += 1;
      break;
      
      case 72: // for 22:00-23:00
      current_hour = 22;
      menu += 1;
      break;

      case 75: // for 23:00-00:00
      current_hour = 23;
      menu += 1;
      break;

      default:
      break;
    }
  }
  else if( !(PINB & 0x01) ) // button down
  {
    switch(menu)
    {
      case 1:
      menu = 6;
      break;

      case 2:
      hours -= 10;
      if(hours < 0)
      {
        hours = 0;
      }
      break;

      case 3:
      hours -= 1;
      if(hours < 0)
      {
        hours = 0;
      }
      break;

      case 4:
      minutes -= 10;
      if(minutes < 0)
      {
        minutes = 0;
      }
      break;

      case 5:
      minutes -= 1;
      if(minutes < 0)
      {
        minutes = 0;
      }
      break;

      case 6:
      menu = 9;
      break;

      case 7: // for 00:00-01:00
      decrease_color(0);
      lcd.setCursor(12,1);
      print_color(0);
      lcd.setCursor(17,1);
      print_brightness(0);
      break;

      case 8:
      decrease_brightness(0);
      lcd.setCursor(17,1);
      print_brightness(0);
      break;

      case 9:
      menu = 12;
      break;

      case 10: // for 01:00-02:00
      decrease_color(1);
      lcd.setCursor(12,2);
      print_color(1);
      lcd.setCursor(17,2);
      print_brightness(1);
      break;

      case 11:
      decrease_brightness(1);
      lcd.setCursor(17,2);
      print_brightness(1);
      break;

      case 12:
      menu = 15;
      break;

      case 13: // for 02:00-03:00
      decrease_color(2);
      lcd.setCursor(12,3);
      print_color(2);
      lcd.setCursor(17,3);
      print_brightness(2);
      break;

      case 14:
      decrease_brightness(2);
      lcd.setCursor(17,3);
      print_brightness(2);
      break;

      case 15: // for 03:00-04:00
      case 18: // for 04:00-05:00
      case 21: // for 05:00-06:00
      case 24: // for 06:00-07:00
      menu = menu + 3;
      break;

      case 16: // color 03:00-04:00
      case 19: // color 04:00-05:00
      case 22: // color 05:00-06:00
      case 25: // color 06:00-07:00
      decrease_color(current_hour);
      lcd.setCursor(12, current_hour - 3);
      print_color(current_hour);
      lcd.setCursor(17, current_hour - 3);
      print_brightness(current_hour);
      break;

      case 17: // brightness 03:00-04:00
      case 20: // brightness 04:00-05:00
      case 23: // brightness 05:00-06:00
      case 26: // brightness 06:00-07:00
      decrease_brightness(current_hour);
      lcd.setCursor(17, current_hour - 3);
      print_brightness(current_hour);
      break;

      case 27: // 07:00-08:00
      case 30: // 08:00-09:00
      case 33: // 09:00-10:00
      case 36: // 10:00-11:00
      menu = menu + 3;
      break;

      case 28: // color 07:00-08:00
      case 31: // color 08:00-09:00
      case 34: // color 09:00-10:00
      case 37: // color 10:00-11:00
      decrease_color(current_hour);
      lcd.setCursor(12, current_hour - 7);
      print_color(current_hour);
      lcd.setCursor(17, current_hour - 7);
      print_brightness(current_hour);
      break;

      case 29: // brightness 03:00-04:00
      case 32: // brightness 04:00-05:00
      case 35: // brightness 05:00-06:00
      case 38: // brightness 06:00-07:00
      decrease_brightness(current_hour);
      lcd.setCursor(17, current_hour - 7);
      print_brightness(current_hour);
      break;

      case 39: // for 11:00-12:00
      case 42: // for 12:00-13:00
      case 45: // for 13:00-14:00
      case 48: // for 14:00-15:00
      menu += 3;
      break;

      case 40: // color 11:00-12:00
      case 43: // color 12:00-13:00
      case 46: // color 13:00-14:00
      case 49: // color 14:00-15:00
      decrease_color(current_hour);
      lcd.setCursor(12, current_hour - 11);
      print_color(current_hour);
      lcd.setCursor(17, current_hour - 11);
      print_brightness(current_hour);
      break;

      case 41: // brightness 11:00-12:00
      case 44: // brightness 12:00-13:00
      case 47: // brightness 13:00-14:00
      case 50: // brightness 14:00-15:00
      decrease_brightness(current_hour);
      lcd.setCursor(17, current_hour - 11);
      print_brightness(current_hour);
      break;

      case 51: // for 15:00-16:00
      case 54: // for 16:00-17:00
      case 57: // for 17:00-18:00
      case 60: // for 18:00-19:00
      menu += 3;
      break;

      case 52: // color 15:00-16:00
      case 55: // color 16:00-17:00
      case 58: // color 17:00-18:00
      case 61: // color 18:00-19:00
      decrease_color(current_hour);
      lcd.setCursor(12, current_hour - 15);
      print_color(current_hour);
      lcd.setCursor(17, current_hour - 15);
      print_brightness(current_hour);
      break;

      case 53: // brightness 15:00-16:00
      case 56: // brightness 16:00-17:00
      case 59: // brightness 17:00-18:00
      case 62: // brightness 18:00-19:00
      decrease_brightness(current_hour);
      lcd.setCursor(17, current_hour - 15);
      print_brightness(current_hour);
      break;

      //case 60: // for 18:00-19:00
      //menu = 1; // for 00:00-01:00
      //break;

      case 63: // for 19:00-20:00
      case 66: // for 20:00-21:00
      case 69: // for 21:00-22:00
      case 72: // for 22:00-23:00
      menu += 3;
      break;

      case 64: // color 19:00-20:00
      case 67: // color 20:00-21:00
      case 70: // color 21:00-22:00
      case 73: // color 22:00-23:00
      decrease_color(current_hour);
      lcd.setCursor(12, current_hour - 19);
      print_color(current_hour);
      lcd.setCursor(17, current_hour - 19);
      print_brightness(current_hour);
      break;

      case 65: // brightness 19:00-20:00
      case 68: // brightness 20:00-21:00
      case 71: // brightness 21:00-22:00
      case 74: // brightness 22:00-23:00
      decrease_brightness(current_hour);
      lcd.setCursor(17, current_hour - 19);
      print_brightness(current_hour);
      break;

      case 75: // for 23:00-00:00
      menu = 1; // for 00:00-01:00
      break;

      case 76: // color 23:00-00:00
      decrease_color(current_hour);
      lcd.setCursor(12, 0);
      print_color(current_hour);
      lcd.setCursor(17, 0);
      print_brightness(current_hour);
      break;

      case 77: // brightness 23:00-24:00
      decrease_brightness(current_hour);
      lcd.setCursor(17, 0);
      print_brightness(current_hour);
      break;
      
      default:
      break;
    }
  }
  
  
  if(menu >= 0 and menu <= 14)
  {
    print_time();
  }
  
  print_menu();
  delay(150);
}
