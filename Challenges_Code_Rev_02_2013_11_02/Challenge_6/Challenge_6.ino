// include the servo library
#include <Servo.h> 

// create an instance of the servo class 
Servo myservo;

// setup the pins for the project 
int potpin = A0;  
int LEDPin = 7;
int servoPin = 11;

// give pins an initial value
int potVal = 0;    
int modVal = 0;
 
void setup() 
{ 
  // attach the servo to digital pin 11 of the Arduino
  myservo.attach(servoPin);
  // begin Serial communication
  Serial.begin(9600);
  // Turns on Arduino's A0 internal pull-up resistor
  pinMode(potpin, INPUT);
} 
 
void loop() 
{ 
  // read in the potentiometers value and store that value in the
  // potVal variable
  potVal = analogRead(potpin);   
  // map the potVal variable between 0 and 180  
  potVal = map(potVal, 0, 1023, 0, 180);  
  // write potVal to the servo 0-180 degrees  
  myservo.write(potVal);
  // store the remainder of potVal / 30 into modVal  
  modVal = potVal % 30;
  // if modVal is less-than-or-equal-too turn LED on.
  if(modVal <= 5)
  {
    digitalWrite(LEDPin, HIGH);
  }
  // if modVal is greater-than 5 the LED will turn off.
  else
  {
    digitalWrite(LEDPin, LOW); 
  }
  // print potVal to the serial monitor for debugging
  Serial.println(potVal);
  delay(15);                          
}

