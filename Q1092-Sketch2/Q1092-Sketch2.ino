//Definição do uso dos pinos do Arduino
#define pinSensor 14
#define pinRele 13

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);

int estadoSensor;
int estadoSensorAnt;

//Configuração do projeto no Arduino
void setup() {
  lcd.init();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Iniciando...");

  //Configura o estado das portas do Arduino
  pinMode(pinSensor, INPUT);
  pinMode(pinRele, OUTPUT);

  //Força Atualização do Display na Primeira Execução
  estadoSensorAnt = !digitalRead(pinSensor);
}

void loop() {

  estadoSensor = digitalRead(pinSensor);

  if (estadoSensor) {
    if (estadoSensor != estadoSensorAnt) {
      lcd.clear();
      lcd.backlight();
      lcd.setCursor(1, 0);
      lcd.print("Estado: Normal");
      lcd.setCursor(1, 1);
      lcd.print("Sensor: Ativo");
      digitalWrite(pinRele, HIGH);
    } else {
      if (bitRead(millis(), 10)) {
        lcd.setCursor(15, 1);
        lcd.print("*");
      } else {
        lcd.setCursor(15, 1);
        lcd.print(" ");
      }
    }
  } else {
    if (estadoSensor != estadoSensorAnt) {
      lcd.clear();
      lcd.setCursor(3, 0);
      lcd.print("ATENCAO!!");
      lcd.setCursor(1, 1);
      lcd.print("FOGO DETECTADO");
      digitalWrite(pinRele, LOW);
    } else {
      if (bitRead(millis(), 9)) {
        lcd.backlight();
      } else {
        lcd.noBacklight();
      }
    }
  }

  estadoSensorAnt = estadoSensor;
}