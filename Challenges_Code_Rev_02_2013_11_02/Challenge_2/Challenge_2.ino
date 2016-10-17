int buttonPin = 12;  // Arduino pin that the button is connected to.
int LEDPin = 6; // Arduino pin that the LED is connected to.
 
int buttonState = 0; // Keeps track of button

void setup()
{
  // Set button as an input
  pinMode(buttonPin, INPUT);
  // Set LED as an output
  pinMode(LEDPin, OUTPUT);
  // Use Arduinos internal pull-up resistor
  digitalWrite(buttonPin, HIGH); 
}
void loop()
{
  // Read button value on Arduino
  buttonState = digitalRead(buttonPin);
 
  // Conditional If Statement
  if(buttonState == LOW)
  {
   // Turn ON LED when button is pressed
   digitalWrite(LEDPin, HIGH);
  } 
  else
    // Turn OFF LED when button is not pressed
    digitalWrite(LEDPin, LOW);
}

