#include <Braccio.h>
#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(7, 8); // RX, TX


Servo base;
Servo shoulder;
Servo elbow;
Servo wrist_rot;
Servo wrist_ver;
Servo gripper;



void setup()  
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port

  Braccio.begin();;
    mySerial.begin(9600);
    mySerial.println("Hello, world?");
    delay(2000);
    Braccio.ServoMovement(20, 0, 132, 135, 170, 90, 10);
}


void loop() // run over and over
{
 if (mySerial.available()) {
    //Serial.write(mySerial.read());
    int x = Serial.write(mySerial.read());
    mySerial.println(x);
    if (x == 1) {
    delay(1000);
    Braccio.ServoMovement(20, 0, 132, 135, 170, 90, 60);
    delay(1000);
    Braccio.ServoMovement(20, 90, 100, 145, 170, 90, 60);
    delay(1000);
    Braccio.ServoMovement(20, 90, 100, 145, 170, 90, 10);
    delay(1000);
    Braccio.ServoMovement(20, 0, 132, 135, 170, 90, 10);
    while(mySerial.available()) {
        // Clear the serial buffer to discard any additional bytes
        mySerial.read();
    }
 }
}
}


