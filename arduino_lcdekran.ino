#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcdekranim(0x27, 16, 2);

void setup()
{
  Serial.begin(9600);
  lcdekranim.init();
  lcdekranim.backlight();
  lcdekranim.setCursor(0, 0);
  lcdekranim.print("Merhaba");
  delay(1000);
  lcdekranim.clear();
}

void loop()
{
  if (Serial.available())
  {
    String message = Serial.readString();
    lcdekranim.clear();
    lcdekranim.print(message);
    delay(2000);
    for (int i = 0; i < message.length() + 16; i++) {
      lcdekranim.scrollDisplayLeft();
      delay(500);
    }
  }
}
