int tempPin = A0; 
int LEDPin = 13;
 
void setup()
{
   pinMode(LEDPin, OUTPUT);
   Serial.begin(9600);
   // Turns on Arduino's A0 internal pull-up resistor
   pinMode(tempPin, INPUT);
}
 
void loop()
{
 //get voltage reading from the temperature sensor
 int reading = analogRead(tempPin);  
 
 float voltage = reading * 5.0;
 voltage /= 1024.0;  // short way of stating voltage = voltage / 1024.0
 
 // now print out the temperature
 float tempC = (voltage - 0.5) * 100 ;  
 
 // now convert to Fahrenheight
 float tempF = (tempC * 9.0 / 5.0) + 32.0;
 
 if(tempF >= 75)
 {
   digitalWrite(LEDPin, HIGH);
 }
 else 
 {
   digitalWrite(LEDPin, LOW); 
 }
 
 Serial.println(tempF); //Send tempF data to serial port.
 
 delay(500);   //waiting a half second
}

