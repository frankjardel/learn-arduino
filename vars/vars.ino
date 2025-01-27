void setup() {
  // put your setup code here, to run once:
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int intervalPisca;
  intervalPisca = 500;

  
  
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  delay(intervalPisca);

  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
  delay(intervalPisca);
}
