#include <Arduino.h>
#include "Inkplate.h"
#include "driver/rtc_io.h"

Inkplate display(INKPLATE_1BIT);

void setup() {
  Wire.begin();
  Serial.begin(115200);

  display.draw_mode_on();
  display.begin();
  display.clean();
  for (int i = 0; i < 8; i++) {
    display.setTextColor(i, 8 - i);
    display.setTextSize(i);
    display.setCursor(0, (600 / 8) * i);
    display.print("Hello World");
  }
  display.display();
  display.draw_mode_off();
  esp_sleep_enable_timer_wakeup(60 * 1000 * 1000);
  rtc_gpio_isolate(GPIO_NUM_12);
  esp_deep_sleep_start();
}

void loop() {}