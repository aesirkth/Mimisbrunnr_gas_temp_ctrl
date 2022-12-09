#include "screen_UI.h"


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


bool statusBtnUp   = false;
bool statusBtnOk   = false;
bool statusBtnDown = false;
bool statusBtnBack = false;

bool statusAkhirBtnUp   = false;
bool statusAkhirBtnOk   = false;
bool statusAkhirBtnDown = false;
bool statusAkhirBtnBack = false;

bool UP   = false;
bool _OK   = false;
bool DOWN = false;
bool BACK = false;

int halaman  = 1;

bool config_menu_active = false;
int menu_index = 1;

void screen_UI_init() {

  // INIT Buttons
  pinMode(btnUp,   INPUT_PULLUP);
  pinMode(btnOk,   INPUT_PULLUP);
  pinMode(btnDown, INPUT_PULLUP);
  pinMode(btnBack, INPUT_PULLUP);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    // #TODO: More error warning, can bus or wifi
    for(;;); // Loop endless
  }

  delay(500); // Pause for 1 seconds

  display.clearDisplay(); // Clear the buffer.
}

void display_loading_screen(int delay_val) {
  display.clearDisplay();
  display.drawBitmap(0, 0, image_data_aesir_logo_128x64, 128, 64, 1); // Display logo
  display.display();
  delay(delay_val);
  display.invertDisplay(true); // Flicker for style
  display.display();
  delay(delay_val);
  display.invertDisplay(false); // Revert
  display.clearDisplay();
  display.display();
}

void reading_buttons() {
  statusBtnUp   = digitalRead(btnUp);
  statusBtnOk   = digitalRead(btnOk);
  statusBtnDown = digitalRead(btnDown);
  statusBtnBack = digitalRead(btnBack);
}

void display_telemetry() {
  display.clearDisplay();
}

class sub_item {
  public:
    std::string name;
    int index;

    sub_item(std::string Name, int Index)
    {
      name = Name;
      index = Index;
    }
};

class menu_item {
  public:
    char* name;
    int index;
    sub_item sub_item1;
    sub_item sub_item2;

    menu_item(char* Name, int Index, sub_item Sub_item1, sub_item Sub_item2) : sub_item1(Sub_item1), sub_item2(Sub_item2)
    {
      name = Name;
      index = Index;
      sub_item1 = Sub_item1;
      sub_item2 = Sub_item2;
    }
};

sub_item yes("Yes", 1);
sub_item no("No", 2);

menu_item item1("Menu item 1", 1, yes, no);
menu_item item2("Menu item 2", 2, yes, no);
menu_item item3("Menu item 3", 3, yes, no);
menu_item item4("Menu item 4", 4, yes, no);
menu_item item5("Menu item 5", 5, yes, no);

#define menu_array_length 5
menu_item menu_array[menu_array_length] = {item1, item2, item3, item4, item5};


bool activate_config_menu() { // To check if config menu should be activated
  if (!config_menu_active) {
    if(statusBtnOk) {
      config_menu_active = true;
    }
  }
  else {
    if(statusBtnBack) {
      config_menu_active = false;
    }
  }

  return config_menu_active;
}

void display_config_menu() {
  
  display.clearDisplay();

  if(!activate_config_menu()) { // Abort if config menu not active
    return;
  }

  display.setTextSize(1);
  display.setTextColor(WHITE);

  if(menu_index == menu_array_length+1) {
    menu_index = 0;
  }
  else if (menu_index == -1) {
    menu_index = menu_array_length;
  }

  int margin = 5;
  int arrow_location = menu_index * 10 + margin;
  for (int i = 0; i < 5; i++)
  {
    display.setCursor(10, margin);
    display.println(menu_array[i].name);
    margin += 10;
  }

  if(!digitalRead(btnUp)) {
    menu_index--;
    while(!digitalRead(btnUp));
  }
  if(!digitalRead(btnDown)) {
    menu_index++;
    while(!digitalRead(btnDown));
  }

  display.display();
}

  