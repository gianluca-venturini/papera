#include "DigiKeyboard.h"

void setup() { 
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
  DigiKeyboard.print("terminal");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  delay(2000);
  DigiKeyboard.print("curl ");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() {
 /*empty*/
}
