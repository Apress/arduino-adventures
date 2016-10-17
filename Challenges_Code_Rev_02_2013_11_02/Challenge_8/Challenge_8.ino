// initailize the two PWM pins to control speed for two motors
int PWMPin1 = 5;
int PWMPin2 = 6;

// initailize direction pins
int DirPin1 = 4;
int DirPin2 = 7;

// function prototypes for the 5 function we need to create
void Forward(int);
void Reverse(int);
void turnRight(int);
void turnLeft(int);
void Stop(int);

void setup()
{
  // set the pin mode for each of the digital pins of the Arduino
  // that are used to control speed and direction.
  pinMode(PWMPin1, OUTPUT);
  pinMode(PWMPin2, OUTPUT);
  pinMode(DirPin1, OUTPUT);
  pinMode(DirPin2, OUTPUT);
}

void loop()
{
  
  // move forward for 1500ms
  Forward(1500);
  // turn right for 500ms
  turnRight(500);
  // move forward for 2000ms
  Forward(2000);
  // turn left for 750ms
  turnLeft(750);
  // reverse for 2500ms
  Reverse(2500);
  // stop both motors for 2500ms
  Stop(2500);
  
}

// this is the Forward function
void Forward(int tdelay)
{
  /* 
     sets DirPin1 to HIGH and PWMPin1 to 220 out of 255.
     I tweeked the PWMPin1 value to 220 rather then 255
     because the robot was turning left when it should be going 
     straight. You may need to do the same to either PWMPin 
     value.
  */  
   digitalWrite(DirPin1, HIGH);
   analogWrite(PWMPin1, 220);
   // sets DirPin2 to HIGH and PWMPin2 to 255 out of 255.
   digitalWrite(DirPin2, HIGH);
   analogWrite(PWMPin2, 255);
   // delay for what ever integer value is passed into the 
   // Forward function.
   delay(tdelay);
}

// this is the Reverse function
void Reverse(int tdelay)
{
   // sets DirPin1 to LOW and PWMPin1 to 220 out of 255.
   digitalWrite(DirPin1, LOW);
   analogWrite(PWMPin1, 220);
   // sets DirPin2 to LOW and PWMPin2 to 255 out of 255.
   digitalWrite(DirPin2, LOW);
   analogWrite(PWMPin2, 255);
   // delay for what ever integer value is passed into the 
   // Reverse function.
   delay(tdelay);
}

// this is the turnRight function
void turnRight(int tdelay)
{
   // sets DirPin1 to LOW and PWMPin1 to 220 out of 255.
   digitalWrite(DirPin1, LOW);
   analogWrite(PWMPin1, 220);
   // sets DirPin2 to HIGH and PWMPin2 to 255 out of 255.
   digitalWrite(DirPin2, HIGH);
   analogWrite(PWMPin2, 255);
   // delay for what ever integer value is passed into the 
   // turnRight function.
   delay(tdelay);
}

// this is the turnLeft function
void turnLeft(int tdelay)
{
   // sets DirPin1 to HIGH and PWMPin1 to 220 out of 255.
   digitalWrite(DirPin1, HIGH);
   analogWrite(PWMPin1, 220);
   // sets DirPin2 to LOW and PWMPin2 to 255 out of 255.
   digitalWrite(DirPin2, LOW);
   analogWrite(PWMPin2, 255);
   // delay for what ever integer value is passed into the 
   // turnLeft function.
   delay(tdelay);
}

// this is the stop function
void Stop(int tdelay)
{
   // sets DirPin1 to LOW and PWMPin1 to 0 out of 255.
   digitalWrite(DirPin1, LOW);
   analogWrite(PWMPin1, 0);
   // sets DirPin2 to LOW and PWMPin2 to 0 out of 255.
   digitalWrite(DirPin2, LOW);
   analogWrite(PWMPin2, 0);
   // delay for what ever integer value is passed into the 
   // Stop function.
   delay(tdelay);
}

