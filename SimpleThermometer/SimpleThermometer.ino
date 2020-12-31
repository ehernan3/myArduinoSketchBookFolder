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
float tempC_filtered;   // Final filtered temperatire, decC;
int tempC_min = 150;     // Variable to hold the minimum temperature, degC
int tempC_max = -40;     // Variable to hold the maximum temperature, degC
int tempF = 0;     // Variable to hold the temperature, degF
const int textSize = 1; // Size of text to use in display
float slope = 0.5;        // slope of line for oscilloscope
float intercept = 0;      // intercept of line for oscilloscope
float verticalPosition = 32; // Vertical pixel position of oscilloscope, initialized to be off the 128x32 screen
float horizontallPosition = 128; // Vertical pixel position of oscilloscope, initialized to be off the 128x32 screen
int loopDelay = 1000; // Delay for the loop
const int NSAMPLES = 15; // Number of samples for the MovingAverage class
