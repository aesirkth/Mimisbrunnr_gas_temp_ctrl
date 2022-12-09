#include <Arduino.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "screen_UI.h"

 
void setup() {
  Serial.begin(115200);

  screen_UI_init();

  display_loading_screen(800);

  statusBtnOk = true;
}
 
void loop() {

  // reading_buttons();

  display_config_menu();
}
