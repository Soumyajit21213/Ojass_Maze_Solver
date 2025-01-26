# Ojass Maze Solver

## Description
The **Ojass Maze Solver** is a project we created fro Techfest of NIT Jamshedpur and we won. It navigates and solves mazes using an Arduino-based robotic system. 

## Code Structure
Below is the detailed structure of the project files and their explanations:

```
Ojass_Maze_Solver
├── .DS_Store (system file, can be ignored)
├── LICENSE (license file, can be ignored per user request)
├── README.md (this file contains information about the project)
├── MOTOR_TEST
│   └── MOTOR_TEST.ino (Arduino sketch for testing motor functionalities)
├── Final_Code
│   └── Final_code.ino (Main Arduino sketch for solving the maze)
├── PID
│   └── PID.ino (Arduino sketch implementing PID control for smooth movement)
├── ULTRASONIC_VALUES
│   └── ULTRASONIC_VALUES.ino (Arduino sketch for testing ultrasonic sensor readings)
└── .git (contains Git-related metadata)
```

### Explanation of Each Code File

#### **MOTOR_TEST/MOTOR_TEST.ino**
- This sketch is used to test the functionality and performance of the motors.

#### **Final_Code/Final_code.ino**
- The main program for the maze-solving robot.

#### **PID/PID.ino**
-  Implements a PID (Proportional-Integral-Derivative) control algorithm for smooth and precise movement.

#### **ULTRASONIC_VALUES/ULTRASONIC_VALUES.ino**
-  Tests the functionality of the ultrasonic sensors.
-  
### Additional Notes
- **Requirement:**
  - To open the `.ino` files , you need [Arduino IDE](https://www.arduino.cc/en/software) (version 2.3.2 or later recommended).
- **Testing Order**: Follow this testing order to ensure smooth integration:
  1. Test motors using `MOTOR_TEST.ino`.
  2. Test ultrasonic sensors using `ULTRASONIC_VALUES.ino`.
  3. Calibrate PID control using `PID.ino`.
  4. Integrate and test the full system using `Final_code.ino`.



## Getting Started

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/Soumyajit21213/Ojass_Maze_Solver.git
   ```

2. **Navigate to the Folder:**

   ```bash
   cd Ojass_Maze_Solver
   ```

---

## Contributions

Contributions are welcome! If you have suggestions or improvements, feel free to fork the repository and create a pull request.

---

## Contact

If you have any questions or need assistance, please feel free to reach out:

- **Author:** Soumyajit Samanta
- **Email:** [Soumyajit2121@gmail.com](mailto\:soumyajit2121@gmail.com)
