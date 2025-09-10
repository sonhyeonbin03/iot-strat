#define LED_PIN 18    // LED 연결된 GPIO 5번 사용

void setup() {
  pinMode(LED_PIN, OUTPUT);   // LED 핀을 출력으로 설정
}

void loop() {
  digitalWrite(LED_PIN, HIGH);  // LED 켜기
  delay(1000);                  // 1초 대기
  digitalWrite(LED_PIN, LOW);   // LED 끄기
  delay(1000);                  // 1초 대기
}
