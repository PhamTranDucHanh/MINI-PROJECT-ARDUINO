#include <Wire.h>
#include <ThreeWire.h>
#include <LiquidCrystal_I2C.h>
#include <RtcDS1302.h>
ThreeWire myWire(7, 6, 8); //DAT, CLK, RST;
LiquidCrystal_I2C lcd(0x27, 16, 2);
RtcDS1302<ThreeWire> Rtc(myWire);

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  Rtc.Begin();
  RtcDateTime currentTime=RtcDateTime(__DATE__, __TIME__); 
  Rtc.SetDateTime(currentTime);
}
void loop() {
  RtcDateTime now = Rtc.GetDateTime();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Date: ");
  lcd.print(now.Day());
  lcd.print("/");
  lcd.print(now.Month());
  lcd.print("/");
  lcd.print(now.Year());

  lcd.setCursor(0, 1);
  lcd.print("Time: ");
  lcd.print(now.Hour());
  lcd.print(":");
  lcd.print(now.Minute());
  lcd.print(":");
  lcd.print(now.Second());
//  lcd.setCursor(6, 0);
//  lcd.print("DHanh");
//  lcd.setCursor(1, 1);
//  lcd.print("iuu Tnhu nhiu");
//  lcd.scrollDisplayLeft();
//  delay(1000);
}
