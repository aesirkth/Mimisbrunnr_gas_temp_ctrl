#include "loading_screen.h"

void display_loading_screen(Adafruit_SSD1306 display, int delay_val) {
    // Draw bitmap on the screen
    display.drawBitmap(0, 0, image_data_aesir_logo_128x64, 128, 64, 1);
    display.display();
    delay(delay_val);
    display.invertDisplay(true);
    display.display();
    delay(delay_val);
    display.invertDisplay(false);
    display.clearDisplay();
  }
