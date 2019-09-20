#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

StaticJsonBuffer<200> jsonBuffer;

const char* wifiName = "Ayana";
const char* wifiPass = "12345678";
byte mac[6]; 
 
//Web Server address to read/write from 
const char *host = ""; //insert http link here

char json[] = "{\"sensor\":}
 
void setup() {
  
  Serial.begin(115200);
  delay(10);
  Serial.println();
 
  
  Serial.print("Connecting to ");
  Serial.println(wifiName);
 
  WiFi.begin(wifiName, wifiPass);

 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  

  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
 
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());   //You can get IP address assigned to ESP
}
 
void loop() {
  HTTPClient http;    //Declare object of class HTTPClient
 
  Serial.print("Request Link:");
  Serial.println(host);
  
  http.begin(host);     //Specify request destination
  
  int httpCode = http.GET();            //Send the request
  String payload = http.getString();    //Get the response payload from server
 
  Serial.print("Response Code:"); //200 is OK
  Serial.println(httpCode);   //Print HTTP return code

  Serial.println();

  Serial.println();

  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.println();
 
  Serial.print("Returned data from Server:");
  Serial.println(payload);    //Print request response payload
  
  if(httpCode == 200)
  {
    // Allocate JsonBuffer
    // Use arduinojson.org/assistant to compute the capacity.
    const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
    DynamicJsonBuffer jsonBuffer(capacity);
  
   // Parse JSON object
    JsonObject& root = jsonBuffer.parseObject(json);
    if(!root.success()) {
    Serial.println("parseObject() failed");
    return false;
    }
  else
  {
  const char* sensor = root["sensor"];
  }

  //HTTP POST
  JsonObject& root = jsonBuffer.createObject();
  root["sensor"] = "co2";
  root["time"] = ;

  JsonArray& data = root.createNestedArray("data");
  data.add(48.756080);
  data.add(2.302038);

  root.printTo(Serial);
 
  http.end();  //Close connection
  
  delay(20000);  //GET Data at every 2 seconds
}
