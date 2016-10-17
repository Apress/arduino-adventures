void setup() {
  // setup serial port
  Serial.begin(9600);
  // Turns on Arduino's A0 internal pull-up resistor
  pinMode(A0, INPUT);
}

void loop() {
  // set sensorValue to the reading on analog input 0
  int sensorValue = analogRead(A0);
  // set the mappedSensorValue to the value of the map() function
  int mappedSensorValue = map(sensorValue, 0, 1023, 0, 9);
  // send mappedSensorValue to the serial port.
  Serial.println(mappedSensorValue, DEC);
}

