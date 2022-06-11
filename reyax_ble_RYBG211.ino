
#include <SoftwareSerial.h>

#define rxPin 10
#define txPin 11
const int led1 = 4;
const int led2 = 5;
const int led3 = 6;
const int led4 = 7;
char data_in ;

// Set up a new SoftwareSerial object
SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);
  

void setup() {
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
   
    
    // Set the baud rate for the SoftwareSerial object
    mySerial.begin(9600);
    Serial.begin(9600);
}

void loop() {
  if (mySerial.available() > 0) {
    data_in = (char)mySerial.read();
    Serial.print(data_in);
  }
   
if (data_in == 'A') {
    digitalWrite(led1, LOW);
    delay(20);
   

  }
  
  if (data_in == 'a') {
    digitalWrite(led1, HIGH);
    delay(5);
   

  }

  if (data_in == 'B') {
    digitalWrite(led2, LOW);
    delay(20);
   

  }
  
  if (data_in == 'b') {
    digitalWrite(led2, HIGH);
    delay(5);
   

  }
  if (data_in == 'E') {
    digitalWrite(led3, LOW);
    delay(20);
   

  }
  
  if (data_in == 'e') {
    digitalWrite(led3, HIGH);
    delay(5);
   

  }
  if (data_in == 'D') {
    digitalWrite(led4, LOW);
    delay(20);
   

  }
  
  if (data_in == 'd') {
    digitalWrite(led4, HIGH);
    delay(5);
   

  }
}
