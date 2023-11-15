#include <LiquidCrystal_I2C.h>;
#include <DHT.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int DHTPIN=5;
const int DHTTYPE=DHT11;
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.init();
  lcd.backlight();
}
void loop() {
  float humid= dht.readHumidity();
  float celsi=dht.readTemperature();
  if (isnan(humid) || isnan(celsi)) Serial.println("KHONG CO TIN HIEU");
  else{
    Serial.print("Do am: ");
    Serial.print(humid);
    Serial.print("% | ");
    Serial.print("Nhiet do la: ");
    Serial.print(celsi);
    Serial.println(" C ");
  }
  lcd.setCursor(0, 0);
  lcd.print("Do am: ");
  lcd.print(humid);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print("Nhiet do la:");
  lcd.print(celsi);
  lcd.print(" C ");
  delay(500);
}
