#include <WiFi.h>
#include <HTTPClient.h>
 
const char* ssid = "Ayana";
const char* password =  "12345678";

/* CO2 Monitoring Section */
int CO2pin = A0; 
int redLed = 12;
int greenLed = 11;
int buzzer = 10;
int sensorThres = 400;
int val;

void setup() {
  
  Serial.begin(115200);
  delay(4000);   //Delay needed before calling the WiFi.begin
 
  WiFi.begin(ssid, password); 
 
  while (WiFi.status() != WL_CONNECTED) { //Check for the connection
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");

  
  pinMode(CO2pin, INPUT); // Pin input CO2
 
}
 
void loop() {
 int analogSensor = analogRead(CO2pin); // Input analog sensor CO2

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

  val = analogRead(CO2pin); //Read Analog values and Store in val variable
 
 if(WiFi.status()== WL_CONNECTED){   //Check WiFi connection status
 
   HTTPClient http;   

   String url = "http://hilmy.top/api/co2&value=";
   url += val;
   Serial.println("URL : " + url);
   
   http.begin(url);  //Specify destination for HTTP request
   http.addHeader("Content-Type", "text/plain");             //Specify content-type header
 
   int httpResponseCode = http.POST("POSTING from ESP32");   //Send the actual POST request
 
   if(httpResponseCode>0){
 
    String response = http.getString();                       //Get the response to the request
 
    Serial.println(httpResponseCode);   //Print return code
    Serial.println(response);           //Print request answer
 
   }else{
 
    Serial.print("Error on sending POST: ");
    Serial.println(httpResponseCode);
 
   }
 
   http.end();  //Free resources
 
 }else{
 
    Serial.println("Error in WiFi connection");   
 
 }
 
  delay(10000);  //Send a request every 10 seconds
 
}
