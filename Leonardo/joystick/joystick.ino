// https://docs.arduino.cc/language-reference/en/functions/usb/Keyboard/keyboardModifiers/

#include <Keyboard.h>
#include <Mouse.h>

const int button = 2;

// Joystick
const int R3 = 3;
const int pinX = A0, pinY = A1, pinZ = A2;

void setup() {
  pinMode(button, INPUT);
  pinMode(R3, INPUT);
  
  Keyboard.begin();
  Mouse.begin();
  
  Serial.begin(9600);
  //while (!Serial);
  
  delay(5000);
  Serial.println("loaded..");
}

void loop() {
  if (digitalRead(button) == 1) {
    Keyboard.press(' ');
  } else {
    Keyboard.release(' ');
  }

  // Joystick
  if (digitalRead(R3) == 1) {
    Serial.println("R3 Pressed");
    //Keyboard.press('r');
  } else {
    //Keyboard.release('r');
  }
 
  int x = analogRead(pinX);
  int y = analogRead(pinY);
  int z = analogRead(pinZ);

  if (x <= 100) {
    Serial.println("x <= 100");
    Keyboard.press('a');
  } else {
    Keyboard.release('a');
  }
  if (x >= 1000) {
    Serial.println("x >= 1000");
    Keyboard.press('d');
  } else {
    Keyboard.release('d');
  }

  if (y <= 100) {
    Serial.println("y <= 100");
    Keyboard.press('w');
  } else {
    Keyboard.release('w');
  }
  if (y >= 1000) {
    Serial.println("y >= 1000");
    Keyboard.press('s');
  } else {
    Keyboard.release('s');
  }

  if (z == 0) {
    Serial.println("R3 Pressed");
  }
}
