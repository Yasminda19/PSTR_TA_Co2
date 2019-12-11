#include "WiFi.h"
#include <WiFiClient.h>;
#include <ThingSpeak.h>;

//MQ4 = Methane
//MQ9 = Carbon Monoxide
//MQ135 = Air Quality
//MQ7 = Smoke
 
const char* ssid = "Ayana"; //Your Network SSID
const char* password = "12345678"; //Your Network Password
int val;
int smokepin = A0; //LDR Pin Connected at A0 Pin
int methanepin = D4;
int copin = D5;
int airpin = D2;
int redLed = 12;
int greenLed = 11;
int buzzer = 10;
int sensorThres = 400;
WiFiClient client;
unsigned long myChannelNumber = 934949; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "FIU0027HEGOV9V0G"; //Your Write API Key
void setup()
 
{
 
Serial.begin(115200);
 
delay(10);
 
// Connect to WiFi network
 
WiFi.begin(ssid, password);
pinMode(CO2pin, INPUT); 
ThingSpeak.begin(client);
 
}
 
void loop(){
  int analogMQ7 = analogRead(smokepin);
  int analogMQ4 = analogRead(methanepin);
  int analogMQ9 = analogRead(copin);
  int analogMQ135 =  analogRead(airpin);
  
  Serial.print("Smoke: ");
  Serial.println(analogMQ7);
  Serial.print("Methane: ");
  Serial.println(analogMQ4);
  Serial.print("CO: ");
  Serial.println(analogMQ9);
  Serial.print("Air: ");
  Serial.println(analogMQ135);
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

  delay(1000);
  ThingSpeak.writeField(myChannelNumber, 1,analogMQ7, myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 2,analogMQ4, myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 3,analogMQ9, myWriteAPIKey);
  ThingSpeak.writeField(myChannelNumber, 4,analogMQ135, myWriteAPIKey);//Update in ThingSpeak
  delay(100);
 
}
