#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int X=A0;
int Y=A1;
int button=3;
int cnt=0;
int limnhay=0;
void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  pinMode (X, INPUT);
  pinMode (Y, INPUT);
  pinMode (button, INPUT_PULLUP);
}

void loop() {
  cnt--;
  if(limnhay==3) limnhay=0;
  if(cnt<0) cnt=15;
  int triX=analogRead(X);
  int triY=analogRead(Y);
  int bamY=map(triY, 0, 1023, 0, 16);
  int b=digitalRead(button);
  int nhay;
  if(triX>500){
    nhay=0;
    limnhay++;
  }
  else nhay=1;
  if (limnhay>2){ 
    nhay=1;
    delay(100);
  }
  lcd.setCursor(3, nhay);
  lcd.print("#");
  delay(200);
  lcd.setCursor(cnt,1);
  lcd.print("M");
  delay(200);
  Serial.print(nhay);
  Serial.print(" ");
  Serial.println(triY);
  Serial.println(nhay);
  if(cnt==3 && nhay==1){
    lcd.clear();
    while(triY<1000){
      triY=analogRead(Y);
      lcd.setCursor(2,0);
      lcd.print("THUA ROAI :((");
      lcd.setCursor(4, 1);
      lcd.print("Gat trai");
    }
  }
  lcd.clear();
  delay(100);
}
