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
  Radio.openWritingPipe(address);
  Radio.setPALevel(RF24_PA_MIN);
  Radio.stopListening();
}

void loop() {
  const char text[] = "Hello World";
  Radio.write(&text, sizeof(text));
  delay(1000);
}
