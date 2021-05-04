void print_menu(void)
{
  switch(menu)
  {
    case 1: // window 1
    lcd.clear();
    print_time();
    lcd.setCursor(10, 0);
    lcd.print("Time");
    lcd.setCursor(14, 0);
    lcd.print(char_arrow);
    lcd.setCursor(0, 1);
    lcd.print("00:00-01:00 "); // blue, brightness 1; lamp 1
    //lcd.print("01:00-02:00 blue b1 "); // blue,  brightness 1;
    //lcd.print("01:00-02:00 red  b2 "); // red,  brightness 2;
    lcd.setCursor(12,1);
    print_color(0); // for 00:00-01:00
    lcd.setCursor(17,1);
    print_brightness(0); // for 00:00-01:00
    lcd.setCursor(0, 2);
    lcd.print("01:00-02:00 "); 
    lcd.setCursor(12,2); 
    print_color(1); // for 01:00-02:00
    lcd.setCursor(17,2);
    print_brightness(1); // for 01:00-02:00
    lcd.setCursor(0, 3);
    lcd.print("02:00-03:00 ");
    lcd.setCursor(12,3); 
    print_color(2); // for 02:00-03:00
    lcd.setCursor(17,3);
    print_brightness(2); // for 02:00-03:00
    break;

    case 2:
    lcd.setCursor(8, 0);
    lcd.print(char_arrow);
    lcd.setCursor(14, 0);
    lcd.print(char_accept);
    break;

    case 3:
    break;

    case 4:
    break;

    case 5:
    break;

    case 6:
    lcd.setCursor(14, 0);
    lcd.print(" ");
    lcd.setCursor(19, 2);
    lcd.print(" ");
    lcd.setCursor(19, 1);
    lcd.print(char_arrow);
    break;

    case 7:
    lcd.setCursor(19, 1);
    lcd.print(char_accept);
    break;

    case 8:
    break;

    case 9:
    lcd.setCursor(19, 1);
    lcd.print(" ");
    lcd.setCursor(19, 3);
    lcd.print(" ");
    lcd.setCursor(19, 2);
    lcd.print(char_arrow);
    break;

    case 10:
    lcd.setCursor(19, 2);
    lcd.print(char_accept);
    break;

    case 11:
    break;

    case 12:
    lcd.clear();
    print_time();
    lcd.setCursor(10, 0);
    lcd.print("Time");
    lcd.setCursor(0, 1);
    lcd.print("00:00-01:00 "); // blue, brightness 1; lamp 1
    lcd.setCursor(12,1);
    print_color(0); // for 00:00-01:00
    lcd.setCursor(17,1);
    print_brightness(0); // for 00:00-01:00
    lcd.setCursor(0, 2);
    lcd.print("01:00-02:00 "); 
    lcd.setCursor(12,2); 
    print_color(1); // for 01:00-02:00
    lcd.setCursor(17,2);
    print_brightness(1); // for 01:00-02:00
    lcd.setCursor(0, 3);
    lcd.print("02:00-03:00 ");
    lcd.setCursor(12,3); 
    print_color(2); // for 02:00-03:00
    lcd.setCursor(17,3);
    print_brightness(2); // for 02:00-03:00
    //lcd.setCursor(19, 2);
    //lcd.print(" ");
    lcd.setCursor(19, 3);
    lcd.print(char_arrow);
    break;

    case 13:
    lcd.setCursor(19, 3);
    lcd.print(char_accept);
    break;

    case 14:
    break;

    case 15: // window 2
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("03:00-04:00 "); 
    lcd.setCursor(12,0);
    print_color(3); // for 03:00-04:00
    lcd.setCursor(17,0);
    print_brightness(3); // for 03:00-04:00
    lcd.setCursor(19, 0);
    lcd.print(char_arrow);
    lcd.setCursor(0, 1);
    lcd.print("04:00-05:00 "); 
    lcd.setCursor(12,1); 
    print_color(4); // for 04:00-05:00
    lcd.setCursor(17,1);
    print_brightness(4); // for 04:00-05:00
    lcd.setCursor(0, 2);
    lcd.print("05:00-06:00 ");
    lcd.setCursor(12,2);
    print_color(5); // for 05:00-06:00
    lcd.setCursor(17,2);
    print_brightness(5); // for 05:00-06:00
    lcd.setCursor(0, 3);
    lcd.print("06:00-07:00 ");
    lcd.setCursor(12,3);
    print_color(6); // for 06:00-07:00
    lcd.setCursor(17,3);
    print_brightness(6); // for 06:00-07:00
    break;

    case 16:
    lcd.setCursor(19, 0);
    lcd.print(char_accept);
    break;

    case 17:
    break;

    case 18:
    lcd.setCursor(19, 0);
    lcd.print(' ');
    lcd.setCursor(19, 2);
    lcd.print(' ');
    lcd.setCursor(19, 1);
    lcd.print(char_arrow);
    break;

    case 19:
    lcd.setCursor(19, 1);
    lcd.print(char_accept);
    break;

    case 20:
    break;

    case 21:
    lcd.setCursor(19, 1);
    lcd.print(' ');
    lcd.setCursor(19, 3);
    lcd.print(' ');
    lcd.setCursor(19, 2);
    lcd.print(char_arrow);
    break;

    case 22: 
    lcd.setCursor(19, 2);
    lcd.print(char_accept);
    break;

    case 23:
    break;

    case 24:
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("03:00-04:00 "); 
    lcd.setCursor(12,0);
    print_color(3); // for 03:00-04:00
    lcd.setCursor(17,0);
    print_brightness(3); // for 03:00-04:00
    lcd.setCursor(19, 3);
    lcd.print(char_arrow);
    lcd.setCursor(0, 1);
    lcd.print("04:00-05:00 "); 
    lcd.setCursor(12,1); 
    print_color(4); // for 04:00-05:00
    lcd.setCursor(17,1);
    print_brightness(4); // for 04:00-05:00
    lcd.setCursor(0, 2);
    lcd.print("05:00-06:00 ");
    lcd.setCursor(12,2);
    print_color(5); // for 05:00-06:00
    lcd.setCursor(17,2);
    print_brightness(5); // for 05:00-06:00
    lcd.setCursor(0, 3);
    lcd.print("06:00-07:00 ");
    lcd.setCursor(12,3);
    print_color(6); // for 06:00-07:00
    lcd.setCursor(17,3);
    print_brightness(6); // for 06:00-07:00
    break;

    case 25: 
    lcd.setCursor(19, 3);
    lcd.print(char_accept);
    break;

    case 26:
    break;

    case 27: // window 3
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("07:00-08:00 "); 
    lcd.setCursor(12,0);
    print_color(7); // for 07:00-08:00
    lcd.setCursor(17,0);
    print_brightness(7); // for 07:00-08:00
    lcd.setCursor(19, 0);
    lcd.print(char_arrow);
    lcd.setCursor(0, 1);
    lcd.print("08:00-09:00 "); 
    lcd.setCursor(12,1); 
    print_color(8); // for 08:00-09:00
    lcd.setCursor(17,1);
    print_brightness(8); // for 08:00-09:00
    lcd.setCursor(0, 2);
    lcd.print("09:00-10:00 ");
    lcd.setCursor(12,2);
    print_color(9); // for 09:00-10:00
    lcd.setCursor(17,2);
    print_brightness(9); // for 09:00-10:00
    lcd.setCursor(0, 3);
    lcd.print("10:00-11:00 ");
    lcd.setCursor(12,3);
    print_color(10); // for 10:00-11:00
    lcd.setCursor(17,3);
    print_brightness(10); // for 10:00-11:00
    break;

    case 28:
    case 40:
    case 52:
    case 64:
    lcd.setCursor(19, 0);
    lcd.print(char_accept);
    break;

    case 29:
    case 41:
    case 53:
    case 65:
    break;

    case 30:
    case 42:
    case 54:
    case 66:
    lcd.setCursor(19, 0);
    lcd.print(' ');
    lcd.setCursor(19, 2);
    lcd.print(' ');
    lcd.setCursor(19, 1);
    lcd.print(char_arrow);
    break;

    case 31:
    case 43:
    case 55:
    case 67:
    lcd.setCursor(19, 1);
    lcd.print(char_accept);
    break;

    case 32:
    case 44:
    case 56:
    case 68:
    break;

    case 33:
    case 45:
    case 57:
    case 69:
    lcd.setCursor(19, 1);
    lcd.print(' ');
    lcd.setCursor(19, 3);
    lcd.print(' ');
    lcd.setCursor(19, 2);
    lcd.print(char_arrow);
    break;

    case 34: 
    case 46:
    case 58:
    case 70:
    lcd.setCursor(19, 2);
    lcd.print(char_accept);
    break;

    case 35:
    case 47:
    case 59:
    case 71:
    break;

    case 36:
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("07:00-08:00 "); 
    lcd.setCursor(12,0);
    print_color(7); // for 07:00-08:00
    lcd.setCursor(17,0);
    print_brightness(7); // for 07:00-08:00
    lcd.setCursor(19, 3);
    lcd.print(char_arrow);
    lcd.setCursor(0, 1);
    lcd.print("08:00-09:00 "); 
    lcd.setCursor(12,1); 
    print_color(8); // for 08:00-09:00
    lcd.setCursor(17,1);
    print_brightness(8); // for 08:00-09:00
    lcd.setCursor(0, 2);
    lcd.print("09:00-10:00 ");
    lcd.setCursor(12,2);
    print_color(9); // for 09:00-10:00
    lcd.setCursor(17,2);
    print_brightness(9); // for 09:00-10:00
    lcd.setCursor(0, 3);
    lcd.print("10:00-11:00 ");
    lcd.setCursor(12,3);
    print_color(10); // for 10:00-11:00
    lcd.setCursor(17,3);
    print_brightness(10); // for 10:00-11:00
    break;

    case 37:
    case 49:
    case 61:
    case 73:
    lcd.setCursor(19, 3);
    lcd.print(char_accept);
    break;

    case 38:
    case 50:
    case 62:
    case 74:
    break;

    case 39: // window 4
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("11:00-12:00 "); 
    lcd.setCursor(12,0);
    print_color(11); // for 11:00-12:00
    lcd.setCursor(17,0);
    print_brightness(11); // for 11:00-12:00
    lcd.setCursor(19, 0);
    lcd.print(char_arrow);
    lcd.setCursor(0, 1);
    lcd.print("12:00-13:00 "); 
    lcd.setCursor(12,1); 
    print_color(12); // for 12:00-13:00
    lcd.setCursor(17,1);
    print_brightness(12); // for 12:00-13:00
    lcd.setCursor(0, 2);
    lcd.print("13:00-14:00 ");
    lcd.setCursor(12,2);
    print_color(13); // for 13:00-14:00
    lcd.setCursor(17,2);
    print_brightness(13); // for 13:00-14:00
    lcd.setCursor(0, 3);
    lcd.print("14:00-15:00 ");
    lcd.setCursor(12,3);
    print_color(14); // for 14:00-15:00
    lcd.setCursor(17,3);
    print_brightness(14); // for 14:00-15:00
    break;

    case 48: 
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("11:00-12:00 "); 
    lcd.setCursor(12,0);
    print_color(11); // for 11:00-12:00
    lcd.setCursor(17,0);
    print_brightness(11); // for 11:00-12:00
    lcd.setCursor(19, 3);
    lcd.print(char_arrow);
    lcd.setCursor(0, 1);
    lcd.print("12:00-13:00 "); 
    lcd.setCursor(12,1); 
    print_color(12); // for 12:00-13:00
    lcd.setCursor(17,1);
    print_brightness(12); // for 12:00-13:00
    lcd.setCursor(0, 2);
    lcd.print("13:00-14:00 ");
    lcd.setCursor(12,2);
    print_color(13); // for 13:00-14:00
    lcd.setCursor(17,2);
    print_brightness(13); // for 13:00-14:00
    lcd.setCursor(0, 3);
    lcd.print("14:00-15:00 ");
    lcd.setCursor(12,3);
    print_color(14); // for 14:00-15:00
    lcd.setCursor(17,3);
    print_brightness(14); // for 14:00-15:00
    break;

    case 51: // window 5
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("15:00-16:00 "); 
    lcd.setCursor(12,0);
    print_color(15); // for 15:00-16:00
    lcd.setCursor(17,0);
    print_brightness(15); // 15:00-16:00
    lcd.setCursor(19, 0);
    lcd.print(char_arrow);
    lcd.setCursor(0, 1);
    lcd.print("16:00-17:00 "); 
    lcd.setCursor(12,1); 
    print_color(16); // for 16:00-17:00
    lcd.setCursor(17,1);
    print_brightness(16); // for 16:00-17:00
    lcd.setCursor(0, 2);
    lcd.print("17:00-18:00 ");
    lcd.setCursor(12,2);
    print_color(17); // for 17:00-18:00
    lcd.setCursor(17,2);
    print_brightness(17); // for 17:00-18:00
    lcd.setCursor(0, 3);
    lcd.print("18:00-19:00 ");
    lcd.setCursor(12,3);
    print_color(18); // for 18:00-19:00
    lcd.setCursor(17,3);
    print_brightness(18); // for 18:00-19:00
    break;

    case 60:
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("15:00-16:00 "); 
    lcd.setCursor(12,0);
    print_color(15); // for 15:00-16:00
    lcd.setCursor(17,0);
    print_brightness(15); // 15:00-16:00
    lcd.setCursor(19, 3);
    lcd.print(char_arrow);
    lcd.setCursor(0, 1);
    lcd.print("16:00-17:00 "); 
    lcd.setCursor(12,1); 
    print_color(16); // for 16:00-17:00
    lcd.setCursor(17,1);
    print_brightness(16); // for 16:00-17:00
    lcd.setCursor(0, 2);
    lcd.print("17:00-18:00 ");
    lcd.setCursor(12,2);
    print_color(17); // for 17:00-18:00
    lcd.setCursor(17,2);
    print_brightness(17); // for 17:00-18:00
    lcd.setCursor(0, 3);
    lcd.print("18:00-19:00 ");
    lcd.setCursor(12,3);
    print_color(18); // for 18:00-19:00
    lcd.setCursor(17,3);
    print_brightness(18); // for 18:00-19:00
    break;

    case 63: // window 6
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("19:00-20:00 "); 
    lcd.setCursor(12,0);
    print_color(19); // 19:00-20:00
    lcd.setCursor(17,0);
    print_brightness(19); // 19:00-20:00
    lcd.setCursor(19, 0);
    lcd.print(char_arrow);
    lcd.setCursor(0, 1);
    lcd.print("20:00-21:00 "); 
    lcd.setCursor(12,1); 
    print_color(20); // for 20:00-21:00
    lcd.setCursor(17,1);
    print_brightness(20); // for 20:00-21:00
    lcd.setCursor(0, 2);
    lcd.print("21:00-22:00 ");
    lcd.setCursor(12,2);
    print_color(21); // 21:00-22:00
    lcd.setCursor(17,2);
    print_brightness(21); // 21:00-22:00
    lcd.setCursor(0, 3);
    lcd.print("22:00-23:00 ");
    lcd.setCursor(12,3);
    print_color(22); // for 22:00-23:00
    lcd.setCursor(17,3);
    print_brightness(22); // for 22:00-23:00
    break;

    case 72:
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("19:00-20:00 "); 
    lcd.setCursor(12,0);
    print_color(19); // 19:00-20:00
    lcd.setCursor(17,0);
    print_brightness(19); // 19:00-20:00
    lcd.setCursor(19, 3);
    lcd.print(char_arrow);
    lcd.setCursor(0, 1);
    lcd.print("20:00-21:00 "); 
    lcd.setCursor(12,1); 
    print_color(20); // for 20:00-21:00
    lcd.setCursor(17,1);
    print_brightness(20); // for 20:00-21:00
    lcd.setCursor(0, 2);
    lcd.print("21:00-22:00 ");
    lcd.setCursor(12,2);
    print_color(21); // 21:00-22:00
    lcd.setCursor(17,2);
    print_brightness(21); // 21:00-22:00
    lcd.setCursor(0, 3);
    lcd.print("22:00-23:00 ");
    lcd.setCursor(12,3);
    print_color(22); // for 22:00-23:00
    lcd.setCursor(17,3);
    print_brightness(22); // for 22:00-23:00
    break;

    case 75: // window 7
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("23:00-00:00 "); 
    lcd.setCursor(12,0);
    print_color(23); // 23:00-00:00
    lcd.setCursor(17,0);
    print_brightness(23); // 23:00-00:00
    lcd.setCursor(19, 0);
    lcd.print(char_arrow);
    break;

    case 76:
    lcd.setCursor(19, 0);
    lcd.print(char_accept);
    break;

    case 77:
    break;

    default:
    break;
  }
}
