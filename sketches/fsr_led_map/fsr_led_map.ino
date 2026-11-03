const int FSR_PIN = A0;
const int LED_PIN = 3;
const int FSR_MIN = 20;   // 안 누를 때 잡음보다 약간 위
const int FSR_MAX = 988;  // 1부 실측 최대

void setup() {
  Serial.begin(9600);
}

void loop() {
  int v = analogRead(FSR_PIN);                     // 0~1023 (10비트 ADC)
  int b = map(v, FSR_MIN, FSR_MAX, 0, 255);        // 0~255 (8비트 PWM)로 변환
  b = constrain(b, 0, 255);                        // 범위를 벗어난 값 자르기
  analogWrite(LED_PIN, b);
  Serial.print(v); Serial.print('\t'); Serial.println(b);
  delay(20);
}