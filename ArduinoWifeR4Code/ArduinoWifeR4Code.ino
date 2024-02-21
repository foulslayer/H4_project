#include <PubSubClient.h>
#include <WiFiS3.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(12, 13);  // Rx (MISO), Tx (SCK)



const char ssid[] = "bruh";  // change your network SSID (name)
const char pass[] = "Datait2024!";   // change your network password (use for WPA, or use as key for WEP)

int status = WL_IDLE_STATUS;

WiFiClient wifiClient;
PubSubClient client(wifiClient);

//afstand værdi og pins
const int trigPin = 3;
const int echoPin = 2;
long duration;
float distance;


void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
   pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input


 
  // attempt to connect to WiFi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);
    
    // wait 10 seconds for connection:
    delay(3000);
  }
  Serial.print(status);
    client.setServer("192.168.0.128",1883);
    // client is now ready for use
    if (client.connect("welp_arduino", "admin", "DataIt2024!")) {
    // connection succeeded
    Serial.println("Connected now subscribing");
   bool rc = client.publish("presence", "This is a test message");

  } 
  else {
    // connection failed
    Serial.println(client.state()); // will provide more information
    // on why it failed.
    Serial.println("Connection failed ");
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = (duration*.0343)/2;
String myString = String(distance);
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
 if (client.connect("welp_arduino", "admin", "DataIt2024!")) {

  if(distance >= 13 and distance <= 15){
     bool rc = client.publish("presence", myString.c_str());
    mySerial.println(1); 
  Serial.println("1st instruction sended");
 // mySerial.write("instruction");
  delay(5000);
} 
}}
