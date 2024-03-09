Final Project: Eco-Friendly RGB Lighting
====================================================================================

### Authors
1. Nick DeBaise
2. Will Plante

Date submitted for review: 03/09/2024

### Behavior
Reads input from user adjusted potentiometers to determin the percentage of red, green, and blue light to emit from the led strip. Reads light level via LDR sensor to determin how much dimming shoukd be applied to the led strip based on natural light. PIR sensor detrmins if the room is occupied, and deactivates the led strip if unoccupied. Naturl light level and RGB levels displayed on LCD display

### Modules
- arduino: Facilitates communication between the NUCLEO Board and the Arduino Micro
- display: Initializes the LCD display
- interface: Prints relevant info to the LCD display
- leds: No current use (functianlity is now perfromed by the Arduino Micro)
- motion: Initializes and determins room occupancy
- sensors: Initializes and reads RGB potentiometers and LDR sensor

### Hardware
- 1 NUCLEO-F429ZI Microcontroller - Com Pin D10
- 1 Arduino Micro Microcontroller - Com Pin A4
- 1 NeoPixel RGB LED Strip - 12 (ARDUINO)
- 1 LCD Display (with potentiometer) - D0-D7, D8, D9 (NUCLEO)
- 1 PIR Motion Sensor - PG_0 (NUCLEO)
- 1 LDR Light Sensor - A0(NUCLEO) A3(ARDUINO)
- 3 Potentiometers
    - R: A3(NUCLEO) A0(ARDUINO)
    - G: A2(NUCLEO) A1(ARDUINO)
    - B: A1(NUCLEO) A2(ARDUINO)
  
### Testing
- Initial LED strip test
- Initial LCD display test
- LCD display with sensor value display functionality
- RGB strip with LDR dimming functionality
- RGB with potentiometer color change functionality
- RGB with PIR occupancy detection functionality

### Other Important Details

The Nucleo F429ZI is based on the STM32 microcontroller. Currently, no good libraries exist to drive Neopixels on the Nucleo board. Thus, an external Arduino Micro was used to drive the Neopixels and interface with the Nucleo controller. The provided 'FinalProjectCode.ino' file should be uploaded to the Arduino in order to drive the Neopixels.
