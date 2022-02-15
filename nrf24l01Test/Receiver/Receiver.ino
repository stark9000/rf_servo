#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>

int CE_PIN = 9;
int CSN_PIN = 10;

RF24 Radio (CE_PIN, CSN_PIN);

const byte address[6] = "00001";
void setup() {
  Serial.begin(9600);
  Serial.println("started!");
  Radio.begin();
  Radio.openReadingPipe(0, address);
  Radio.setPALevel(RF24_PA_MIN);
  Radio.startListening();
}

void loop() {
  if (Radio.available()) {
    char text[32] = "";
    Radio.read(&text, sizeof(text));
    Serial.println(text);
  }
}
