void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(10, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  char info = Serial.read();

  if (info == 'l') {
    digitalWrite(10, LOW);
    digitalWrite(9, HIGH);
  };

  if (info == 'd') {
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
  };
}
