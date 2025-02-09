int pinRed = 10;
int pinGreen = 9;
int pinYellow = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinYellow, OUTPUT);
  pinMode(pinGreen, OUTPUT);
  pinMode(pinRed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  char info = Serial.read();
  
  Serial.print("I received:");
  Serial.println(info);
  Serial.write(info);
  
  if (info == 'l') {
    digitalWrite(pinYellow, HIGH);
    digitalWrite(pinGreen, LOW);
    digitalWrite(pinRed, LOW);
    delay(3000);
    digitalWrite(pinYellow, LOW);
    digitalWrite(pinGreen, HIGH);
    digitalWrite(pinRed, LOW);
    delay(1500);
    digitalWrite(pinYellow, LOW);
    digitalWrite(pinGreen, LOW);
    digitalWrite(pinRed, HIGH);
    delay(3000);
  } else if (info == 'm') {
    digitalWrite(pinYellow, HIGH);
    digitalWrite(pinGreen, HIGH);
    digitalWrite(pinRed, HIGH);
  } else if (info == 'd') {
    digitalWrite(pinYellow, LOW);
    digitalWrite(pinGreen, LOW);
    digitalWrite(pinRed, LOW);
  };

  if (true) {
    
  } else {
    
  };
}
