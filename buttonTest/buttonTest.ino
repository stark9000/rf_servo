int BTN_1 = A0;
int BTN_2 = A1;
int BTN_3 = A2;
int BTN_4 = A3;

void setup() {
  Serial.begin(9600);
  pinMode(BTN_1, INPUT);
  pinMode(BTN_2, INPUT);
  pinMode(BTN_3, INPUT);
  pinMode(BTN_4, INPUT);
  Serial.println("buton test.");
}

void loop() {
  if (digitalRead(BTN_1)) {
    Serial.println("buton 1 pressed.");
    delay(50);
  }

  if (digitalRead(BTN_2)) {
    Serial.println("buton 2 pressed.");
    delay(50);
  }

  if (digitalRead(BTN_3)) {
    Serial.println("buton 3 pressed.");
    delay(50);
  }

  if (digitalRead(BTN_4)) {
    Serial.println("buton 4 pressed.");
    delay(50);
  }
}
