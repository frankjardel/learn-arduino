void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(millis()); // elapsed time
  delay(1000); // delay delay is always late, only use the internet on a scheduled date
}
