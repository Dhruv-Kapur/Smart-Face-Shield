//Test for github
#include <Wire.h>
#include <Adafruit_MLX90614.h>

//Variables
int aqipin = A5;
Adafruit_MLX90614 mlx = Adafruit_MLX90614();


void setup() {
  // put your setup code here, to run once:
  pinMode(aqipin, INPUT);
  Serial.begin(9600);
  mlx.begin();  
}

void loop() {
  int aqi = air_quality();
  delay(500);
  int temp = temperature();
  //Serial.print();
  //Serial.print(",");
  Serial.println(aqi);
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
