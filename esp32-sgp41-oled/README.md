# ESP32-S3 SGP41 OLED Demo

This example project shows how to read air quality data from the Sensirion SGP41 sensor
and display the raw values on a 0.96" OLED (SSD1306 128x64 dots) using C++ on the
Arduino framework. Hardware power is controlled with a lever switch and a
rechargeable 18650 battery using a TP4056 charging module with overcharge
protection.

## Hardware

- **Microcontroller**: ESP32-S3 module
- **Gas sensor**: Sensirion SGP41 (I²C address `0x59`)
- **Display**: 0.96" OLED, SSD1306 controller, 128x64 pixels (I²C)
- **Power**: 18650 Li-Ion battery, TP4056 charger with protection, MTS-103 toggle
  switch to cut power

### Wiring

| ESP32-S3 Pin | SGP41 | OLED |
|--------------|-------|------|
| 3V3          | VCC   | VCC  |
| GND          | GND   | GND  |
| GPIO21 (SDA) | SDA   | SDA  |
| GPIO22 (SCL) | SCL   | SCL  |

Connect the battery to the TP4056 module, then to the MTS-103 switch, and finally
feed the ESP32's `VBAT` or `5V` input (according to your module). The charger
module prevents overcharging of the cell.

## Build

Use PlatformIO or the Arduino IDE with ESP32 core 2.0 or later. Required
libraries:

- `Adafruit SSD1306`
- `Adafruit GFX`
- `Sensirion I2C SGP41`

## Usage

Upload the sketch in `src/main.cpp` to your board. The display shows the raw VOC
and NOx signals reported by the SGP41 every second.
