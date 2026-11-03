#include <Servo.h>
const int FSR_PIN = A0;
const int FSR_MIN = 20, FSR_MAX = 988;
Servo servo;
int prevA = 0;

void setup() {
  Serial.begin(115200);
  servo.attach(9);
}

void loop() {
  int v = analogRead(FSR_PIN);
  int a = constrain(map(v, FSR_MIN, FSR_MAX, 0, 180), 0, 180);
  if (abs(a - prevA) >= 3) {   // 3° 미만 변화는 무시 (떨림 방지)
    servo.write(a);
    prevA = a;
  }
  Serial.print("v:"); Serial.print(v);
  Serial.print(" a:"); Serial.println(a);
  delay(20);
}