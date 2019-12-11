//MQ4 = Methane
//MQ9 = Carbon Monoxide
//MQ135 = Air Quality
//MQ7 = Smoke

int smokepin = A3; //LDR Pin Connected at A0 Pin
int methanepin = A1;
int copin =A9;
int airpin = A0;
int redLed = 12;
int greenLed = 11;
int buzzer = 10;
int sensorThres = 400;

void setup() {
  Serial.begin(9600);
}

void loop() {
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
  delay(300);

}
