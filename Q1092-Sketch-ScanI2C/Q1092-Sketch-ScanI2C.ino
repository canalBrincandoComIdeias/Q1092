#include <Wire.h>

void setup() {
  Serial.begin(9600);
  while (!Serial);  // Aguarda até que a porta serial esteja pronta
  
  Wire.begin();

  Serial.println("\nEscaneando endereços I2C...");
  scanI2C();
}

void loop() {
  delay(5000);  // Aguarda 5 segundos entre cada novo escaneamento
  Serial.println("\nEscaneando endereços I2C novamente...");
  scanI2C();
}

void scanI2C() {
  byte error, address;
  int deviceCount = 0;

  for(address = 1; address < 127; address++ ) {
    // O endereço 0 é reservado para o próprio Arduino
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("Dispositivo encontrado no endereço 0x");
      if (address<16)
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println();
      deviceCount++;
    }
    else if (error==4) {
      Serial.print("Erro desconhecido no endereço 0x");
      if (address<16)
        Serial.print("0");
      Serial.println(address,HEX);
    }
  }
  
  if (deviceCount == 0) {
    Serial.println("Nenhum dispositivo encontrado.");
  } else {
    Serial.print("Total de dispositivos encontrados: ");
    Serial.println(deviceCount);
  }
}
