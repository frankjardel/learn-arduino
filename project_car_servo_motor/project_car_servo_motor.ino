#include <Servo.h>
Servo myservo;
int position = 0;

const int pin7 = 7;
const int pin6 = 6;

void setup() {
  Serial.begin(9600);

  myservo.attach(5);

  pinMode(pin7, OUTPUT);
  pinMode(pin6, OUTPUT);

  digitalWrite(pin7, HIGH);
  digitalWrite(pin6, LOW);
  delay(2000);
  digitalWrite(pin7, LOW);
  digitalWrite(pin6, HIGH);
  delay(2000);
  digitalWrite(pin7, LOW);
  digitalWrite(pin6, LOW);
  delay(2000);

  myservo.write(180);
  delay(2000);  
  myservo.write(0);
  delay(2000); 
  myservo.write(90);
  position = 90;
}

void loop() {
  while (Serial.available()) {
    char command = Serial.read();

    // forward
    if (String(command) == "f") {
      digitalWrite(pin7, HIGH);
      digitalWrite(pin6, LOW);
    }
    // back
    if (String(command) == "b") {
      digitalWrite(pin7, LOW);
      digitalWrite(pin6, HIGH);
    }
    // stop
    if (String(command) == "s") {
      digitalWrite(pin7, LOW);
      digitalWrite(pin6, LOW);
    }

    if (String(command) == "w") {
      position = 90;
      myservo.write(90);
    }
    //left
    if (String(command) == "a") {
      if (position > 0) {
        position = position - 45;
        myservo.write(position);
      }
    }
    //right
    if (String(command) == "d") {
      if (position < 180) {
        position = position + 45;
        myservo.write(position);
      }
    }
  }
}
