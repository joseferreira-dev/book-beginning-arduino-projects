// Project 4 - Interactive Traffic Lights

// Car lights
int carRed = 12;
int carYellow = 11;
int carGreen = 10;
// Pedestrian lights
int pedRed = 9; 
int pedGreen = 8;

int button = 2;
int crossTime = 5000;
unsigned long changeTime = 0; // time last pedestrian cycle completed

void setup() {
  pinMode(carRed, OUTPUT);
  pinMode(carYellow, OUTPUT);
  pinMode(carGreen, OUTPUT);
  pinMode(pedRed, OUTPUT);
  pinMode(pedGreen, OUTPUT);
  pinMode(button, INPUT);
  // Setup the initial lights state
  digitalWrite(carGreen, HIGH); 
  digitalWrite(pedRed, HIGH);
}

void loop() {
  int state = digitalRead(button);
  // Check if button is pressed and it is over 5 seconds since last button press
  if (state == HIGH && (millis() - changeTime) > 5000) {
    changeLights();
  }
}

void changeLights() {
  digitalWrite(carGreen, LOW);
  digitalWrite(carYellow, HIGH);
  delay(2000);

  digitalWrite(carYellow, LOW);
  digitalWrite(carRed, HIGH);
  delay(1000);

  digitalWrite(pedRed, LOW);
  digitalWrite(pedGreen, HIGH);
  delay(crossTime);

  for (int i = 0; i < 10; i++) {
    digitalWrite(pedGreen, HIGH);
    delay(250);
    digitalWrite(pedGreen, LOW);
    delay(250);
  }

  digitalWrite(pedRed, HIGH);
  delay(500);

  digitalWrite(carYellow, HIGH);
  digitalWrite(carRed, LOW);
  delay(1000);
  digitalWrite(carGreen, HIGH);
  digitalWrite(carYellow, LOW);

  // record the time since last change of lights
  changeTime = millis();
}
