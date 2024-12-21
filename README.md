
---

# Simple Firefighter Robot Using Arduino UNO  

This repository contains the source code and instructions for building a firefighter robot using Arduino UNO. The robot is capable of detecting and extinguishing fires using IR sensors, a servo-controlled water pump, and an L298N motor driver for movement.

## Features  
- Fire detection using IR sensors.  
- Automatic fire extinguishing using a servo-controlled water pump.  
- Autonomous navigation using a dual-motor system.  
- Debugging information displayed via Serial Monitor.  

## Components  
1. **Arduino UNO**  
2. **L298N Motor Driver**  
3. **Flame Sensors (3)**  
4. **Mini Servo Motor**  
5. **(5 - 9V) Water Pump**
6. **Solder-less Breadboard**
7. **Power Supply**
8. **BO motors(4)**
9. **Chachies**
10. **Wheels(4)**
11. **Switch**
12. **Power Supply (Batteries)**
13. **Water tank / bottle**
14. **TIP-122 Transistor**
15. **104 pf capacitor**
16. **1K Resister**
17. **Jumper Wires**

## Pin Connections  

| **Component**         | **Arduino Pin** | **Description**              |  
|-----------------------|----------------|-----------------------------|  
| L298N Enable1         | 10             | Motor1 speed control (PWM)  |  
| L298N in1             | 9              | Motor1 forward              |  
| L298N in2             | 8              | Motor1 backward             |  
| L298N in3             | 7              | Motor2 forward              |  
| L298N in4             | 6              | Motor2 backward             |  
| L298N Enable2         | 5              | Motor2 speed control (PWM)  |  
| Flame Sensor (Right)     | A3             | Fire detection (Right)      |  
| Flame Sensor (Front)     | A1             | Fire detection (Front)      |  
| Flame Sensor (Left)      | A2             | Fire detection (Left)       |  
| Servo Motor           | A4             | Controls servo for water spray |  
| Water Pump            | A5             | Activates water pump        |  

## Code Explanation  
The code is designed to control the robot's motion and extinguish fire based on IR sensor readings:  
- **Flame Sensor Values**:  
  - If values are below thresholds, fire is detected.  
  - Robot positions itself and activates the water pump.  
- **Servo Motor**:  
  - Rotates to spray water over the fire.  
- **Motor Movement**:  
  - Moves forward, backward, or adjusts direction based on IR sensor inputs.  

## How to Use  
1. Connect the components as per the **Pin Connections** table.  
2. Upload the `code.c` to your Arduino UNO using the Arduino IDE.  
3. Power up the system.  
4. Monitor the Serial Monitor for debugging information.  
5. Place the robot in a test environment with a small fire (e.g., a candle).  

## Setup Instructions  
1. Download and install the [Arduino IDE](https://www.arduino.cc/en/software).  
2. Clone this repository:  
   ```bash  
   git clone https://github.com/your-repo-name/firefighter-robot.git  
   ```  
3. Open `code.c` in the Arduino IDE.  
4. Connect your Arduino UNO to your computer via USB.  
5. Select the correct board and COM port in the Arduino IDE.  
6. Click **Upload** to flash the code.  

## Safety Precautions  
- Ensure the robot operates in a controlled environment.  
- Avoid testing near flammable materials or large fires.  
- Always have an adult present during testing.

## Contribution  
Feel free to contribute to this project by submitting pull requests or reporting issues.  

## Author  
- **Name**: MANOJ KUMAR K
- **Name**: KUNDURU SRI CHARAN REDDY
- **Name**: JAGANNATH VUNGARALA
- **Name**: ASPATHRI MOHISIN
- **Name**: SINGIREDDY VIVEKANANDA REDDY
  

---
