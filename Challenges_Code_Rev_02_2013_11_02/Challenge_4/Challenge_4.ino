// Initialize all of the pins variables
int LEDPin1 = 12;
int LEDPin2 = 11;
int ButtonPin1 = 10;
int ButtonPin2 = 9;
int MotorPWMPin = 3;
int MotorDirPin = 4;
int PotPin = A0;

// Initialize value and state variables
int ButtonState1 = 0;
int ButtonState2 = 0;
int PotValue = 0;
int MappedPotValue = 0;

void setup()
{
  // Set pins to be outputs
  pinMode(LEDPin1, OUTPUT);
  pinMode(LEDPin2, OUTPUT);
  pinMode(MotorPWMPin, OUTPUT);
  pinMode(MotorDirPin, OUTPUT);

  // use the Arduino's internal pullup resistor for 
  // the buttons so that the buttons do not float.
  digitalWrite(ButtonPin1, HIGH);
  digitalWrite(ButtonPin2, HIGH);
  
  // Turns on Arduino's A0 internal pull-up resistor
  pinMode(PotPin, INPUT);
}

void loop()
{
  // Read in button values
  ButtonState1 = digitalRead(ButtonPin1);
  ButtonState2 = digitalRead(ButtonPin2);
  // Read in Potentiometer values
  PotValue = analogRead(PotPin);

  // Scale pot value from 0 to 256
  MappedPotValue = PotValue/4;

  if (ButtonState1 == 0)
  {
    // if button1 is pressed adjust speed to mapped
    // potentiometer value then turn motor on and turn 
    // counterclockwise.
    analogWrite(MotorPWMPin, MappedPotValue);
    digitalWrite(MotorDirPin, HIGH);
    digitalWrite(LEDPin1, HIGH);
    digitalWrite(LEDPin2, LOW);
  }
  else if (ButtonState2 == 0)
  {
    // if button2 is pressed adjust speed to mapped
    // potentiometer value then turn motor on and turn 
    // clockwise.
    analogWrite(MotorPWMPin, MappedPotValue);
    digitalWrite(MotorDirPin, LOW);
    digitalWrite(LEDPin2, HIGH);
    digitalWrite(LEDPin1, LOW);
  }
  else
  {
    // Turn motor off
    digitalWrite(MotorPWMPin, LOW);
    digitalWrite(MotorDirPin, LOW);
    digitalWrite(LEDPin2, LOW);
    digitalWrite(LEDPin1, LOW); 
  }
}

