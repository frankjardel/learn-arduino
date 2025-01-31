int led = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  
  if (led == 8 && led == 16 / 2 || led == 4 * 2 && led != 0) {
    digitalWrite(led, HIGH);
  }

  delay(3000);

  int ternario = led > 0 ? 8 : 4; // condition ? first_option : second_option

  if (ternario) {
    int count = 0;
    while (count <= 10) {
      digitalWrite(led, HIGH);
      delay(500);
      digitalWrite(led, LOW);
      delay(500);
      count++;
      Serial.println(count);
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
