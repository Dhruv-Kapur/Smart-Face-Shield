int button_pin = 13;
void setup() {
  // put your setup code here, to run once:
  pinMode(button_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(button_pin));
  delay(1000);
}
