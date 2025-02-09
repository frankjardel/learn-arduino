int button = 7;
int led = 13;
int myVector[11] = {0,1,2,3,4,5,6,7,8,9,10};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  
  for (int i = 0; i < 10; i++) {
    Serial.println(myVector[i]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int state = digitalRead(button);
  digitalWrite(led, state);
  Serial.println(millis()); // time release?
}
