// Joystick
const int L3 = 2;
const int pinX = A0, pinY = A1;

// CTRL Motor
const int pin10 = 10;
const int pin9 = 9;
// CTRL Servo
const int pin5 = 5;

#include <Servo.h>
Servo myservo;
int position;

void setup() {
  Serial.begin(9600);

  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT);
  pinMode(L3, INPUT_PULLUP);

  pinMode(pin10, OUTPUT);
  pinMode(pin9, OUTPUT);

  pinMode(pin5, OUTPUT);
  digitalWrite(pin5, HIGH);

  myservo.attach(7);

  delay(5000);
  Serial.println("loaded..");
}

void loop() {
  int x = analogRead(pinX);
  int y = analogRead(pinY);
  // Forward
  if (x <= 100) {
    digitalWrite(pin9, HIGH);
  } else {
    digitalWrite(pin9, LOW);
  }
  // Reverse
  if (x >= 1000) {
    digitalWrite(pin10, HIGH);
  } else {
    digitalWrite(pin10, LOW);
  }
  // right
  if (y <= 100) {
    for (position = 0; position <= 180; position += 1) {
      myservo.write(position);
      delay(10);
    };
  } else {
    digitalWrite(pin5, LOW);
  }
  // left
  if (y >= 1000) {
    
  } else {
    
  }

  if (digitalRead(L3) == 0) {
    digitalWrite(pin10, LOW);
    digitalWrite(pin9, LOW);
  }
}
