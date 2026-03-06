# Environmental Monitoring System with Arduino, LCD, and Bluetooth

This project is an **Arduino-based environmental monitoring system**
that measures:

-   Temperature
-   Humidity
-   CO₂ concentration
-   NO₂ gas level

The system displays real-time readings on a **20x4 I2C LCD screen** and
also sends the data wirelessly using a **Bluetooth module (HC‑05 /
HC‑06)**.

It is useful for **air quality monitoring, indoor environment tracking,
and IoT experiments**.

------------------------------------------------------------------------

# Features

-   Real-time **temperature and humidity measurement**
-   **Air quality monitoring** using the MQ135 gas sensor
-   **CO₂ concentration estimation**
-   **NO₂ gas level estimation**
-   Data display on **20x4 I2C LCD**
-   **Wireless Bluetooth transmission**
-   Serial monitor output for debugging
-   Automatic updates every few seconds

------------------------------------------------------------------------

# Hardware Requirements

-   Arduino Uno (or compatible board)
-   MQ135 Gas Sensor
-   DHT11 Temperature & Humidity Sensor
-   20x4 I2C LCD Display
-   Bluetooth Module (HC-05 or HC-06)
-   Jumper wires
-   Breadboard (optional)

------------------------------------------------------------------------

# Libraries Used

The following Arduino libraries are required:

-   LiquidCrystal_I2C
-   MQ135
-   DHT11
-   SoftwareSerial

You can install them using the **Arduino Library Manager**.

------------------------------------------------------------------------

# Pin Configuration

  Component             Arduino Pin
  --------------------- -------------
  DHT11 Data            2
  MQ135 Analog Output   A2
  Bluetooth RX          10
  Bluetooth TX          11
  LCD I2C Address       0x27

Note: The LCD communicates via **I2C**, so it uses the Arduino's SDA and
SCL pins.

------------------------------------------------------------------------

# How the System Works

1.  The **DHT11 sensor** measures temperature and humidity.
2.  The **MQ135 sensor** reads air quality values.
3.  CO₂ concentration is calculated using temperature and humidity
    correction.
4.  NO₂ level is estimated from the MQ135 analog reading.
5.  Data is displayed on the **LCD screen**.
6.  The same data is transmitted through **Bluetooth** and printed in
    the **Serial Monitor**.

------------------------------------------------------------------------

# LCD Display Cycle

The LCD alternates between two screens:

Screen 1: Temperature and Humidity

Example: Temp:25C Hum:60%

Screen 2: CO₂ and NO₂ gas readings

Example: CO2:420 PPM NO2:15 ppm

------------------------------------------------------------------------

# Example Bluetooth Output

A Bluetooth terminal will receive data in this format:

    Temp:25,Hum:60,CO2:420,NO2:15
    Temp:26,Hum:58,CO2:430,NO2:14

------------------------------------------------------------------------

# Bluetooth Setup

1.  Connect the **HC‑05 / HC‑06 module** to the Arduino.
2.  Pair the module with your phone or computer.
3.  Open a Bluetooth terminal application such as **Serial Bluetooth
    Terminal**.
4.  Connect using **baud rate 9600**.
5.  Sensor data will begin streaming automatically.

------------------------------------------------------------------------

# Code Overview

Main parts of the code:

-   **DHT11** for temperature and humidity readings
-   **MQ135** for air quality measurement
-   **LiquidCrystal_I2C** for LCD control
-   **SoftwareSerial** for Bluetooth communication

The Arduino continuously reads sensor values and updates the display and
Bluetooth output.

------------------------------------------------------------------------

# Possible Improvements

-   Add **WiFi (ESP8266 / ESP32)** for cloud monitoring
-   Store measurements on an **SD card**
-   Create a **mobile application** to visualize data
-   Add more gas sensors (CO, NH3, etc.)
-   Send alerts when air quality becomes unsafe

------------------------------------------------------------------------

# Applications

-   Indoor air quality monitoring
-   Smart home environmental systems
-   School or science fair projects
-   IoT environmental sensing
-   Laboratory monitoring systems
