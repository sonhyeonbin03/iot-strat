#define LED_PIN1 14
#define LED_PIN2 26

// 이전 시간 기록
unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;

// 깜빡임 주기 (ms)
const long interval1 = 1000;  // LED1은 1초마다 깜빡임
const long interval2 = 2000;   // LED2는 2초마다 깜빡임

// LED 상태 저장
int ledState1 = LOW;
int ledState2 = LOW;

void setup() {
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();

  // LED1 제어
  if (currentMillis - previousMillis1 >= interval1) {
    previousMillis1 = currentMillis;
    ledState1 = !ledState1; // 상태 반전
    digitalWrite(LED_PIN1, ledState1);
  }

  // LED2 제어
  if (currentMillis - previousMillis2 >= interval2) {
    previousMillis2 = currentMillis;
    ledState2 = !ledState2; // 상태 반전
    digitalWrite(LED_PIN2, ledState2);
  }
}
