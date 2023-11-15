void setup() {
  Serial.begin(9600);
}
void loop() {
  int vontage=analogRead(A0);
  Serial.println(vontage);
  delay(100);

}
