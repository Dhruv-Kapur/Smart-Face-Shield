#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#include <SoftwareSerial.h> 
SoftwareSerial BT(3, 4); // RX | TX 

//Variables
int aqipin = A0;
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
const int trigPin = 9;
const int echoPin = 10;
int button_pin = 13;
float duration, distance;

int aqi = 0 ;
int temp = 30 ;
int us = 200;

void setup() {
  // put your setup code here, to run once:
  pinMode(aqipin, INPUT);
  Serial.begin(9600);
  mlx.begin(); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(button_pin, INPUT);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();

  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(0, 10); 

  BT.begin(9600); 
}

void loop() {
  if (digitalRead(button_pin) == HIGH ) {
    aqi = air_quality();
    temp = temperature();
    BlueTooth(temp, aqi , 90, 95);
  }

  int us = ultra_sound();
  oled(temp, us, 92);
  Serial.println(us);
  delay(1000);

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
}

int oled (int mlx, int ultras, int bo) {
  display.clearDisplay(); // clear the buffer
  if ( mlx > 36 ) {
     display.setTextSize(3);
     display.println("FEVER");
  } else if ( ultras < 180) {
    display.setTextSize(3);
    display.println("6 FT");
  } else if (bo < 90) {
    display.setTextSize(3);
    display.println("LOW O2");
  } else {
    display.setTextSize(3);
    display.println("OKAY");
  }
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(0, 10); 
  display.display(); 

}

int BlueTooth (int temp_bt, int PPM_bt, int BO_bt, int HR_bt){
  int index = 0 ;
  while (index < 8){
   String nums = String(temp_bt) + "," + String(PPM_bt) + "," + String(BO_bt)+ "," + String(HR_bt);
   BT.println(nums);
   delay(500);
   index++ ; 
  }
}
