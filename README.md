# Driver Drowsiness Detection and Alert System

## Overview
This project is designed to detect driver drowsiness using two MPU-6050 sensors and a Raspberry Pi with a camera module. The system monitors the angle rotated by the steering wheel and analyzes driver drowsiness based on the number of blinks per second. If drowsiness is detected, the system sends a signal to the Arduino to implement the braking system, ensuring the driver's safety.

## Components
- Arduino Uno
- Two MPU-6050 sensors
- Raspberry Pi
- Raspberry Pi Camera Module
- Breadboard and jumper wires
- Resistors and capacitors (as needed)
- Computer with Python and OpenCV installed

## System Architecture

### Arduino
- Reads data from two MPU-6050 sensors to monitor the angle rotated by the steering wheel.
- Processes this data for 10 seconds and sends the results to the Raspberry Pi.

### Raspberry Pi
- Receives data from the Arduino and uses the camera module to analyze the driver's eye movements using OpenCV.
- If drowsiness is detected, it sends a signal back to the Arduino.

### Braking System
- Activated by the Arduino when a drowsiness signal is received from the Raspberry Pi.

# How to Run

## Arduino Setup:
1. Connect the two MPU-6050 sensors to the Arduino.
2. Upload the Arduino code to the Arduino Uno.

## Raspberry Pi Setup:
1. Attach the camera module to the Raspberry Pi.
2. Install necessary Python packages:
    - OpenCV (`cv2`)
    - `dlib`
    - `scipy`
3. Download the `shape_predictor_68_face_landmarks.dat` file and place it in the working directory.
4. Run the Python script on the Raspberry Pi.

## System Integration:
1. Ensure the Arduino and Raspberry Pi are connected and can communicate.
2. Test the system to ensure it correctly detects drowsiness and activates the braking system.

## Conclusion
This project provides a comprehensive system for detecting driver drowsiness and taking necessary actions to prevent accidents. By integrating sensors and computer vision techniques, it enhances driver safety and contributes to smarter vehicle systems.
