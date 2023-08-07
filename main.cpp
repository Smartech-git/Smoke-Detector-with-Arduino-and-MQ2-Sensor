/*
 EEE 302 PROJECT- SMOKE DETECTOR SOURCE CODE
 GRP 1- 40
 5TH AUGUST,2023
*/

// INITIALIZING PINS
int buzzer =  7;  // +ve pin of the buzzer connected the digital pin 9 of arduino through a 1k ohm resistor
int blueLED = 4; // connected to the digital pin 8 of the arduino through  a 1k ohm resistor
int redLED = 2;  // connected to the digital pin 7 of the arduino through a 1k ohm resistor
int sensor = A0;  // analogue pin of the sensor(MG2) connected to the analogue pin A0 in arduino board
int sensorValue = 0;   // to store the reading from the sensor
int threshold = 250; // above this value read from the sensr, the alarm goes off.
int delayTime = 200; // for LED blink time sequence
int bFreq = 4000; // the frequency of the buzze when beeping


// the setup function runs once when you press reset or power the board
void setup() {
  //setup Pin Modes
  pinMode(buzzer, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(sensor, INPUT);

  Serial.begin(9600); // to communicate with the serial monitor at 9600 baud rate
}

// the loop function runs over and over again forever
void loop() {
  sensorValue = 0;
  sensorValue = analogRead(sensor);  // read the input value from the senorPin and store in the sensorValue

  //prints the sensorValue to the serial monitor;
  Serial.print("Sensor value: ");
  Serial.println(sensorValue);

  //conditionals
  if( sensorValue >= threshold){
    // This triggers the alarm and the red lED when the threshold is exceeded of reached
    
    digitalWrite(blueLED, LOW); // OFF the blue LED if it was ON
    
    tone(buzzer, bFreq); // beep the buzzers
    digitalWrite(redLED, HIGH); // ON the red LED 
    delay(delayTime); // delay for 200 milliseconds

    noTone(buzzer); // OFF the buzzers
    digitalWrite(redLED, LOW); // OFF the red LED 
    delay(delayTime); // delay for 200 milliseconds
    
  }else {
    digitalWrite(blueLED, HIGH); // turn ON the Blue LED
    digitalWrite(redLED, LOW);  // turn OFF the Red  LED
    noTone(buzzer); // OFF buzzer
  }
}
