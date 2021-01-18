// include libraries for SSD1306 display connected to I2C (SDA, SCL pins)
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "classTemperature.h"
#include "classMovingAverage.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Declare constants
const int textSize = 1; // Size of text to use in display

// Instantiate
Temperature ps0(A0);
Temperature ps1(A1);

 void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  
 ps0.setup();
 ps1.setup();
}
void loop() {
  // put your main code here, to run repeatedly:
  ps0.loop();
  ps1.loop();
  writeDisplay(ps0,ps1);
}
void writeDisplay(Temperature ps0,Temperature ps1){
  // Write to display
  display.clearDisplay();

  display.setTextSize(textSize);
  display.setTextColor(WHITE);
  
  display.setCursor(0, 0);
  display.print("ps0.reading = ");display.print(ps0.reading);
  //display.print(",");display.print(readingMin);
  //display.print(",");display.print(readingMax);
  
  display.setCursor(0, 8);
  display.print("ps0.vPin = ");display.print(ps0.vPin);
  //display.print(",");display.print(vPinMin);
  //display.print(",");display.print(vPinMax);
  
  display.setCursor(0, 16);
  display.print("ps0.current = ");display.print(ps0.tempC_current);
  //display.print("tempC_filtered = ");display.print(tempC_filtered,1);
  //display.print(",");display.print(tempC_min);
  //display.print(",");display.print(tempC_max);
  
  display.setCursor(0, 24);
  display.print("ps1.current = ");display.print(ps1.tempC_current);
  //display.print("tempF_filtered = ");display.print(tempF_filtered,1);

  display.display();
}
