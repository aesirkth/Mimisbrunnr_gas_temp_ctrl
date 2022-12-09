#ifndef __LOADING_SCREEN_H__
#define __LOADING_SCREEN_H__

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "aesir_logo_128x64.h"

void display_loading_screen(Adafruit_SSD1306 display, int delay_val);

#endif //__LOADING_SCREEN_H__
