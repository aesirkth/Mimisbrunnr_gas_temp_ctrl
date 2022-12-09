#ifndef ___SCREEN_UI_H__
#define ___SCREEN_UI_H__

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <string.h>

#include "aesir_logo_128x64.h"
#include "aesir_logo_ae_56x46.h"


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define btnUp   12
#define btnOk   14
#define btnDown 27
#define btnBack 26

extern bool statusBtnUp  ;
extern bool statusBtnOk  ;
extern bool statusBtnDown;
extern bool statusBtnBack;

void screen_UI_init();

void display_loading_screen(int delay_val);

void display_telemetry();

void reading_buttons();

void display_config_menu();

#endif //___SCREEN_UI_H__
