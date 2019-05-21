/*This Arduino code is for the "Doorman" project I recreated. The original "Doorman" project can be seen here
 * https://www.thingiverse.com/thing:2753756
 * This is updated and cleaned up code that is easier to read and works for my servo,LED,and sensor set up.
 */
#include <Servo.h>

//Define pins that servos are hooked up to on Arduino Nano
const int servoPinEyeLids = 3;
const int servoPinRightEyeX = 6;
const int servoPinLeftEyeX = 5;
const int servoPinRightEyeY = 10;
const int servoPinLeftEyeY = 9;

//Define servo objects
Servo servoEyeLids;
Servo servoRightEyeY;
Servo servoLeftEyeY;
Servo servoRightEyeX;
Servo servoLeftEyeX;

//Define pin for PIR sensor
const int inputPinPIR = 2;

//Define pin for 2 LEDs hooked in parallel
const int pinLED = 13;

//Definie initial PIR sensor state
int statePIR = LOW;
//Variable to hold read in state from PIR sensor
int readStatePIR = 0; 

void setup() {
  //Declare PIR sensor as an INPUT
  pinMode(inputPinPIR, INPUT);
  //Declare LEDs as OUTPUT as we are sending it a signal, not reading in a signal
  pinMode(pinLED, OUTPUT);
  
  //Attach servo objects to correct pins on Arduino Nano
  servoEyeLids.attach(servoPinEyeLids);
  servoRightEyeX.attach(servoPinRightEyeX);
  servoLeftEyeX.attach(servoPinLeftEyeX);
  servoRightEyeY.attach(servoPinRightEyeY);
  servoLeftEyeY.attach(servoPinLeftEyeY);

  /*Set initial positions of SG90 micro servos.
  These positions depend how you hook up the attachments to the servos,
  therefore most likely will be different for you.*/
  servoEyeLids.write(150);
  servoRightEyeX.write(95);
  servoLeftEyeX.write(100);
  servoRightEyeY.write(75);
  servoLeftEyeY.write(50);

  //For debugging purposes, you can use print statements to to make sure you're reaching certain parts of the code
  Serial.begin(9600);
  Serial.println("Start");
}

void loop() {
  //Read the state of the PIR sensor to check for motion
  readStatePIR = digitalRead(inputPinPIR);
  if (readStatePIR == HIGH) {  //motion was detected
    //Turn on LEDs to light up the eyes
    digitalWrite(pinLED, HIGH);
    if (statePIR == LOW) { //check we weren't initiating eye movements before this
      //Iniatate eye movements
      openEyeLids();
      delay(2000);
      turnEyesLeft();
      delay(1000);
      turnEyesRight();
      delay(1000);
      turnEyesStraight();
      delay(1000);
      turnEyesUpAndLeft();
      delay(2000);
      turnEyesUpAndRight();
      delay(1000);
      turnEyesStraight();
      delay(1000);
      //Set PIR state to HIGH so eye movements dont keep looping
      statePIR = HIGH;
    }
  } else {
    if(statePIR == HIGH) { //we just went through eye movements 1 time
      delay(3000);
      //Turn off LEDs
      digitalWrite(pinLED, LOW);
      closeEyeLids();
      delay(1000);
      //reset statePIR to LOW to go through the eye movements again
      statePIR = LOW; //
      
    }
  }
}

void openEyeLids() {
  servoEyeLids.write(160);
}
void closeEyeLids() {
  servoEyeLids.write(80);
}
void turnEyesLeft() {
  servoRightEyeX.write(125);
  servoLeftEyeX.write(130);
}
void turnEyesRight() {
  servoRightEyeX.write(56);
  servoLeftEyeX.write(66);
}
void turnEyesStraight() {
  servoRightEyeY.write(75);
  servoRightEyeX.write(95);
  servoLeftEyeY.write(50);
  servoLeftEyeX.write(100);
}
void turnEyesUpAndLeft() {
  servoRightEyeY.write(50);
  servoRightEyeX.write(120);
  servoLeftEyeY.write(80);
  servoLeftEyeX.write(120);
}
void turnEyesUpAndRight() {
  servoRightEyeY.write(50);
  servoRightEyeX.write(75);
  servoLeftEyeY.write(80);
  servoLeftEyeX.write(75);
}
