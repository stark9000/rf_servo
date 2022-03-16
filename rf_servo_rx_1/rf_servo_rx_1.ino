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

int a = 0;
int b = 0;
int c = 90;
int d = 90;

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
  servo1.write(a);
  servo2.write(b);
  servo3.write(c);
  servo4.write(d);
  delay(10);
}

void loop() {
  if (Radio.available()) {
    char text[32] = "";
    Radio.read(&text, sizeof(text));
    rxd = String(text);

    if (rxd == "M1") {
      servo1.write(a);
      delay(10);
      if (a < 45) {
        a++;
        delay(50);
      }
    }

    if (rxd == "M2") {
      servo2.write(b);
      delay(10);
      if (b < 45) {
        b++;
        delay(50);
      }
    }

    if (rxd == "M3") {
      servo3.write(c);
      delay(10);
      if (c > 45) {
        c--;
        delay(50);
      }
    }

    if (rxd == "M4") {
      servo4.write(d);
      delay(10);
      if (d > 45) {
        d--;
        delay(50);
      }
    }
    if (rxd == "M5") {
      a = 0;
      b = 0;
      c = 90;
      d = 90;
      servo1.write(a);
      servo2.write(b);
      servo3.write(c);
      servo4.write(d);
    }
  }
}
