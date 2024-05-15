#include <IRremoteESP8266.h>
#include <IRsend.h>
IRsend irsend(12);

#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel button_led(1, 27, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  irsend.begin();

  button_led.setPixelColor(0, button_led.Color(0, 5, 0));
  button_led.show();
}

void loop() {
  int khz = 38;
  uint16_t buf[5];
  buf[0] = 450;
  buf[1] = 7500;
  buf[2] = 450;
  buf[3] = 7500;
  buf[4] = 450;

  irsend.sendRaw(buf, 5, khz);
  delay(100);
}