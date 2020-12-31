// include libraries for SSD1306 display connected to I2C (SDA, SCL pins)
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Setup TMP36, where the transfer function is:
// Vout[mV] = temperature[degC]*slope[mV] + offset[mV]
// temp[degC] = (V[mV] - offset[mV])/10[mV]
int TMP36=A0; // TMP36 on Analog Pin 0
int reading = 0;      // Variable to hold the analog reading from the TMP36, 10-bit decimal
int readingMin = 1023;      // Variable to hold the minimum analog reading from the TMP36, 10-bit decimal
int readingMax = 0;      // Variable to hold the maximum analog reading from the TMP36, 10-bit decimal
int vPin = 0;         // Variable to hold the pin voltage from the TMP35, mV
int vPinMin = 5000;         // Variable to hold the minimum pin voltage from the TMP35, mV
int vPinMax = 0;         // Variable to hold the maximum pin voltage from the TMP35, mV
int tempC = 0;     // Variable to hold the temperature, degC
int tempC_min = 150;     // Variable to hold the minimum temperature, degC
int tempC_max = -40;     // Variable to hold the maximum temperature, degC
int tempF = 0;     // Variable to hold the temperature, degF
const int textSize = 1; // Size of text to use in display
float slope = 0.5;        // slope of line for oscilloscope
float intercept = 0;      // intercept of line for oscilloscope
float verticalPosition = 32; // Vertical pixel position of oscilloscope, initialized to be off the 128x32 screen
float horizontallPosition = 128; // Vertical pixel position of oscilloscope, initialized to be off the 128x32 screen

void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  //display.clearDisplay();
}

void loop() {
  // Read the pin value from the temperature sensor
  reading = analogRead(TMP36);
  // This 10-bit reading will range between 0-1023 to represent 0-5V.
  // So divide by 1024 to get the fraction of 5V
  // Then multiply by 5000 to get the voltage in mV
  vPin = (reading) * (5000/1024);
  // Subtract the offset(mV) and divide by the slope(mV) to convert into degC
  tempC = (vPin - 500) / 10;
  // now convert to Fahrenheight
  tempF = (tempC * 9.0 / 5.0) + 32.0;

  // Stats
  readingMin = min(readingMin,reading);
  readingMax = max(readingMax,reading);
  vPinMin = min(vPinMin,vPin);
  vPinMax = max(vPinMax,vPin);
  tempC_min = min(tempC_min,tempC);
  tempC_max = max(tempC_max,tempC);
  
  // Write to display
  display.clearDisplay();

  display.setTextSize(textSize);
  display.setTextColor(WHITE);
  
  display.setCursor(0, 0);
  display.print("reading = ");display.print(reading);
  display.print(",");display.print(readingMin);
  display.print(",");display.print(readingMax);
  
  display.setCursor(0, 8);
  display.print("vPin = ");display.print(vPin);
  display.print(",");display.print(vPinMin);
  display.print(",");display.print(vPinMax);
  
  display.setCursor(0, 16);
  display.print("tempC = ");display.print(tempC);
  display.print(",");display.print(tempC_min);
  display.print(",");display.print(tempC_max);
  
  display.setCursor(0, 24);
  display.print("tempF = ");display.print(tempF);

  display.display();

  delay(250);

}
