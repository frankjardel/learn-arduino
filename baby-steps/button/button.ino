int led = 13;
int button = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int state;
  state = digitalRead(button);
  Serial.println(state);
  if (state) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  };
}
