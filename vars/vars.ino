int intervalPisca = 500;
float price = 1.5;
double double_value = 2.0;
char gender = 'm';
bool is_learning = true;
String username = "frankjardel";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);

  Serial.println(price);
  Serial.println(double_value);
  Serial.println(gender);
  Serial.println(is_learning);
  Serial.println(username);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  delay(intervalPisca);

  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);
  delay(intervalPisca);
}
