#include <KiwisIoT.h>

// WIFI
const char* ssid  = "Wifi name ";      // Replace with your WiFi network name
const char* pass  = "Wifi password";       // Replace with your WiFi network password
const char* topic = "dash_1788941450719";     // Replace with your dashboard topic ID

KiwisIoT kiwisiot(ssid, pass, topic);
#define echoPin D6 
#define trigPin D5 

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT);
   Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with NODEMCU");
  kiwisiot.begin();
}
void loop() {
  kiwisiot.run();
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  kiwisiot.send("1",distance);
 
}