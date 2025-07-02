# 🖥️ Wireless Input System for Handicapped People

This project demonstrates a gesture-based wireless input device designed to help handicapped individuals interact with computers easily, without the use of a traditional keyboard or mouse. The system uses an accelerometer to detect hand movements and translates them into cursor movements and click actions on the computer.

---

## 🧠 Project Description

Computers play a vital role in day-to-day communication and interaction. Typically, devices like keyboards and mice are required to interface with a computer. These input devices range from traditional wired modules to more advanced IR or VR-based systems. However, such devices are often challenging or unusable for people with physical disabilities.

In this project, we propose a **gesture-based wireless input system** tailored for **handicapped users**, providing an accessible and low-cost alternative to traditional input devices. While there are existing solutions like trackball devices, camera-based mice, and Braille gloves, they tend to be expensive or complicated to use.

Our system leverages an **accelerometer sensor** to detect hand or wrist gestures. These gestures are captured and processed by a **microcontroller**, which then sends the corresponding signals to a computer via **UART (serial communication)**. A custom application on the computer receives this data and performs the appropriate mouse or keyboard actions.

### 🔑 Key Features:
- The **accelerometer** acts as a virtual cursor.
- **Double flicking** the sensor triggers a click action.
- Compact, low-cost, and easy to use.
- Designed to enhance digital accessibility for users with limited mobility.

---

## 📂 Project Structure

│
├── main.c               
├── docs/
 ── circuit-diagram.png   
│   
├── README.md            
├── LICENSE                   

## 🔧 Technical Details

- **Microcontroller**: AT89S52 (8051 architecture)
- **Clock Frequency**: 11.0592 MHz
- **Communication**: UART @ 9600 baud rate
- **Display**: 16x2 LCD (data lines mapped to Port 2)
- **Sensor**: Accelerometer (e.g., ADXL335 or MPU6050)
- **Programming Language**: Embedded C (Keil uVision)


