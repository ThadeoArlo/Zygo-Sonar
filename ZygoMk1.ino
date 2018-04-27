#define trigPin 12
#define echoPin 13
int ledPin = 11;
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;
  if (distance < 30) {
    Serial.println("Close Obstacle detected!");
    Serial.print(distance);
    Serial.print(" CM!");
    digitalWrite(ledPin, HIGH);
  } else {
    Serial.println("No obstacle detected.");
    digitalWrite(ledPin, LOW);
  }
}
