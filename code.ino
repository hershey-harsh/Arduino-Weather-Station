#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

int pinDHT11 = 5;
SimpleDHT11 dht11(pinDHT11);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
}

void loop() {

  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    return;
  }

    lcd.begin();
 
  lcd.backlight();
  lcd.print("Climates: "); lcd.print((int)(temperature * 1.8 + 29)); lcd.print((char)223); lcd.print("F");
  lcd.setCursor(0, 1);
  lcd.print("Moisture: ");
  lcd.print((int)humidity); lcd.print("%");
  delay(1000);
}
