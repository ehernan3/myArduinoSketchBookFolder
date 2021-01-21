// Include library here, above class definition
#include <movingAvg.h>                  // https://github.com/JChristensen/movingAvg

// Begin class definition
class Temperature {

  // Members
  private:
  const uint8_t SENSOR_PIN;
  float VCC_mV;                 // Actual voltage supplied to the TMP36 from the Arduino(measured with multimeter), mV
  // Generally, you should use "unsigned long" for variables that hold time, because
  // the value will quickly become too large for an int to store
  unsigned long previousMillis; // variable to store last time TMP36 reading was updated
  int long interval;            // interval at which to update the sensor reading(milliseconds)
  movingAvg avgTemp;            // Declaring a variable, avgTemp, as in instance of the class
  
  public:
  int tempC_current;
  int tempC_filtered;
    
  // Constructor
  public:
  Temperature(byte attachTo):
    // The colon syntax allows you to initialise things inside your class that themselves have constructors
    // which we will be doing later.
    SENSOR_PIN(attachTo),
    avgTemp(10)         // Instantiate the moving average object with 10 samples
    {
  }
  
  // Methods
  void setup(){
    VCC_mV = 4900;      // Must be measured with voltmeter to verify reference voltage
    previousMillis = 0; // Initialize
    interval = 1000;    // 1 second loop. Read temperature every second, update average every second
    avgTemp.begin();    // Initialize avgTemp object
  }
  void loop(){
    // Build a timer that determines when to update the sensor reading
    // without blocking the rest of the program with a delay().
    
    unsigned long currentMillis = millis(); // variable local to loop
    
    // If the following conditional is not met, nothing happens here, BUT
    // the rest of the loop will finish.
    if (currentMillis - previousMillis >= interval) {
      // save the last time you updated the sensor reading
      previousMillis = currentMillis;
      
      // Read the pin value from the temperature sensor
      int tC100 = readTMP36(SENSOR_PIN);  // read the sensor, return value 100 * temperature in degC
      tempC_current = tC100/100;          // divide by 100 to get degC
      
      // Update the filtered value
      tempC_filtered = avgTemp.reading(tC100)/100;   // calculate the moving average, then divide by 100
      } // end of the If statement

      // Other statements executed during the loop, but outside the If statement
      
      } // end of the loop

    // Local function for reading the pin, taken from https://github.com/JChristensen/movingAvg
    long readTMP36(int muxChannel){
      long uV = (analogRead(muxChannel) * 5000000L + 512) / 1024;    //microvolts from the TMP36 sensor
      return (uV - 500000 + 50) / 100;
      }
};
