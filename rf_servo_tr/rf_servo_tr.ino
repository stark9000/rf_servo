#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>

int CE_PIN = 9;
int CSN_PIN = 10;

RF24 Radio (CE_PIN, CSN_PIN);

const byte address[6] = "00001";

int BTN_1 = A0;
int BTN_2 = A1;
int BTN_3 = A2;
int BTN_4 = A3;


void setup() {
  Serial.begin(9600);
  Serial.println("started!");
  Radio.begin();
  Radio.openWritingPipe(address);
  Radio.setPALevel(RF24_PA_MIN);
  Radio.stopListening();

  pinMode(BTN_1, INPUT);
  pinMode(BTN_2, INPUT);
  pinMode(BTN_3, INPUT);
  pinMode(BTN_4, INPUT);
}

void loop() {
  if (digitalRead(BTN_1)) {
    Serial.println("buton 1 pressed.");
    const char text[] = "M1";
    Radio.write(&text, sizeof(text));
    delay(50);
  }

  if (digitalRead(BTN_2)) {
    Serial.println("buton 2 pressed.");
    const char text[] = "M2";
    Radio.write(&text, sizeof(text));
    delay(50);
  }

  if (digitalRead(BTN_3)) {
    Serial.println("buton 3 pressed.");
    const char text[] = "M3";
    Radio.write(&text, sizeof(text));
    delay(50);
  }

  if (digitalRead(BTN_4)) {
    Serial.println("buton 4 pressed.");
    const char text[] = "M4";
    Radio.write(&text, sizeof(text));
    delay(50);
  }


  if (digitalRead(BTN_1) && digitalRead(BTN_4) ) {
    Serial.println("reset pressed.");
    const char text[] = "M5";
    Radio.write(&text, sizeof(text));
    delay(50);
  }

}
