#include <Adafruit_GFX.h>    // Core graphics library
#include "SWTFT.h" // Hardware-specific library
#include <dht11.h>
dht11 DHT;


#include <SPI.h>
#include <SD.h>
   
   File myFile;

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

SWTFT tft;
int chk;
int smokepin = A8; //LDR Pin Connected at A0 Pin
int methanepin = A9;
int copin = A10;
int airpin = A12;
int sensorThres = 400;

void setup(void) {
  Serial.begin(9600);
  Serial.println(F("TFT LCD test"));
  
  tft.reset();
  uint16_t identifier = tft.readID();
 
    Serial.print(F("LCD driver chip: "));
    Serial.println(identifier, HEX);

  tft.begin(identifier);
  Serial.println(F("Benchmark Time (microseconds)"));
  Serial.print(F("Screen fill"));
  delay(500);
  
Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
}

void loop(void) {


  int analogMQ7 = analogRead(smokepin);
  int analogMQ4 = analogRead(methanepin);
  int analogMQ9 = analogRead(copin);
  int analogMQ135 =  analogRead(airpin);

  Serial.print(smokepin,1);
  Serial.print(",\t");
  Serial.println(methanepin,1);
  Serial.print(",\t");
  Serial.println(copin,1);
  Serial.print(",\t");
  Serial.println(airpin,1);

  
  tft.fillScreen(BLACK);
  tft.setCursor(10, 10);
  
  tft.setTextSize(5);
 
  String stringOne = ("Smoke "); 
  String stringThree = stringOne + smokepin;
  tft.println(stringThree); 
  
  tft.setTextColor(WHITE);
  tft.setCursor(10, 60);
  String stringTwo = "Methane";
  String stringFour = stringTwo + methanepin;
  tft.println(stringFour); 

  tft.setTextColor(RED);
  tft.setCursor(10, 60);
  String stringTwo = "Co";
  String stringFour = stringTwo + copin;
  tft.println(stringFour); 

  tft.setTextColor(GREEN);
  tft.setCursor(10, 60);
  String stringTwo = "Kualitas Udara";
  String stringFour = stringTwo + airpin;
  tft.println(stringFour); 

  delay(5000);


    // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("test.txt", FILE_WRITE);

    // if the file opened okay, write to it:
  if (myFile) {
   // Serial.print("Writing to test.txt...");
    myFile.println(stringThree + stringFour);
    // close the file:
    myFile.close();
    Serial.println("writing done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }

  // re-open the file for reading:
  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("test.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }

  delay(2000);
}
