# Dual-Sensor Temperature & Humidity Monitoring System

A dual-sensor environmental monitoring system built and presented at the NEN E-Week '16 Technical Exhibition at the Institute of Engineering & Management, developed as a two-member group project during Bachelor's studies.

## Hardware Components

- GY-BME280 sensor — temperature and humidity measurement
- DHT22 (AM2302) sensor — temperature and humidity measurement
- Arduino NANO — central microcontroller
- IIC/I2C Serial Interface Adapter Module
- 16x2 LCD display — real-time data display
- Bluetooth module — wireless data transmission to mobile app

## How It Works

Two sensors measure temperature and humidity simultaneously, providing redundant readings that improve measurement reliability and accuracy compared to single-sensor systems. The Arduino NANO processes readings from both sensors and displays real-time data on the LCD screen via the I2C adapter. During the exhibition, a Bluetooth module transmitted live sensor data wirelessly to a mobile application, allowing visitors to view readings directly on their phones.

## Key Features

- Dual-sensor redundancy for improved measurement accuracy
- Real-time data display on 16x2 LCD
- Bluetooth wireless transmission to mobile application
- Compact PCB-mounted design

## Exhibition

Presented at NEN E-Week Technical Exhibition, February 2016, Institute of Engineering & Management, Kolkata.
