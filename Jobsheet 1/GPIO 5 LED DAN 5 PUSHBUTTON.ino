// set pin numbers
const int buttonPin = 4; // the number of the pushbutton pin
const int ledPin = 5; // the number of the LED pin
const int buttonPin1 = 2;
const int ledPin1 = 19;
const int buttonPin2 = 33;
//const int ledPin2 = 25;
//const int ledPin3 = 26;
//const int ledPin4 = 27;
// variable for storing the pushbutton status
int buttonState = 0;
int buttonState1 = 0;
int buttonState2 = 0;
void setup() { 
 Serial.begin(115200);
 // initialize the pushbutton pin as an input
 pinMode(buttonPin, INPUT);
 pinMode(buttonPin1, INPUT);
 pinMode(buttonPin2, INPUT);
 // initialize the LED pin as an output
 pinMode(ledPin, OUTPUT);
 pinMode(ledPin1, OUTPUT);
//pinMode(ledPin2, OUTPUT);
 //pinMode(ledPin3, OUTPUT);
 //pinMode(ledPin4, OUTPUT);
}
void loop() {
  
 // read the state of the pushbutton value
 buttonState = digitalRead(buttonPin);
 Serial.println(buttonState);
 // check if the pushbutton is pressed.
 // if it is, the buttonState is HIGH
 if (buttonState == HIGH) {
 // turn LED on
 digitalWrite(ledPin, HIGH);
 } else {
 // turn LED off
 digitalWrite(ledPin, LOW);
 }
 buttonState1 = digitalRead(buttonPin1);
 Serial.println(buttonState1);
 
 if (buttonState1 == HIGH) {
 // turn LED on
  digitalWrite(ledPin1, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(ledPin1, LOW);    // turn the LED off by making the voltage LOW
  delay(500);                       // wait for a second
 } else {
 // turn LED off
 digitalWrite(ledPin1 , LOW);
 }
 
 buttonState2 = digitalRead(buttonPin2);
 Serial.println(buttonState2);
  if (buttonState2 == HIGH) {
  //LED yang ada di Pin 3 menyala, Pin 4 & 5 mati
  digitalWrite(25, HIGH);
  digitalWrite(26, LOW);
  digitalWrite(27, LOW);
  //kecepatan kedip 0,5 detik
  delay(500);
 
  //LED yang ada di Pin 4 menyala, Pin 3 & 5 mati
  digitalWrite(25, LOW);
  digitalWrite(26, HIGH);
  digitalWrite(27, LOW);
  //kecepatan kedip 0,5 detik
  delay(500);
 
  //LED yang ada di Pin 5 menyala, Pin 3 & 4 mati
  digitalWrite(25, LOW);
  digitalWrite(26, LOW);
  digitalWrite(27, HIGH);
  //kecepatan kedip 0,5 detik
  delay(500);                      
 } else {
 // turn LED off
 digitalWrite(25 , LOW);
 digitalWrite(26 , LOW);
 digitalWrite(27 , LOW);
 }
}
