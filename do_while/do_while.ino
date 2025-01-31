int button = 7;
int led = 13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  
  int count = 0;
  do {
    count++;
    Serial.println(count);
    if (count == 10) {
      Serial.println("i break");
      break;
    } else {
      Serial.println("continue...");
      continue;
    }
  } while (count <= 10);
}

void loop() {
  // put your main code here, to run repeatedly:
  int state;
  state = digitalRead(button);
  digitalWrite(led, state);
}
