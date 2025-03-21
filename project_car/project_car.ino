// Joystick
const int L3 = 2;
const int pinX = A0, pinY = A1;

// CTRL Motor
const int pin10 = 10;
const int pin9 = 9;

const int pin6 = 6;
const int pin5 = 5;

int right = 100;
int left = 100;

void setup() {
  Serial.begin(9600);

  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT);
  pinMode(L3, INPUT_PULLUP);

  pinMode(pin10, OUTPUT);
  pinMode(pin9, OUTPUT);

  pinMode(pin6, OUTPUT);
  pinMode(pin5, OUTPUT);

  delay(5000);
  Serial.println("loaded..");
}

void loop() {
  int x = analogRead(pinX);
  int y = analogRead(pinY);

  if (x <= 100) {
    Serial.println("front");
    digitalWrite(pin10, HIGH);
    digitalWrite(pin5, HIGH);
  } else {
    digitalWrite(pin10, LOW);
    digitalWrite(pin5, LOW);
  }
  if (x >= 1000) {
    Serial.println("back");
    digitalWrite(pin9, HIGH);
    digitalWrite(pin6, HIGH);
  } else {
    digitalWrite(pin9, LOW);
    digitalWrite(pin6, LOW);
  }

  if (y <= 100) {
    Serial.println("left");
  } else {
    //Serial.println("y");
  }
  if (y >= 1000) {
    Serial.println("right");
  } else {
    //Serial.println("y");
  }

  if (digitalRead(L3) == 0) {
    Serial.println("L3 pressed");
  } else {
    //Serial.println("L3 unpressed");
  }
}
