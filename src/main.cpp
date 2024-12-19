#include <Arduino.h>
#include <PID_v1.h>
#include <Servo.h>

  // PIN Assignments
#define trigPin 11            // Trig Pin Of HC-SR04
#define echoPin 12            // Echo Pin Of HC-SR04
#define ML_Forward  3        //left motor 1st pin
#define ML_Backward 2        //left motor 2nd pin
#define MR_Forward  6        //right motor 1st pin
#define MR_Backward 7        //right motor 2nd pin

Servo servo;

//declaration of functions
// double getDistance();
// int scanEnvironment();
// void turn(int angle);
// void controlMotors(int Lspeed, int Rspeed);

double Kp = 10;
double Ki = 0.1;
double Kd = 0.1;
 
double setPoint = 15.0; //Desired distance from obstacles (in cm)
double input = 0;
double output = 0;

// PID controller for the obstacle avoidance robot
PID Speed(&input, &output, &setPoint, Kp, Ki, Kd, REVERSE);

void setup() {
  Serial.begin(9600);

  // Set Motor Pins As O/P
  pinMode(ML_Forward,  OUTPUT);     
  pinMode(ML_Backward, OUTPUT);
  pinMode(MR_Backward, OUTPUT);
  pinMode(MR_Forward,  OUTPUT);

  // Ultrasonic Sensor PINS
  pinMode(trigPin, OUTPUT); // Set Trig Pin As O/P To Transmit Waves
  pinMode(echoPin, INPUT);  //Set Echo Pin As I/P To Receive Reflected Waves

  // Servo Pin assignment
  // servo.attach(10);


  Speed.SetMode(AUTOMATIC);
  Speed.SetOutputLimits(-255, 255);
  Speed.SetTunings(Kp, Ki, Kd);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  input = (duration * 0.034) / 2;
  Speed.Compute();

  if(output < 0){
//backward
    digitalWrite(ML_Forward, LOW);
    digitalWrite(ML_Backward, HIGH);

    digitalWrite(MR_Forward, LOW);
    digitalWrite(MR_Backward, HIGH);
    delay(1000);
//STOP
    analogWrite(ML_Forward, 0);
    digitalWrite(ML_Backward, LOW);
    analogWrite(MR_Forward, 0);
    digitalWrite(MR_Backward, LOW);
    delay(1000);
// Move LEFT

    analogWrite(ML_Forward, 0);
    digitalWrite(ML_Backward, HIGH);
    analogWrite(MR_Forward, 255);
    digitalWrite(MR_Backward, LOW);
    delay(100);
  } else {
    analogWrite(ML_Forward, output);
    digitalWrite(ML_Backward, LOW);
    analogWrite(MR_Forward, output);
    digitalWrite(MR_Backward, LOW);
  }


  Serial.print("Distance: ");
  Serial.print(input);
  Serial.print(" cm, PID Output: ");
  Serial.println(output);

  delay(50);
}