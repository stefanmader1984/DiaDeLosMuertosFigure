/* PINS Teensy 3.1
Neopixel: 2
Neopixel VCC: 5V
Neopixel GND: GND

Servo1 Mouth: 3
Servo1 VCC: 5V
Servo1 GND: GND

Servo2 Headturn: 4
Servo2 VCC: 5V
Servo2 GND: GND

Button1: 18
Button2: 19
Button3: 20
Button4: 21
Button5: 22
Button6: 23
Button GND: GND

DF Player Mini VCC: 5V
DF Player Mini GND: GND
DF Player Mini RX: 1K Resistor to: 1 (TX1)
DF Player Mini TX: 0 (RX1)
DF Player Mini SPK_1: Speaker red
DF Player Mini GND: Speaker black
*/


#include <Servo.h>
#include "Adafruit_NeoPixel.h"
#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#define HWSERIAL Serial1
//SoftwareSerial mySoftwareSerial(1, 0); // RX, TX

DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

Servo Servo1;
Servo Servo2;

const int button1 = 18;
const int button2 = 19;
const int button3 = 20;
const int button4 = 21;
const int button5 = 22;
const int button6 = 23;

int servoPin1 = 3;
int servoPin2 = 4;

int ledPin = 2;
int buttonState1 = 0;
int buttonState2 = 0; 
int buttonState3 = 0; 
int buttonState4 = 0; 
int buttonState5 = 0; 
int buttonState6 = 0;

int servo1Min = 70;
int servo1Max = 90;

int servo2Min = 90;
int servo2Max = 105;

#define LEDBRIGTHNESS 60 //128
Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, ledPin, NEO_RGB + NEO_KHZ800);


void setup() {
    Servo1.attach(servoPin1);
    Servo2.attach(servoPin2);
    
    pinMode(button1, INPUT_PULLUP);
    pinMode(button2, INPUT_PULLUP);
    pinMode(button3, INPUT_PULLUP);
    pinMode(button4, INPUT_PULLUP);
    pinMode(button5, INPUT_PULLUP);
    pinMode(button6, INPUT_PULLUP);

    strip.begin();
    strip.setBrightness(1);

    //mySoftwareSerial.begin(9600);
    myDFPlayer.begin(Serial1);
    HWSERIAL.begin(9600);
    Serial.begin(115200);

    Servo1.write(servo1Min); //Mouth closed
    Servo2.write(servo2Min);

    Serial.println();
    Serial.println(F("DFRobot DFPlayer Mini Demo"));
    Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
    if (!myDFPlayer.begin(HWSERIAL)) {  //Use softwareSerial to communicate with mp3.
      Serial.println(F("Unable to begin:"));
      Serial.println(F("1.Please recheck the connection!"));
      Serial.println(F("2.Please insert the SD card!"));
      while(true);
    }
    Serial.println(F("DFPlayer Mini online."));
  
    myDFPlayer.volume(25);  //Set volume value. From 0 to 30


    delay(1000);


}

static void setServo1ToMin()
{
  Servo1.write(servo1Min);
}

static void setServo1ToMax()
{
  Servo1.write(servo1Max);
}

static void setServo2ToMin()
{
  Servo2.write(servo2Min);
}

static void setServo2ToMax()
{
  Servo2.write(servo2Max);
}

static void setLight()
{
  strip.setPixelColor(0, strip.Color(0,255,0));
  strip.setBrightness(LEDBRIGTHNESS);
  strip.show(); 
  delay(1000);
  LightAbblendenSlow();
}

static void LightAbblendenSlow()
{
  for (uint16_t j = LEDBRIGTHNESS; j > 5; j=j-5) {
    strip.setBrightness(j);
    strip.show(); 
    delay(30);
  }
  strip.setPixelColor(0, strip.Color(0,0,0));
  strip.setBrightness(LEDBRIGTHNESS);
  strip.show(); 
  delay(30);
}
void playnextMP3()
{
  myDFPlayer.next();  //Play next mp3 every 3 second.
}

void loop() {

  buttonState1 = digitalRead(button1);
  if (buttonState1 == LOW) {
    setServo1ToMin();
    delay(500);
  } else {

  }

  buttonState2 = digitalRead(button2);
  if (buttonState2 == LOW) {
    setServo1ToMin();
    delay(500);
  } else {

  }

  buttonState3 = digitalRead(button3);
  if (buttonState3 == LOW) {
    setServo1ToMax();
    delay(500);
  } else {

  }

  buttonState4 = digitalRead(button4);
  if (buttonState4 == LOW) {
    setServo2ToMin();
    delay(500);
  } else {

  }

  buttonState5 = digitalRead(button5);
  if (buttonState5 == LOW) {
    setServo2ToMax();
    delay(500);
  } else {
    

  }
  buttonState6 = digitalRead(button6);
  if (buttonState6 == LOW) {
    //myDFPlayer.play(1);  //Play the first mp3
    playnextMP3();
    setLight();
  } else {
    

  }


  delay(50);



}
