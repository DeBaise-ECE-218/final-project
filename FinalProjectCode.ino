//=====[Libraries]=============================================================
#include <Adafruit_NeoPixel.h>

//=====[Declaration of private defines]========================================
#define LED_PIN    12
#define LED_COUNT 30
#define RED_POT 18
#define BLUE_POT 20
#define GREEN_POT 19
#define LDR 21
#define DATA_IN 22

#define LDR_MAX_AVG_COUNT 25
#define SYSTEM_DELAY_TIME 10

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of private global objects]===============

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

int ldrCount = 0;
unsigned long ldrSum = 0;
int ldrReading = 0;

int redAnalog;
int blueAnalog;
int greenAnalog;
int ldrAnalog;
int dataIn;

unsigned long colors[3] = {255, 100, 0};

//=====[Declarations (prototypes) of private functions]========================

int mapPotToBrightness(int reading);
int mapPotToColor(int reading);

//=====[Implementations of public functions]===================================

//=====[Implementations of private functions]==================================

// Setup function
void setup() {
  Serial.begin(115200);
  delay(5000);
  strip.begin();
  strip.show();
  strip.setBrightness(20); // max = 255

  pinMode(DATA_IN, INPUT);
}

void loop() {
  // read in potentiometers and LDR
  redAnalog = analogRead(RED_POT);
  blueAnalog = analogRead(BLUE_POT);
  greenAnalog = analogRead(GREEN_POT);
  ldrAnalog = analogRead(LDR);
  dataIn = digitalRead(DATA_IN);

  // map readings to colors
  colors[0] = mapPotToColor(redAnalog);
  colors[1] = mapPotToColor(greenAnalog);
  colors[2] = mapPotToColor(blueAnalog);

  // average LDR to prevent flickering
  if(ldrCount > LDR_MAX_AVG_COUNT) {
    int val = ldrSum / ldrCount;
    ldrReading = mapPotToBrightness(abs(ldrSum / ldrCount));
    ldrSum = 0;
    ldrCount = 0;
  } else {
    ldrCount++;
    ldrSum += ldrAnalog;
  }
  
  // set each pixel on the strip
  for(int i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(colors[0],   colors[1],   colors[2]));
  }

  strip.setBrightness(ldrReading);

  if(dataIn == 1) {
    strip.show();
  } else {
    strip.clear();
    strip.show();
  }

  delay(SYSTEM_DELAY_TIME);
}

//Map the potentiometer reading to a value between 0-255 for colors
int mapPotToColor(int reading) {
  // reading is 0-675ish due to 3.3v
  // map from 0-675 to 0-255
  int val = map(reading, 0, 675, 0, 255);
  if(val < 0) return 0;
  if(val > 255) return 255;
  return val;
}

//Map the LDR reading to a value between 0-255 for brightness
int mapPotToBrightness(int reading) {
  int val = map(reading, 0, 1023, 0, 255);
  if(val < 0) return 255;
  if(val > 255) return 0;
  return 255 - val;
}

