#include "SoftwareSerial.h"
SoftwareSerial serialToMCU(0, 1);


int val;
int CO2pin = A0; //LDR Pin Connected at A0 Pin
int redLed = 12;
int greenLed = 11;
int buzzer = 10;
int sensorThres = 400;

void setup() {
  Serial.begin(9600);
  serialToMCU.begin(115200);
}

void loop() {
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
  if (serialToMCU.available()) {
    serialToMCU.write(String(analogSensor).c_str());
  }
}
