# Wall-A

<p align="center">
  <img src="https://github.com/user-attachments/assets/3555e62d-1aaa-4b5d-8731-0cfbef4f45f1" />
  <img src="https://github.com/user-attachments/assets/90d81f08-54b4-4a88-bb8a-1460f06423a9" />
</p>


Wall - A is an Arduino-based vehicle bot designed to track and move away from obstacles and slows down when there's incoming obstacles. This project implements the PID controller and PID code to adjust the speed of the vehicle. This project is developed for the subject Feedback and Control Systems. Paired and collaborated with Andrey Fritz Solijon. 

## Table of Contents
  - [Overview](#overview)
  - [Hardware Components](#hardware-components)
  - [Features](#features)
  - [Platform/Environment Setup](#platformenvironment-setup)
  - [Usage](#usage)
  - [License](#license)

## Overview
  Block Diagram
  ![image](https://github.com/user-attachments/assets/2327669a-5010-4957-b7a5-c30a9bc6c6f5)
  Wall Avoidance or Obstacle Avoidance Robot also known as Wall-A is an Arduino-based project designed to slow down its speed based on the distance from the sensor to the obstacle. With the implementation of PID (Proportional, Integral, Derivative) controller. This controller uses real-time measurement through the use of sensors that adjust its speed based on the set point and the obstacles and learns to adjust the error based on multiple trials.
## Features
  - PID controller - precisely controls and adjusts its errors based on feedback through calculation of Kp(Proportional), Ki(Integral), Kd(Derivative).
  - Feedback-based Speed Regulator - uses feedback from the sensor to adjust its speed.
  - Arduino-based - affordable and easy to replicate, customizable hardware.
## Hardware Components

   ### Arduino Circuit Diagram
![image](https://github.com/user-attachments/assets/f921fb34-1ca7-4c70-b654-54d9b7dd2a63)
 
  Components needed to implement the project:
  
  1. Arduino Uno ( You can use any type of Arduino hardware)
      - Acts as the brain that controls the components through PID-implemented code
  2. HRCS04 Ultrasonic Sensor
      - Sensor for real-time measurement and feedback.
  3. SG90 Servo Motor
      - Allows rotational movement of the head with the sensor and scanning of the environment
  4. L298N Motor Driver
      - A driver for the motor wheels, enabling reverse and forward and dynamic control of speed
  6. Power Supply (6V) 
      - Power for the whole circuit and components
  8. 2 Geared Motors
      - Wheels for the movement of the robot
  10. Wires and Connectors
      - Ensure connection between the components and complete the circuit of the robot
## Platform/Environment Setup
  - Visual Studio Code PlatformIO Extension
    - Install PlatformIO Extension in Vscode. In this platform, you won't need the Arduino IDE application to upload your code to the Arduino Uno component.
  - Arduino IDE (Optional)
    - As an alternative of PlatformIO, install Arduino IDE application to upload your source code.
    - Note: You cannot clone the repository directly in Arduino IDE. Instead, manually copy the provided source code
  - Source Code
    - 
## Usage
  - Wall - A is used as a simulation in implementing PID controller and real-time feedback-based measurement of output (speed to be measured in this project). This simulation is a potential usage for cars, motorcycles, and any other vehicle in the street. This implementation and application of PID in road vehicles can significantly reduce accidents and damage over time. Though it's already existent in some vehicles but not yet really advertised worldwide.
## License
  - This project is under MIT License.
