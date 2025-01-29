int pinLed[3] = {8,9,10}; 

void setup() {
  // put your setup code here, to run once:
  
  for (int x = 0; x <= sizeof(pinLed); x += 1) {
    pinMode(pinLed[x], OUTPUT);
  };
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int x = 0; x <= sizeof(pinLed); x++) {
    delay(250);
    digitalWrite(pinLed[x], HIGH);
    delay(250);
    digitalWrite(pinLed[x], LOW);
  };
}
