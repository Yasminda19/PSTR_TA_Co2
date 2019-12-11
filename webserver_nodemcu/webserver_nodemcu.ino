#include <WiFi.h>
const char* ssid     = "Ayana"; //masukkin uname
const char* password = "12345678"; //masukkin pass
WiFiServer server(80);

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
int analogSensor;

void setup()
{
  Serial.begin(115200);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(copin, INPUT);
  pinMode(smokepin, INPUT);
  pinMode(methanepin, INPUT);
  pinMode(airpin, INPUT);
  Serial.begin(115200);
  delay(10);

  connectWiFi();
}

int value = 0;

void loop()
{
  analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
 //   tone(buzzer, 1000, 200);
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
 //   noTone(buzzer);
  }
  delay(1000);
  WiFiLocalWebPageCtrl();
}
void WiFiLocalWebPageCtrl(void)
{
  WiFiClient client = server.available();   // listen for incoming clients
  //client = server.available();
  if (client) {                             
    Serial.println("New Client.");          
    String currentLine = "";                
    while (client.connected()) {            
      if (client.available()) {             
        char c = client.read();             
        Serial.write(c);                   
        if (c == '\n') {                   

          if (currentLine.length() == 0) {
           
            client.println("HTTP/1.1 200 OK"); // cek apakah connect
            client.println("Content-type:text/html");
            client.println();
            client.println("Refresh: 5"); // refresh the page automatically every 5 sec
            client.println();
            client.println("<!DOCTYPE HTML>");
            client.println("<html lang=\"en\">");
            client.println("<head>");
            client.println("<meta charset=\"utf-8\">");
            client.println("<title>cactus.io</title>");
            client.println("</head>");
            client.println("<body>");
            // the content of the HTTP response follows the header:
            //WiFiLocalWebPageCtrl(); 
              client.print("CO  value: ");
              client.print(copin);
              client.print("  oC<br>");
              client.print("<br>");
              client.print("Air Quality Value: ");
              client.print(airpin);
              client.print("  oC<br>");
              client.print("<br>");
              client.print("<br>");
              client.print("Smoke Value: ");
              client.print(smokepin);
              client.print("  oC<br>");
              client.print("<br>");
              client.print("<br>");
              client.print("Methane Value: ");
              client.print(methanepin);
              client.print("  oC<br>");
              client.print("<br>");
              client.print("<br>");
                  

            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            client.println("</body>");
            client.println("</html>");
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}

void connectWiFi(void)
{
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  
  server.begin();
}
