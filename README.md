# Line Follower Robot using Arduino and L298N

This project implements a basic **line follower robot** using an **Arduino Uno**, an **L298N motor driver**, and **IR sensors** for line detection. The robot follows a black line on a white surface using simple digital logic.

---

## 🚀 Features

- Follows a black line using 3 IR sensors (Left, Middle, Right)
- Controls two DC motors via the L298N dual H-bridge motor driver
- Adjusts movement based on sensor inputs: forward, left, right, or stop

---

## 🛠️ Hardware Required

| Component              | Quantity |
|------------------------|----------|
| Arduino Uno            | 1        |
| L298N Motor Driver     | 1        |
| DC Motors              | 2        |
| IR Sensors (Analog/Digital) | 3  |
| Power Supply (Battery) | 1        |
| Connecting Wires       | As needed |
| Chassis (robot body)   | 1        |

---

## 🔌 Pin Configuration

### Motor Driver (L298N):

| Function     | Arduino Pin |
|--------------|-------------|
| Enable A     | D10         |
| IN1 (Motor 1)| D9          |
| IN2 (Motor 1)| D8          |
| IN3 (Motor 2)| D7          |
| IN4 (Motor 2)| D6          |
| Enable B     | D5          |

### IR Sensors:

| Sensor  | Arduino Pin |
|---------|-------------|
| Left    | A0          |
| Right   | A1          |
| Middle  | A4          |

---

## ⚙️ How It Works

- **Forward**: Middle sensor sees black; left and right see white.
- **Left Turn**: Left sensor detects black (turn left to realign).
- **Right Turn**: Right sensor detects black (turn right to realign).
- **Stop**: All sensors detect black (end of line or junction).

---

## 🧠 Logic Flow

```text
If L=0, M=1, R=0 => Forward
If L=1, M=1/0, R=0 => Turn Left
If L=0, M=1/0, R=1 => Turn Right
If L=1, M=1, R=1 => Stop
