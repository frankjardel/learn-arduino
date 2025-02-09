#include <Keyboard.h>

const int button = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT);
  Keyboard.begin();
  Serial.begin(9600);
  //while (!Serial);
  delay(5000);
  Serial.println("loaded..");
}

void loop() {
  // put your main code here, to run repeatedly:
  int state = digitalRead(button);
  Serial.println(state);
  
  if (state == 1) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('s');
  } else {
    Keyboard.release(KEY_LEFT_CTRL);
    Keyboard.release('s');
  }
}
