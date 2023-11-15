#include <Servo.h>
Servo test1;
int analog=A0;
int goc;
void setup() {
  test1.attach(3);
  Serial.begin(9600);
}
void loop() {
//  for (int i=0; i<180; i++){
//    test1.write(i);
//    delay(50);
//  }
//  for (int j=180; j>0; j--){
//    test1.write(j);
//    delay(50);
//  }
//    int doctro=analogRead(analog);
//    goc=map(doctro, 0, 1023, 0, 180);
//    test1.write(goc);
//    Serial.println(doctro);
  test1.write(0);
  delay(1000);
  test1.write(180);
  delay(1000);
  
}
