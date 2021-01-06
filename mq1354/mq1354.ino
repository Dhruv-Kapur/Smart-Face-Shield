int smokeA0 = A5;
int addedone = 0 ;
int counter = 0 ;

void setup() {
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int percentage = (analogRead(smokeA0)/1024)*100;
 
  if (counter < 5 ){
    addedone = addedone + percentage ;
    counter ++;
  } 
  if (counter == 5 ) {
    Serial.println(addedone/5);
    counter = 0;
    addedone = 0;
  }
  
  delay(100);
  
}
