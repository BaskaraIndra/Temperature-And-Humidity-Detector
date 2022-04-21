#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  //Change to 0x3f or 0x27 if not appear
#include <DHT.h>
DHT dht(2, DHT11); 

int powerPin = 3;    // For the instead VCC/5vOLT
 
void setup(){
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight(); 
  // make power pin as output
  pinMode(powerPin, OUTPUT);
  // Default value LOW
  digitalWrite(powerPin, LOW);
 Serial.begin(9600);
 dht.begin();
}
 
void loop(){
 digitalWrite(powerPin, HIGH);
  
 float Humidity = dht.readHumidity();
 float Temperature = dht.readTemperature();

 Serial.print("Humidity: ");
 Serial.print(Humidity);
 Serial.print(" ");
 Serial.print("Temp: ");
 Serial.println(Temperature);
 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Humidity: ");
  lcd.setCursor(11,0);
  lcd.print(Humidity);

  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  lcd.setCursor(5,1);
  lcd.print(Temperature);
  delay(1000);
}
