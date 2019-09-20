#include <TFT.h> // Hardware-specific library
#include <SPI.h>
#include <Esplora.h>

//definisi warna
#define BLACK 0x0000
#define BLUE 0x001F
#define BLUEVIOLET 0x895C
#define BROWN 0xA145
#define CHOCOLATE 0xD343
#define DARKGREEN 0x0320
#define DARKSALMON 0xECAF
#define FIREBRICK 0xB104
#define GREEN 0x0400
#define GREENYELLOW 0xAFE5
#define IVORY 0xFFFE
#define LIGHTBLUE 0xAEDC
#define LIGHTGREEN 0x9772
#define LIGHTSKYBLUE 0x867F
#define LIGHTSTEELBLUE 0xB63B
#define LIGHTYELLOW 0xFFFC
#define LIME 0x07E0
#define LIMEGREEN 0x3666
#define MAGENTA 0xF81F
#define MAROON 0x8000
#define MIDNIGHTBLUE 0x18CE
#define NAVY 0x0010
#define ORANGE 0xFD20
#define PINK 0xFE19
#define PLUM 0xDD1B
#define POWDERBLUE 0xB71C
#define PURPLE 0x8010
#define RED 0xF800
#define SPRINGGREEN 0x07EF
#define YELLOW 0xFFE0
#define WHITE 0xFFFF 

TFT myScreen = TFT(CS, DC, RESET);

// initial position of the point is the middle of the screen
// initial position of the point is the middle of the screen
int xPos = 80;
int yPos = 64;

// direction and speed
int xDir = 1;
int yDir = 1;

// variables to keep track of the point's location
int xPrev = xPos;
int yPrev = yPos;

void setup(){
  EsploraTFT.begin();  
  EsploraTFT.background(0,0,0);  // clear the screen with black
  delay(1000);  // pause for dramatic effect
  myScreen.begin();  
  myScreen.background(0,0,0);
}

void loop(){
  EsploraTFT.stroke(255, 0, 0); // set the stroke color to red
  EsploraTFT.line(0, 10, EsploraLCD.width(), 10); // draw a line across the screen
  delay(1000);

  EsploraTFT.noStroke(); // don't draw a line around the next rectangle
  EsploraTFT.fill(0,255,0); // set the fill color to green
  EsploraTFT.rect(0,20,EsploraTFT.width(),20); //draw a rectangle across the screen
  delay(1000);

  EsploraTFT.fill(0,0,255); // set the fill color to blue
  EsploraTFT.stroke(255,255,255); // outline the rectangle with a white line
  EsploraTFT.rect(0,45,EsploraTFT.width(),50); // draw a fat rectangle
  delay(1000);

  EsploraTFT.background(0,0,0); // clear the screen before starting again
  delay(1000);
}
