# Smart Watering System
In this code contains a code to program the NodeMCU ESP32 microcontroller. In this program code, it is used to create a system to monitor soil moisture and make a switch to turn off or turn on a water pump, besides using a switch the water pump will run automatically according to the detection from the soil moisture sensor. When the soil moisture sensor reads dry soil, the water pump will automatically turn on, when the soil is wet, the sensor will send data and process it to turn off the water pump. Apart from using an automated system, here we also use manual switches via the Blynk application


## Install the ESP32 Driver
1. Download the installer from this repository
2. Plug the USB in ESP32 and connect to laptop via USB
3. Open the file

## Step to install Arduino IDE
1. Download Arduino IDE from this Repository
2. Install like usually
3. Ready to use

## Add a Preference ESP32 in Arduino IDE
Preference : https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json Copy this preference

1. Open the Arduino IDE
2. Click the File -> Preferences
3. Then paste the url in "Additional boards manager URLs"
4. Click "Ok"

## Install ESP32 board in Arduino IDE
1. Click the Tools -> Board -> Boards manager
2. Search your ESP32 in "Filter your search..."
3. When you find the ESP32, then click Install
4. Wait for a minute

## Reference to test Relay and Soil Moisture
Soil Moisture Testing : https://esp32io.com/tutorials/esp32-soil-moisture-sensor
Relay Testing : https://esp32io.com/tutorials/esp32-relay

## Wiring a component
1. NodeMCU ESP 32 - Soil Moisture :
  A. Vin - VCC
  B. GND -GND
  C. D34 - A0

2. NodeMCU ESP 32 - Relay
  A. Vin - VCC
  B. GND - GND
  C. D14 - IN

3. Vin NodeMCU ESP 32 - terminal 1 relay
4. Red Cable Water Pump - terminal 2 Relay
5. Black Cable water Pump - GND NodeMCU ESP 32

Note : When you upload the code, don't forget to press Boot button in ESP32


