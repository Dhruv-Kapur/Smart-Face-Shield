
const int trigPin = 9;
const int echoPin = 10;

float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;

  if (distance > 1800) {
<<<<<<< HEAD
    Serial.print("okay");
  } else {
    Serial.print("too close");
=======
    Serial.print("You can come closer : ");
    Serial.println(distance);
  } else {
    Serial.print("Go back : ");
    Serial.println(distance);

>>>>>>> 370733919455269607a7a4a0e2585c344cf87f16
  }
  delay(500);
  
}
