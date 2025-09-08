const int buttonPin = 27;
const int ledPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  
  // 버튼이 눌리지 않았을 때 (상태가 HIGH일 때) LED를 켭니다
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.println("버튼이 눌리지 않았습니다. LED ON");
  } else {
    // 버튼이 눌렸을 때 (상태가 LOW일 때) LED를 끕니다
    digitalWrite(ledPin, LOW);
    Serial.println("버튼이 눌렸습니다! LED OFF");
  }

  delay(10);
}
