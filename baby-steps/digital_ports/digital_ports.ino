void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(7, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    int stateButton;
    stateButton = digitalRead(7);
  
    //Serial.write(stateButton);
    Serial.println(stateButton);
  
    digitalWrite(10, stateButton);
    digitalWrite(9, !stateButton);
    delay(500);
  } else {
    Serial.println(Serial.available());
  }
}
