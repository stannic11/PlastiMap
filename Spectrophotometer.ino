int greenPin=9;
int redPin=10;
int bluePin=11;

int LDR=A0;
int Rval=0;
int Oval=0;
int Yval=0;
int Gval=0;
int Bval=0;
int Pval=0;

#define CUSTOM_SETTINGS
#define INCLUDE_INTERNET_SHIELD
#define INCLUDE_TERMINAL_SHIELD
#define INCLUDE_GPS_SHIELD
#include <OneSheeld.h>

float latitude;
float longitude;

char charlatitude[10];
char charlongitude[10];

HttpRequest request ("https://api.thingspeak.com/update?api_key=L8QZ03UJD58NJXV3");

//define the fileds for the ThingsSpeak data
String Field1="&field1=";
String Field2="&field2=";
String Field3="&field3=";
bool id=false;

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(LDR, INPUT);

}

void loop() {
  //Red
  analogWrite(redPin, 255);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
  Rval=analogRead(LDR);
  Serial.println(val);
  delay(10000);
  
  //Orange (600)
  analogWrite(redPin, 255);
  analogWrite(greenPin, 70);
  analogWrite(bluePin, 0);
  Oval=analogRead(LDR);
  Serial.println(val);
  delay(10000);
  
  //Yellow (580)
  analogWrite(redPin, 255);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 0);
  Yval=analogRead(LDR);
  Serial.println(val);
  delay(10000);
  
  //Green
  analogWrite(redPin, 0);
  analogWrite(greenPin, 255);
  analogWrite(bluePin, 0);
  Gval=analogRead(LDR);
  Serial.println(val);
  delay(10000);
  
  //Blue
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 255);
  Bval=analogRead(LDR);
  Serial.println(val);
  delay(10000);
  
  //Purple (400 nm)
  analogWrite(redPin, 131);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 181);
  Pval=analogRead(LDR);
  Serial.println(val);
  Serial.print("\n");
  delay(10000);
}

if(Yval>=400){ //Determined by calibration
  id=true;
}

request.addRawData(&(Field1+DataLatitude+Field2+DataLongitude+Field3+id)[0]);
  Internet.performPost(request);                // Perform get to the request
  OneSheeld.delay(2500);
