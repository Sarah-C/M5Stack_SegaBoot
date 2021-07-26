// 203Kb SEGA boot screen with sound.

#include <M5Stack.h>
#include "sega_audio.h"
#include "sega_video205x70.h"

extern const unsigned char sega_audio[];
extern const uint16_t sega_video205x70[];

void startupLogo() {
  static uint8_t brightness, pre_brightness;
  uint32_t length = strlen((char*)sega_audio);
  M5.Lcd.setBrightness(0);
  M5.Lcd.clear(TFT_BLACK);
  M5.Lcd.drawBitmap(57, 75, 205, 70, (uint16_t *)sega_video205x70);
  for (int i = 0; i < length; i++) {
    dacWrite(SPEAKER_PIN, sega_audio[i] >> 2);
    delayMicroseconds(50);
    brightness = (i / 275); // 70,000 bytes / 254 = 275
    // Only change brightness if the integer brightness has changed. To keep audio same speed.
    if (pre_brightness != brightness) {
      pre_brightness = brightness;
      M5.Lcd.setBrightness(brightness);
    }
  }
  for (int i = 255; i >= 0; i--) {
    M5.Lcd.setBrightness(i);
    if (i <= 32) {
      dacWrite(SPEAKER_PIN, i);
    }
    delay(2);
  }
  M5.Lcd.fillScreen(BLACK);
  delay(800);
}

void setup()
{
  M5.begin();
  M5.Power.begin();
  startupLogo();
}

void loop() {

}
