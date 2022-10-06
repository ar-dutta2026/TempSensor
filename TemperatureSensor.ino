/* 
https://youtube.com/shorts/PP4d7iGK5cA?feature=share
Check out my execution of the Temperature Sensor Project using the Arduino Platform!
*/

#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11

LiquidCrystal_I2C lcd(0x3F, 16, 2);  
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  dht.begin();     
  lcd.init();      
  lcd.backlight(); 
}

void loop()
{
  delay(2000); 

  float humi  = dht.readHumidity();    
  float tempC = dht.readTemperature(); 

  lcd.clear();
  // check if any reads failed
  if (isnan(humi) || isnan(tempC)) {
    lcd.setCursor(0, 0);
    lcd.print("Failed");
  } else {
    lcd.setCursor(0, 0);  
    lcd.print("Temp: ");
    lcd.print(tempC);    
    lcd.print((char)223); 
    lcd.print("C");

    lcd.setCursor(0, 1);  
    lcd.print("Humi: ");
    lcd.print(humi);      
    lcd.print("%");
  }
}

