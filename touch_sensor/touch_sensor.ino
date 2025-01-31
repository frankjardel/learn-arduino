int touch_sensor = 7;
struct touch { 
   byte wasPressed = LOW; 
   byte isPressed = LOW; 
}; 
touch touch;

int led = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(touch_sensor, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  touch.isPressed = isTouchPressed(touch_sensor);
  
  if (touch.wasPressed != touch.isPressed) { 
    Serial.println("Touch pressed"); 
    digitalWrite(led, HIGH);
  } else {
    delay(250);
    digitalWrite(led, LOW);
  }
  touch.wasPressed = touch.isPressed;
}

bool isTouchPressed(int pin) { 
   return digitalRead(pin) == HIGH; 
} 
