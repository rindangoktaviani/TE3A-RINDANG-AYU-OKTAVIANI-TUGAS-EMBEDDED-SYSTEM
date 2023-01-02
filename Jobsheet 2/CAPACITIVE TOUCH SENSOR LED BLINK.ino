// set pin numbers
const int touchPin = 4; 
const int ledPin = 16;

// change with your threshold value
const int threshold = 20;
// variable for storing the touch pin value 
int touchValue;

void setup(){
  Serial.begin(115200);
  delay(1000); // give me time to bring up serial monitor
  // initialize the LED pin as an output:
  pinMode (ledPin, OUTPUT);
}

void loop(){
  // read the state of the pushbutton value:
  touchValue = touchRead(touchPin);
  Serial.print(touchValue);
  // check if the touchValue is below the threshold
  // if it is, set ledPin to HIGH
  if(touchValue < threshold){
    // turn LED on
    digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);
    Serial.println(" - LED on");
    digitalWrite(ledPin, LOW);
    delay(500);
    Serial.println(" - LED off");
  }
  else{
    // turn LED off
    digitalWrite(ledPin, LOW);
    delay(500);
    Serial.println(" - LED off");
  }
}
