//int ledRed = 2;
#define LED_RED 2
#define ONE_SECOND 1000

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_RED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(LED_RED);
  blinkLed(LED_RED);
}

void blinkLed(int color) {
  digitalWrite(color,HIGH);
  delay(ONE_SECOND);
  digitalWrite(color,LOW);
  delay(ONE_SECOND);
}
