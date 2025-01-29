int yellowLed = 8;
int greenLed = 9;
int redLed = 10;
char value = '8';

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    if (Serial.available()) {
      value = Serial.read();
    }
  
  switch (value) {
    case '8':
      digitalWrite(yellowLed, HIGH);
      break;
    case '9':
      digitalWrite(greenLed, HIGH);
      break;
    case '1':
      digitalWrite(redLed, HIGH);
      break;
    default:
      digitalWrite(yellowLed, LOW);
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, LOW);
      break;
  }
  Serial.println(value);
}
