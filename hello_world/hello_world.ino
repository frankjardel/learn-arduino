void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(10, OUTPUT); // pino 10 na placa
  Serial.println("Hello World");
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(10, HIGH);
  delay(1000);
  digitalWrite(10, LOW);
  delay(1000);
}
