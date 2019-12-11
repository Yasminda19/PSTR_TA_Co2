//#include <ESP8266WiFi.h>;
#include "WiFi.h"
#include <WiFiClient.h>;
 
#include <ThingSpeak.h>;
 
const char* ssid = "Ayana"; //Your Network SSID
const char* password = "12345678"; //Your Network Password
int val;
int CO2pin = A0; //LDR Pin Connected at A0 Pin
int redLed = 12;
int greenLed = 11;
int buzzer = 10;
int sensorThres = 400;
WiFiClient client;
unsigned long myChannelNumber = 924423; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "R4FGQN7W07UOKB3R"; //Your Write API Key
void setup()
 
{
 
Serial.begin(115200);
 
delay(10);
 
// Connect to WiFi network
 
WiFi.begin(ssid, password);
pinMode(CO2pin, INPUT); 
ThingSpeak.begin(client);
 
}
 
 
 
void loop()
 
{
  int analogSensor = analogRead(CO2pin);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    //tone(buzzer, 1000, 200);
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
   // noTone(buzzer);
  }
  delay(100);
 
  // val = analogRead(CO2pin); //Read Analog values and Store in val variable
 
  Serial.print(analogSensor); //Print on Serial Monitor
  delay(1000);
  ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey); //Update in ThingSpeak
  delay(100);
 
}
