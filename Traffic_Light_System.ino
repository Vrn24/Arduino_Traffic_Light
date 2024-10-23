#include <LiquidCrystal.h> // Include the LCD library

//...............JehanKandy........................
//...........www.jehankandy.com....................
//........www.github.com/JehanKandy....................

//......Arduino Based Traffic Light System 1.2.....

// Create Variables
const int R_LED = 3; // Red LED
const int Y_LED = 4; // Yellow LED
const int G_LED = 5; // Green LED
const int buttonPin = 6; // Pedestrian button pin
const int soundpin = 13; // Sound when pedestrion button is active

// Timing constants
const unsigned long RED_TIME = 30000; // Red light duration
const unsigned long YELLOW_TIME = 2000; // Yellow light duration
const unsigned long GREEN_TIME = 30000; // Green light duration

// Initialize the LCD (pin numbers may vary)
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // (rs, en, d4, d5, d6, d7)

void setup() {
  pinMode(R_LED, OUTPUT);
  pinMode(Y_LED, OUTPUT);
  pinMode(G_LED, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP); // Enable internal pull-up resistor
  pinMode(soundpin, OUTPUT):
  lcd.begin(16, 2); // Initialize the LCD with 16 columns and 2 rows
  lcd.print("Traffic Light"); // Display initial message
}

void loop() {
  // Check for pedestrian request
  if (digitalRead(buttonPin) == LOW) { // Button pressed
    lcd.clear();
    lcd.print("Crossing Request");
    delay(2000); // Show message for 2 seconds
    allowCrossing(); // Allow pedestrian crossing
  } else {
    // Normal traffic light operation
    operateTrafficLight();
  }
}

void operateTrafficLight() {
  // Part 1: Red light
  setLightState(HIGH, LOW, LOW);
  lcd.clear();
  lcd.print("STOP");
  delay(RED_TIME);

  // Part 2: Red + Yellow light
  setLightState(HIGH, HIGH, LOW);
  lcd.clear();
  lcd.print("Get Ready");
  delay(YELLOW_TIME);

  // Part 3: Green light
  setLightState(LOW, LOW, HIGH);
  lcd.clear();
  lcd.print("GO");
  delay(GREEN_TIME);

  // Part 4: Yellow light
  setLightState(LOW, HIGH, LOW);
  lcd.clear();
  lcd.print("Get Ready");
  delay(YELLOW_TIME);
}

void allowCrossing() {
  // Set all lights off for pedestrian crossing
  setLightState(LOW, LOW, LOW);
  lcd.clear();
  lcd.print("Walk Safely");
  digitalWrite(soundpin, HIGH);
  delay(10000); // Allow crossing for 10 seconds
  digitalWrite(soundpin, LOW);
  // Reset traffic light sequence
}

void setLightState(int red, int yellow, int green) {
  digitalWrite(R_LED, red);
  digitalWrite(Y_LED, yellow);
  digitalWrite(G_LED, green);
}

//.........coded by : JehanKandy....
//...........Thank You..............
