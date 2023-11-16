#include <TimerOne.h>

// constants won't change. They're used here to 
//set pin numbers:

const int ledPin = 3; //the number of the IR LED pin
const int sensorPin = 11; //the number of the IR sensor pin
// variables will change; 
int lightLevel;     //variable for storing the sensor data

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensorPin, INPUT); //Input to Arduino
  pinMode(ledPin, OUTPUT); //Output from Arduino

  Timer1.initialize(26); //set a time of length 26 microseconds (or 38kHz)
  Timer1.attachInterrupt(callback); // attach the routine that will happen at the interrupt  

}

void loop() {
  // put your main code here, to run repeatedly:
  lightLevel = digitalRead(sensorPin);
  Serial.print("The IR Sensor is reading:");
  if (lightLevel == 0) {
    Serial.println("IR Communication ON"); 
  }
  else {
    Serial.println("IR Communication OFF"); 
  }
  delay(500); //delay to slow serial monitor output 
}
void callback() //time sensitive function to toggle the IR LED
{
  digitalWrite(ledPin, digitalRead(ledPin) ^ 1); //Toggle the IR LED
}
