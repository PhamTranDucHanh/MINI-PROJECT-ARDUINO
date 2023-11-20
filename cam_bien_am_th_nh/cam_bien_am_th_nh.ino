const int trigPin = 9;  // Chân kích hoạt cảm biến
const int echoPin = 10; // Chân đo thời gian trả về

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance_cm;

  // Gửi xung kích hoạt
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Đọc thời gian trả về từ cảm biến
  duration = pulseIn(echoPin, HIGH);

  // Chuyển đổi thời gian thành khoảng cách
  distance_cm = duration / 29.1 / 2;

  // In ra Serial Monitor
  Serial.print("Khoang cach: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(1000); // Đợi 1 giây trước khi đo lại
}
