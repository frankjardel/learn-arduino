int redLed = 10;
int redGreen = 9;
int count = 0;

char info;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redLed, OUTPUT);
  pinMode(redGreen, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (count <= 10) {
    digitalWrite(redLed, HIGH);
    delay(1000);
    
    count++;
    Serial.println(count);
    Serial.write(count);

    digitalWrite(redLed, LOW);
    delay(1000);
  }

  while (info != 'p') {
    digitalWrite(redGreen, HIGH);
    delay(100);
    digitalWrite(redGreen, LOW);
    delay(100);

    if (Serial.available()) {
      info = Serial.read();
    }
  }
}
