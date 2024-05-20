// Project 2 - SOS Morse Signaller
int ledPin = 10;                

void setup() {
  pinMode(ledPin, OUTPUT);     
}

void loop() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(300);
    digitalWrite(ledPin, LOW);
    delay(200);
  }

  delay(200);     
  
  for (int i = 0; i < 3; i++) {
  	digitalWrite(ledPin, HIGH);
  	delay(800);
  	digitalWrite(ledPin, LOW);
  	delay(200);
  }
  
  delay(200); 
  
  for (int i = 0; i < 3; i++) {
  	digitalWrite(ledPin, HIGH);
  	delay(300);
  	digitalWrite(ledPin, LOW);
  	delay(200);
  }

  delay(5000); 
}
