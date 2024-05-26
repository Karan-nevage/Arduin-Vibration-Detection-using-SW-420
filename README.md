# Arduin-Vibration-Detection-using-SW-420
# Vibration Detection System

## Overview
This project is a comprehensive vibration detection system designed to provide real-time alerts. It leverages the capabilities of an Arduino Pro Mini to process sensor data and control output devices. Upon detecting vibrations, the system triggers a buzzer for an auditory alert, lights up a red LED for a visual alert, and displays a message on an OLED screen for a textual alert. When no vibration is detected, a green LED is lit up, indicating the system is in a standby state.

## Project Components and Their Use
- **Arduino Pro Mini:** The microcontroller that processes sensor data and controls the output devices.
- **SW-420 Vibration Sensor:** Detects vibrations and sends a signal to the Arduino.
- **Buzzer:** Provides an auditory alert when vibrations are detected.
- **Red LED:** Provides a visual alert by lighting up when vibrations are detected.
- **Green LED:** Lights up when no vibration is detected, indicating the system is in a standby state.
- **OLED Display (128x64, I2C):** Displays messages indicating whether vibrations are detected or not.

## Circuit Connection
- **Vibration Sensor:** The SW-420 sensor's VCC, GND, and DO pins are connected to the Arduino's VCC, GND, and digital pin 2, respectively.
- **Buzzer:** The buzzer's positive and negative terminals are connected to the Arduino's digital pin 3 and GND, respectively.
- **Red LED:** The LED's anode and cathode are connected to the Arduino's digital pin 4 and GND, respectively, with a suitable current-limiting resistor.
- **Green LED:** The LED's anode and cathode are connected to the Arduino's digital pin 5 and GND, respectively, with a suitable current-limiting resistor.
- **OLED Display:** The display's SDA and SCL pins are connected to the Arduino's SDA and SCL pins, respectively. The VCC and GND pins are connected to the Arduino's VCC and GND, respectively.

## Program Explanation
The Arduino program continuously reads the output from the SW-420 sensor. If the sensor detects vibration, the Arduino activates the buzzer and the red LED, and displays a "Vibration Detected!" message along with a bell icon on the OLED display. If no vibration is detected, the Arduino lights up the green LED and displays a "No Vibration Detected" message on the OLED display. The program uses the Adafruit_SSD1306 and Adafruit_GFX libraries to control the OLED display.
