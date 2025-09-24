# Smart Door Lock System — Arduino

This project implements a **smart door lock system** using an Arduino board, servomotors, and an LCD display.  
The system simulates the sequence of **unlocking a latch, opening a door, and then automatically closing and locking it again**, with user feedback provided on an LCD screen.  

---

## 🔧 Hardware Components  

- **Arduino Board** (e.g., Arduino Uno)  
- **LiquidCrystal_I2C LCD 16x2** (address `0x27`)  
- **Servo Motor (continuous rotation)** → acts as the **latch lock**  
- **Servo Motor (standard)** → controls the **door opening/closing**  
- **Wires & power supply**  

---

## ⚙️ Features  

1. **LCD Feedback**  
   - Displays countdown before door opening.  
   - Shows each action step: unlocking, opening, closing, locking.  
   - Ends with `"Cycle complete"`.  

2. **Automated Door Sequence**  
   - **Countdown (5 seconds)** → user sees `"Door opening in: 5...1"`.  
   - **Unlock latch** → continuous servo rotates briefly to simulate unlocking.  
   - **Open door** → standard servo moves to an open position.  
   - **Close door** → servo rotates back to closed position.  
   - **Lock latch** → latch servo rotates back to locked position.  

3. **Cyclic Operation**  
   - The system continuously repeats the full cycle.  

---

## 🧠 Arduino Concepts Used  

- **Servo Library**  
  - `servoLatch` uses continuous rotation (write `0`, `90`, `180` for direction/stop).  
  - `servoDoor` uses angular positioning (`80–100°`).  

- **LCD with I2C**  
  - `LiquidCrystal_I2C` for display messages.  
  - `.setCursor()` for row/column positioning.  

- **Timing Control**  
  - `delay()` used for countdowns and action durations.  

---

## 📋 How It Works (Step by Step)  

1. LCD shows countdown → `"Door opening in: X"`.  
2. Unlock latch servo rotates briefly.  
3. Door servo rotates to simulate opening.  
4. Door servo rotates back to closed position.  
5. Latch servo rotates back to locked position.  
6. LCD displays `"Cycle complete"`.  
7. Cycle restarts.  

---

## 🛠️ Setup & Upload  

1. Connect components according to pins:  
   - `servoLatch → D9`  
   - `servoDoor → D10`  
   - `LCD I2C → SDA/SCL (A4/A5 on Arduino Uno)`  

2. Install required Arduino libraries:  
   - `Servo.h` (built-in)  
   - `LiquidCrystal_I2C.h` (via Library Manager)  

3. Upload the sketch to the Arduino.  

---


