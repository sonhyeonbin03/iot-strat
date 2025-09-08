#define LED1_PIN 14
#define LED2_PIN 12
#define LDR_PIN 34   // 조도센서 아날로그 입력

int lightThreshold = 0;  //  LED 켜짐 기준값, 환경에 맞게 조정

void setup() {
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);

  // 시리얼 모니터 초기화
  Serial.begin(115200); 
  Serial.println("LDR LED 제어 시작");
}

void loop() {
  // LDR 값 읽기 (0 ~ 4095)
  int lightValue = analogRead(LDR_PIN);

  // 시리얼 모니터 출력
  Serial.println(lightValue);

  // LED 제어
  if (lightValue <= lightThreshold) {
    // 어두우면 LED 켜기
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, HIGH);
  } else {
    // 밝으면 LED 끄기
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
  }

  delay(100); // 센서 읽기 간격
}
