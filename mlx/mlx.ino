#include <Wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  Serial.begin(9600);

  Serial.println("Adafruit MLX90614 test");  

  mlx.begin();  
}

void loop() {

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
