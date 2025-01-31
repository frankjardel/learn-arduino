void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  int n1 = 4;
  int n2 = 4;
  int total = sum(n1, n2);
  Serial.println(total);
  pinMode(total, OUTPUT);
  digitalWrite(total, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

}

int sum(int x, int y) {
  return x + y;
}

boolean readButton(int value) {
  return true
}
