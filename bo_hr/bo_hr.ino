#include <SoftwareSerial.h>

int mystr;
int numbers = 0;
int bo;
int hr;

SoftwareSerial nano(6, 7); // RX | TX 
int incomingByte;
void setup() {
  // put your setup code here, to run once:
  nano.begin(9600);
  Serial.begin(9600);
}

void loop() {
  while(numbers < 2) {
    if (nano.available() > 0 ) {
      mystr = nano.read();
      Serial.println(mystr);
      if(numbers == 0){
        bo = mystr;
      }
      if(numbers == 1){
        hr = mystr;
      }
      numbers++;
    }
  }
  Serial.println(bo);
  Serial.println(hr);
  while(1);
}
