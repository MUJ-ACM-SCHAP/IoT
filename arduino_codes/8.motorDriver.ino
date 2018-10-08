#include <AFMotor.h>
const int buzzerPin = 4;
const int trigPin = 9;
const int echoPin = 2;

long duration;
int distance;
AF_DCMotor motor1(1, MOTOR12_64KHZ);
AF_DCMotor motor2(2, MOTOR12_64KHZ);
AF_DCMotor motor3(3, MOTOR12_64KHZ);
AF_DCMotor motor4(4, MOTOR12_64KHZ);


void setup() 
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication

  motor1.setSpeed(250);
  motor2.setSpeed(250);
  motor3.setSpeed(250);
  motor4.setSpeed(250);
}


void loop() 
{

  
 
  while (Serial.available() > 0)
  {
    char inbyte = Serial.read();
  
    
    switch(inbyte){
      case 'r':  Serial.print(distance);Serial.print("~"); break;
      case 'f': back(); break;
      case 'd': forward(); break;
      case 'q': left(); break;
      case 'l': right();break;
      
      }
    
    digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
    
  }

 
}


void echo(){
 

  }
void forward()
{
 motor1.run(FORWARD);
 motor2.run(FORWARD);
 motor3.run(FORWARD);
 motor4.run(FORWARD);
 
}

void back()
{
  motor1.run(BACKWARD);
 motor2.run(BACKWARD);
 motor3.run(BACKWARD);
 motor4.run(BACKWARD);
}

void left()
{
  motor2.run(FORWARD);
 motor3.run(FORWARD);
 motor1.run(BACKWARD);
 motor4.run(BACKWARD);
}

void right()
{
  motor2.run(BACKWARD);
 motor3.run(BACKWARD);

 motor1.run(FORWARD);
 motor4.run(FORWARD);
}




