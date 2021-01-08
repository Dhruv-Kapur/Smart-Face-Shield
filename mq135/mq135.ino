int aqipin = A3;

void setup() {
  pinMode(aqipin, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println(air_quality());
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
