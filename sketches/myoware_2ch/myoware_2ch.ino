// 2채널 MyoWare ENV 관찰: A0 = 굴곡근(1), A1 = 신전근(2)
void setup() {
  Serial.begin(115200);
}

void loop() {
  analogRead(A0);            // 채널 전환 직후 첫 값은 버림
  int a0 = analogRead(A0);
  analogRead(A1);
  int a1 = analogRead(A1);

  Serial.print("flex:");  Serial.print(a0);
  Serial.print(",ext:");  Serial.println(a1);
  delay(10);                 // 약 100Hz
}