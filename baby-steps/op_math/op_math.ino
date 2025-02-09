int redLed = 10;
int greenLed = 9;
int yellowLed = 8;
int button = 7;

float n1 = 10;
float n2 = 2;
float res = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(button, INPUT);
  
  res = n1 + n2;
  Serial.println(String(n1) + " + " + String(n2) + " = " + String(res));

  if (int(res) % 2 == 0) {
    Serial.println(String(res) + " : is Pair");
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);
  } else {
    Serial.println(String(res) + " : is Odd");
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
  }

  delay(10000);

  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, LOW);
  // Operators
  // +, ++, +=, -, --, -=, *, *=, /, %, %=
}

void loop() {
  // put your main code here, to run repeatedly:
  int state;
  state = digitalRead(button);
  digitalWrite(redLed, HIGH);
}
