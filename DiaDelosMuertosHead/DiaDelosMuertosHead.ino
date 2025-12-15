#include <Servo.h>

Servo Servo1;
Servo Servo2;

const int button1 = 0;
const int button2 = 1;
int servoPin1 = 8;
int servoPin2 = 9;
int servo1_min = 90;
int servo1_max = 100;
int servo2_min = 70;
int servo2_max = 90;
int talkdelay = 80;
int turndelay = 50;

int led = 11;
int buttonState = 0; 
void setup() {
    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);
    Servo1.attach(servoPin1);
    Servo2.attach(servoPin2);
    
    //pinMode(button1, INPUT_PULLUP);
    //pinMode(button2, INPUT_PULLUP);

    //Servo1.write(90);
    Servo2.write(servo2_max);
    delay(1000);

    /*Servo2.write(110);
    delay(4000);
    Servo2.write(90);
    delay(1000);
*/

    
    //for (int i=0;i <1018; i=i+5)
    //{
     // angle = map(i, 0, 1023, 0, 180);
      //Servo1.write(angle);
      //delay(5000); 
   //}


   
}

void openMouth(){
  Servo2.write(servo2_max-15);
  delay(talkdelay);
  Servo2.write(servo2_max-10);
  delay(talkdelay);
  Servo2.write(servo2_max-5);
  delay(talkdelay);
  Servo2.write(servo2_max);
  delay(talkdelay);
}

void closeMouth(){
  Servo2.write(servo2_max);
  delay(talkdelay);
  Servo2.write(servo2_max-5);
  delay(talkdelay);
  Servo2.write(servo2_max-10);
  delay(talkdelay);
  Servo2.write(servo2_max-15);
  delay(talkdelay);
}
void turnLeft(){
  Servo1.write(servo1_max-8);
  delay(turndelay);
  Servo1.write(servo1_max-6);
  delay(turndelay);
  Servo1.write(servo1_max-4);
  delay(turndelay);
  Servo1.write(servo1_max);
  delay(turndelay);
}

void turnRight(){
  Servo1.write(servo1_min+8);
  delay(turndelay);
  Servo1.write(servo1_min+6);
  delay(turndelay);
  Servo1.write(servo1_min+4);
  delay(turndelay);
  Servo1.write(servo1_min+2);
  delay(turndelay);
  Servo1.write(servo1_min);
  delay(turndelay);
}

void loop() {
  /*Servo1.write(servo1_max);
  delay(4000);
  Servo1.write(servo1_min);
  delay(4000);*/

  /*Servo2.write(servo2_max);
  delay(4000);
  Servo2.write(servo2_min);
  delay(4000);*/

  openMouth();
  delay(500);
  closeMouth();
  openMouth();
  delay(400);
  closeMouth();
  delay(1000);


  turnLeft();

  openMouth();
  closeMouth();
  openMouth();
  closeMouth();
  openMouth();
  closeMouth();
  delay(1000);
  openMouth();
  closeMouth();
  openMouth();
  closeMouth();  

  turnRight();



  /*buttonState = digitalRead(button1);
  if (buttonState == LOW) {
    // turn LED on:
    digitalWrite(led, HIGH);
    //Servo1.write(0);
    delay(1000);
    //Servo1.write(180);
    //delay(1000);
    //Servo1.write(0);
    delay(50);
  } else {
    // turn LED off:
    digitalWrite(led, LOW);
  }*/
  delay(50);



}
