#include <Stepper.h>
Stepper dongco=Stepper(2048, 7, 9, 8, 10);
int analog=A0;
void setup() {
  Serial.begin(9600);
}

void loop() {
//  int tro=analogRead(analog);
//  int tocdo=map(tro, 0, 1023, 4, 18);
//  dongco.setSpeed(tocdo);
//  dongco.step(2048);
//  Serial.println(tocdo);
//  dongco.setSpeed(tocdo);
//  dongco.step(-2048);
    for (int i=0; i<=2048; i+=5){
      int tro=analogRead(analog);
      int tocdo=map(tro, 0, 1023, 8, 18);
      dongco.setSpeed(tocdo);
      if (tocdo<14) dongco.step(-i);
      else dongco.step(i);
      Serial.println(tocdo);
    }
}
