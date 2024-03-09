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
- display: initializes the LCD display
- interface: prints relevant info to the LCD display
- leds: 

### Hardware

### Testing

### Other Important Details

The Nucleo F429ZI is based on the STM32 microcontroller. Currently, no good libraries exist to drive Neopixels on the Nucleo board. Thus, an external Arduino Micro was used to drive the Neopixels and interface with the Nucleo controller. The provided 'FinalProjectCode.ino' file should be uploaded to the Arduino in order to drive the Neopixels.
