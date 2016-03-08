/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
#include <stdlib.h>

Servo myservo;  // create servo object to control a servo
Servo Bmyservo;  // create servo object to control a servo

// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600);//test
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Bmyservo.attach(3);
}

void loop() {
    int myRan = random(2,10);
    int light =analogRead(A0);
    
  for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    int light =analogRead(A0);
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    Bmyservo.write(90-pos);
    if(light<5){
      myservo.write(myRan*5);              // tell servo to go to position in variable 'pos'
      Bmyservo.write(90-pos-myRan);
      delay(myRan);
    }
    else{
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      Bmyservo.write(90-pos);
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  }
  for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    
    int light =analogRead(A0);
    if(light<5){
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      Bmyservo.write(90-myRan*7);
      delay(myRan);
    }
    else{
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      Bmyservo.write(90-pos);
      delay(15);                       // waits 15ms for the servo to reach the position
    }
                          // waits 15ms for the servo to reach the position
  }

  Serial.print(light);
  Serial.println(">>Light");
}

