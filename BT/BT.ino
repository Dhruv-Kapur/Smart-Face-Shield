
#include <SoftwareSerial.h> 
SoftwareSerial BT(3, 4); // RX | TX 

void setup() 
{   
 Serial.begin(9600); 
 BT.begin(9600); 
 Serial.println("Ready to connect\nDefualt password is 1234 or 000"); 
} 
void loop() 
{ 
  //String nums = String(random(0,999)) + "," + String(random(0,999))+ "," + String(random(0,999))+ "," + String(random(0,999));
  String nums = "1,2,3,4" ;
  BT.println(nums);
  Serial.println(nums);
  delay(500);
}  
