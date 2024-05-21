// Project 6 - Interactive LED Chase Effect

byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; // Array for LEDs pins
int ledDelay; // Delay between changes on LEDs
int direction = 1;
int currentLED = 0;
unsigned long changeTime;
int potPin = 2; // Input pin for the potentiometer

void setup() {
  for (int i = 0; i < 10; i++) {
    pinMode(ledPin[i], OUTPUT); 
  }
  changeTime = millis();
}

void loop() {
  ledDelay = analogRead(potPin); // Read the value from the potentiometer
  // Check if it has been ledDelay value in ms since last change
  if ((millis() - changeTime) > ledDelay) {
    changeLED();
    changeTime = millis();
  }
}

void changeLED() {
  // Turn off all LEDs
  for (int i = 0; i < 10; i++) {
    digitalWrite(ledPin[i], LOW);
  }
  
  // Turn on the current LED
  digitalWrite(ledPin[currentLED], HIGH);
  // Increment the current LED based on direction value
  currentLED += direction;

  // Change the direction if we reach the end of LEDs sequence
  if (currentLED == 9) {direction = -1;}
  if (currentLED == 0) {direction = 1;}
}
