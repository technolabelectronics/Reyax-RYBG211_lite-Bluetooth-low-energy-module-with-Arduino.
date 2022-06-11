#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);


#define rxPin 10
#define txPin 11

char data_in ;

// Set up a new SoftwareSerial object
SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);
  

void setup() {
  

  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
    // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
 

   
    
    // Set the baud rate for the SoftwareSerial object
    mySerial.begin(9600);
    Serial.begin(9600);
}

void loop() {
  if (mySerial.available() > 0) {
    data_in = (char)mySerial.read();
    Serial.print(data_in);

    lcd.clear();
    lcd.print("Signal");
    lcd.setCursor(0,1);
    lcd.print("Received");
    delay(500);
   }

   else {
    lcd.clear();
    lcd.print("Signal");
    lcd.setCursor(0,1);
    lcd.print("lost");
    delay(500);
    
    
    
    }

}
