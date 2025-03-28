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

  if (digitalRead(L3) == 0) {
    // break
    digitalWrite(pin10, LOW);
    digitalWrite(pin5, LOW);
    digitalWrite(pin9, LOW);
    digitalWrite(pin6, LOW);
  } else {

     if (y < 512) {
        left  = 100;
        right = map(y, 511, 0, 100, 0); 
     } else {
        left  = map(y, 512, 1023, 100, 0);
        right = 100;       
     }

     if (x < 512) {
        int velocity = map(x, 511, 0, 0, 255);

        analogWrite(pin9, 0);
        analogWrite(pin10, velocity * right / 100);
     
        analogWrite(pin6, 0);
        analogWrite(pin5, velocity * left / 100); 
     } else {
        int velocity = map(x, 512, 1023, 0, 255);

        analogWrite(pin9, velocity * right / 100);
        analogWrite(pin10, 0);
     
        analogWrite(pin6, velocity * left / 100);
        analogWrite(pin5, 0);                         
     }
  }
}
