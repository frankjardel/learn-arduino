long number = 0;
int led = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  number = random(1, 100);
  randomSeed(number);

  Serial.print("Rambom: ");
  Serial.println(number);
  
  delay(100);
  
  if (number == led) {
    digitalWrite(led, HIGH);
  }
}
