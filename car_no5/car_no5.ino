#include "carMazeOfOz.h"

const byte trig = 8;
carMazeOfOz car;

volatile float speedValueLeft, speedValueRight;
volatile float speedValueLeft_SAMPLE[11], speedValueRight_SAMPLE[11];
volatile unsigned long timerPoint = 0, currentEncoderLeft = 0, currentEncoderRight = 0;

// Your variables is in the area below
//--------------------------------------------------//





//--------------------------------------------------//

void setup() {
  Serial.begin(9600);
  car.setPin();
  car.setInterrupt();
  attachInterrupt(LOW, ENC_LEFT_ISR, RISING);
  attachInterrupt(HIGH, ENC_RIGHT_ISR, RISING);
}

void ENC_LEFT_ISR() {
  static byte i = 0;
  speedValueLeft_SAMPLE[10] -= speedValueLeft_SAMPLE[i];
  speedValueLeft_SAMPLE[i] = (COUNTER_TIMER - currentEncoderLeft + TIMER1_STEP_CYCLE) % TIMER1_STEP_CYCLE;
  speedValueLeft_SAMPLE[10] += speedValueLeft_SAMPLE[i];
  speedValueLeft = PERIMETER_ / (speedValueLeft_SAMPLE[10] / 10);
  car.setSpeedLeft(speedValueLeft);
  i = (i + 1) % 10;
  currentEncoderLeft = COUNTER_TIMER;
}

void ENC_RIGHT_ISR() {
  static byte i = 0;
  speedValueRight_SAMPLE[10] -= speedValueRight_SAMPLE[i];
  speedValueRight_SAMPLE[i] = (COUNTER_TIMER - currentEncoderRight + TIMER1_STEP_CYCLE) % TIMER1_STEP_CYCLE;
  speedValueRight_SAMPLE[10] += speedValueRight_SAMPLE[i];
  speedValueRight = PERIMETER_ / (speedValueRight_SAMPLE[10] / 10);
  car.setSpeedRight(speedValueRight);
  i = (i + 1) % 10;
  currentEncoderRight = COUNTER_TIMER;
}
void reTrai(int x)
{
  car.setMotorRight(245, FORWARD);
  car.setMotorLeft(245,BACKWARD);
  delay(x);
}
void rePhai(int x)
{
  car.setMotorRight(245, BACKWARD);
  car.setMotorLeft(245,FORWARD);
  delay(x);
}
void quayDau(int x)
{
  car.setMotorRight(245, FORWARD);
  car.setMotorLeft(245,BACKWARD);
  delay(x);
}
void diThang()
{
  car.setMotorRight(110, FORWARD);
  car.setMotorLeft(110,FORWARD);
}
void diThang1(int x)
{
  car.setMotorRight(110, FORWARD);
  car.setMotorLeft(110,FORWARD);
  delay(x);
}

// Your functions is in the area below
//--------------------------------------------------//





//--------------------------------------------------//

void loop() {
  digitalWrite(trig, LOW);
  car.setSpeedLeft(speedValueLeft);
  car.setSpeedRight(speedValueRight);
  car.configureSpeed(speedValueLeft, speedValueRight);
  
  // Your code is in the area below
  //--------------------------------------------------//
  //-----Example code-----//
  // if (car.getDistanceHead() < 50) {
  //   if (car.getDistanceHead() < 20) {
  //     car.setMotorLeft(MAX_PWM, BACKWARD);
  //     car.setMotorRight(MAX_PWM, FORWARD);
  //   } else {
  //     car.setMotorLeft(150, FORWARD);
  //     car.setMotorRight(150, FORWARD);
  //   }
  // } else {
  //   car.setMotorLeft(200, FORWARD);
  //   car.setMotorRight(200, FORWARD);
  // }
  
  // Use Serial Monitor or Plotter in Arduino IDE to display the values on the screen
   Serial.print(car.getDistanceHead());
   Serial.print(" ");
   Serial.print(car.getSpeedLeft());
   Serial.print(" ");
   Serial.println(car.getSpeedRight());
  // Thuat toan quay dau
  float truoc=car.getDistanceHead();
  float trai=car.getDistanceLeft();
  float phai=car.getDistanceRight();
  float speed1=car.getSpeedLeft();
  float speed2=car.getSpeedRight();
  if (phai<5)
  {
    reTrai(20);
  }
  else if (trai<5)
  {
    rePhai(20);
  }
  if (phai>15)
  {
    rePhai(120);
    diThang1(1000);
  }
  else if (truoc>10)
  {
    diThang();
  }
  else if (trai>15)
  {
    reTrai(100);
  }
  else
  {
    reTrai(100);
  }

  //Serial.println(car.getDistanceHead());


 

  
  
  

  
  
  
  
  
  //--------------------------------------------------//
}
