#define LED_PIN1 14
#define LED_PIN2 26
#define BUTTON_PIN 27   // 버튼 핀 (원하는 GPIO 번호로 변경 가능)

// 상태 저장 변수
unsigned long previousMillis = 0;
const long interval = 3000;   // 3초 간격
int step = 0;                 // 현재 LED 단계
bool running = false;         // LED 동작 여부
int lastButtonState = HIGH;   // 버튼의 이전 상태

void setup() {
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // 풀업 모드 버튼 (눌렀을 때 LOW)
}

void loop() {
  unsigned long currentMillis = millis();

  // 버튼 읽기
  int buttonState = digitalRead(BUTTON_PIN);

  // 버튼 눌렀을 때 동작 토글 (debounce 포함)
  if (buttonState == LOW && lastButtonState == HIGH) {
    delay(50); // 간단한 디바운싱
    running = !running;  // 실행/정지 전환
  }
  lastButtonState = buttonState;

  if (running) {
    if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

      // 순서대로 LED 제어
      if (step == 0) {
        digitalWrite(LED_PIN1, HIGH);
        digitalWrite(LED_PIN2, LOW);
        step = 1;
      } else {
        digitalWrite(LED_PIN1, LOW);
        digitalWrite(LED_PIN2, HIGH);
        step = 0;
      }
    }
  } else {
    // 정지 상태면 LED 끄기
    digitalWrite(LED_PIN1, LOW);
    digitalWrite(LED_PIN2, LOW);
  }
}
