#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);
LiquidCrystal_I2C lcd2(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.init();
  lcd.backlight();

  lcd2.init();
  lcd2.init();
  lcd2.backlight();

  byte brincando1[8] = {
    0b00000,
    0b00001,
    0b00010,
    0b00100,
    0b01000,
    0b01010,
    0b10000,
    0b10000
  };

  byte brincando2[8] = {
    0b11111,
    0b00000,
    0b00100,
    0b00000,
    0b01110,
    0b10001,
    0b10001,
    0b10001
  };

  byte brincando3[8] = {
    0b00000,
    0b10000,
    0b01000,
    0b00100,
    0b00010,
    0b01010,
    0b00001,
    0b00001
  };

  byte brincando4[8] = {
    0b10000,
    0b10000,
    0b01000,
    0b01000,
    0b00100,
    0b00010,
    0b00001,
    0b00000
  };

  byte brincando5[8] = {
    0b10101,
    0b11111,
    0b11111,
    0b01010,
    0b01010,
    0b00010,
    0b00000,
    0b11111
  };

  byte brincando6[8] = {
    0b00001,
    0b00001,
    0b00010,
    0b00010,
    0b00100,

    0b01000,
    0b10000,
    0b00000
  };

  byte heart[8] = {
    0b00000,
    0b01010,
    0b11111,
    0b11111,
    0b01110,
    0b00100,
    0b00000,
    0b00000
  };

  lcd.createChar(0, brincando1);  //<memoria 0-7>, <mapa de char>
  lcd.createChar(1, brincando2);
  lcd.createChar(2, brincando3);
  lcd.createChar(3, brincando4);
  lcd.createChar(4, brincando5);
  lcd.createChar(5, brincando6);
  lcd.createChar(6, heart);

  lcd.setCursor(0, 0);
  lcd.write(byte(0));
  lcd.write(byte(1));
  lcd.write(byte(2));
  lcd.setCursor(0, 1);
  lcd.write(byte(3));
  lcd.write(byte(4));
  lcd.write(byte(5));


  lcd.setCursor(4, 0);
  lcd.print("brincando");

  lcd.setCursor(6, 1);
  lcd.print("com ideias");

  lcd.setCursor(15, 0);
  lcd.write(byte(6));

  //Inicio
  //#include <LiquidCrystal_I2C.h>
  //LiquidCrystal_I2C lcd(0x3F, 16, 2);
  //lcd.init();

  //Texto
  //lcd.clear();
  //lcd.print();
  //lcd.println();
  //lcd.createChar(<memoria 0-7>, <array[8] de byte>);
  //lcd.write(byte(<memoria>));

  //Geral
  //lcd.noDisplay();
  //lcd.display();
  //lcd.backlight();     lcd.setBacklight(True);
  //lcd.noBacklight();   lcd.setBacklight(False);

  //Cursor
  //lcd.home();
  //lcd.setCursor(<coluna>, <linha>);
  //lcd.cursor();    lcd.cursor_on();
  //lcd.noCursor();  lcd.cursor_off();
  //lcd.blink();     lcd.blink_on();
  //lcd.noBlink();   lcd.blink_off();

  lcd2.clear();
  lcd2.home();
  lcd2.blink();
}


void loop() {

  /*
  if (bitRead(millis(), 10)) {
    lcd.noBacklight();
  } else {
    lcd.backlight();
  }
  */
}
