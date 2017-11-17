/*
  Photoresistor

  Use a photoresistor to monitor how bright it is, and turn an LED on when it gets dark.

  View circuit diagram and instructions at:
  https://learn.sparkfun.com/tutorials/sik-experiment-guide-for-arduino---v33/experiment-6-reading-a-photoresistor
 */

int photoresistor = 0;              // this variable will hold a value based on the position of the knob
int threshold = 750;                // if the photoresistor reading is below this value the the light will turn on

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);               // start a serial connection with the computer
  pinMode(13, OUTPUT);              // set pin 13 as an output that can be set to HIGH or LOW
}

// the loop function runs over and over again forever
void loop() {
  // read the position of the knob
  photoresistor = analogRead(A0);   // set photoresistor to a number between 0 and 1023 based on how far the knob is turned
  Serial.println(photoresistor);    // print the value of photoresistor in the serial monitor on the computer

  // if the photoresistor value is below the threshold turn the light on, otherwise turn it off
  if (photoresistor < threshold) {
    digitalWrite(13, HIGH);         // Turn on the LED
  } else{
    digitalWrite(13, LOW);          // Turn off the LED
  }

  delay(100);                       // short delay to make the printout easier to read
}
