#include <Wire.h>
#include <Adafruit_MLX90614.h>

//Variables
int aqipin = A0;
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
const int trigPin = 9;
const int echoPin = 10;
float duration, distance;


void setup() {
  // put your setup code here, to run once:
  pinMode(aqipin, INPUT);
  Serial.begin(9600);
  mlx.begin(); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600); 
}

void loop() {
  int aqi = air_quality();
  int temp = temperature();
  int us = ultra_sound();
  Serial.print(temp);
  Serial.print(",");
  Serial.print(aqi);
  Serial.print(",");
  Serial.print(us);

}

int air_quality(){
  int i = 0;
  int sum = 0;
  while (i < 5) {
    sum = sum + analogRead(aqipin);
    i++;
    delay(100); 
  }
  int average = sum/5 ;
  return average;
}

int temperature (){
  int i = 0;
  int sum = 0;
  while (i < 5) {
    sum = sum + mlx.readObjectTempC();
    i++;
    delay(100); 
  }
  int average = sum/5 ;
  return average;
}

int ultra_sound (){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;

  return distance ;
  /*
  if (distance > 1800) {
    Serial.println("OK");
  } else {
    Serial.println("TOO CLOSE");
  }
  */
}
