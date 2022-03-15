#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>
#include <Servo.h>

int CE_PIN = 8;
int CSN_PIN = 10;

RF24 Radio (CE_PIN, CSN_PIN);

const byte address[6] = "00001";

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int i = 0;

String rxd  = "";

void setup() {
  Serial.begin(9600);
  Serial.println("started!");
  Radio.begin();
  Radio.openReadingPipe(0, address);
  Radio.setPALevel(RF24_PA_MIN);
  Radio.startListening();
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
}

void loop() {
  if (Radio.available()) {
    char text[32] = "";
    Radio.read(&text, sizeof(text));
    rxd = String(text);
    if (rxd == "M1") {
      for (i = 0; i < 45; i++) {
        servo1.write(i);
        delay(10);
      }
    }
  }
}
