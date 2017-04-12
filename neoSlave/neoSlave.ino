#include <Wire.h>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

int ledPin = 13;

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            10
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      6

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
String readString;
int sensPin = 12;
//int ledPin = 2;

const byte slaveId = 2;

void setup(){
  Wire.begin(slaveId); 
  Wire.onReceive(receiveEvent);
  
  pinMode(ledPin,OUTPUT);
  
  digitalWrite(ledPin,LOW);  
  
  
  Serial.begin(9600);
  pixels.setBrightness(255);
  pixels.begin(); // This initializes the NeoPixel library.  
}

void loop(){
}

void receiveEvent(int howMany){
//  Serial.println("FuckMyAssKnulllaMigIArshlet");  
  readString="";  
  while(Wire.available()){
    delay(3);
    char c = Wire.read();  
    readString = readString + c;
 //   Serial.println("2");
  }
 // if (readString.startsWith("D", 0)){
  neoPix();
 // }
  readString="";  
}

