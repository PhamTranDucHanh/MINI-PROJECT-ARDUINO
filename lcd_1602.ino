int red=4;
int green=3;
int blue=2;
void setup(){
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  Serial.begin(9600);
}
void loop(){
  int humid=analogRead(A0);
  Serial.println(humid);
  delay(100);
}
