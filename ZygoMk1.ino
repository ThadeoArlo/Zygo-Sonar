/*Modified version of obstacle avoider,
code adapted to detect proximity and 
sends signal if rang is less than ~45cm*/
#define trigPin 12  // define the pins of your sensor
#define echoPin 13
int ledPin = 11;  // LED connected to digital pin 13
void setup() {
  pinMode(ledPin, OUTPUT);   // sets the digital pin as output
  Serial.begin(9600);        
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);   
}
void loop() {
  long duration, distance;  // start the scan
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);  // delays are required for a succesful sens or operation.
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);  // this delay is required as well!
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;  // convert the distance to centimeters
  if (distance < 100) { /*if there's an obstacle 25 centimers, ahead, do the following: */
    Serial.println("Close Obstacle detected!");
    Serial.print(distance);
    Serial.print(" CM!");  // print out the distance in centimeters.
    digitalWrite(ledPin, HIGH);  // sets the LED on
  } else {
    Serial.println("No obstacle detected.");
    digitalWrite(ledPin, LOW);  // sets the LED off
  }
}
