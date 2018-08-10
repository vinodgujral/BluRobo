#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); //TX, RX respetively
String readdata;

void setup() {
 BT.begin(9600);
 Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(7, OUTPUT);

}
//-----------------------------------------------------------------------// 
void loop() {
  while (BT.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = BT.read(); //Conduct a serial read
  readdata += c; //build the string- "forward", "reverse", "left" and "right"
  } 
  if (readdata.length() > 0) {
    Serial.println(readdata);

  if(readdata == "forward")
  {
    digitalWrite(13, HIGH);
    digitalWrite (12, LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(2,LOW);
    digitalWrite(7,LOW);
    delay(100);
  }

  else if(readdata == "reverse")
  {
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(6,HIGH);
    digitalWrite(2,LOW);
    digitalWrite(7,LOW);
    delay(100);
  }

  else if (readdata == "right")
  {
    digitalWrite (13,LOW);
    digitalWrite (12,HIGH);
    digitalWrite (5,HIGH);
    digitalWrite (6,LOW);
    digitalWrite(2,LOW);
    digitalWrite(7,LOW);
    delay (100);
   
  }

 else if ( readdata == "left")
 {
   digitalWrite (13, HIGH);
   digitalWrite (12, LOW);
   digitalWrite (5, LOW);
   digitalWrite (6, HIGH);
   digitalWrite(2,LOW);
   digitalWrite(7,LOW);
   delay (100);
 }

 else if (readdata == "stop")
 {
   digitalWrite (13, LOW);
   digitalWrite (12, LOW);
   digitalWrite (5, LOW);
   digitalWrite (6, LOW);
   digitalWrite(2,LOW);
   digitalWrite(7,LOW);
   delay (100);
 }


  else if (readdata == "open")
 {
   digitalWrite (13, LOW);
   digitalWrite (12, LOW);
   digitalWrite (5, LOW);
   digitalWrite (6, LOW);
   digitalWrite(2,LOW);
   digitalWrite(7,HIGH);
   delay (100);
 }

 else if (readdata == "close")
 {
   digitalWrite (13, LOW);
   digitalWrite (12, LOW);
   digitalWrite (5, LOW);
   digitalWrite (6, LOW);
   digitalWrite(2,HIGH);
   digitalWrite(7,LOW);
   delay (100);
 }


readdata="";}} //Reset the variable


