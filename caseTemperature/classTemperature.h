class Temperature {
  #include "classMovingAverage.h"
  #include <movingAvg.h>                  // https://github.com/JChristensen/movingAvg
  // Members
  private:
  const uint8_t SENSOR_PIN;
  float VCC_mV;// Actual voltage supplied to the TMP36 from the Arduino(measured with multimeter), mV
  // Generally, you should use "unsigned long" for variables that hold time
  // The value will quickly become too large for an int to store
  unsigned long previousMillis; // will store last time LED was updated
  int long interval;   // interval at which to update the sensor reading(milliseconds)
  MovingAverage filter; // Declaring a variable, filter, as an instance of the class
  movingAvg avgTemp;    // Declaring a variable, avgTemp, as in instance of the class
  
  public:
  int reading;
  float vPin;
  float tempC_current;
  float tempC_filtered;
    
  // Constructor
  public:
  Temperature(byte attachTo):
    // The colon syntax allows you to initialise things inside your class that themselves have constructors
    // which we will be doing later.
    SENSOR_PIN(attachTo),
    filter(0.0), // Initialize the filter with zeros
    avgTemp(10)  // Instantiate the moving average object with 10 samples
    {
  }
  
  // Methods
  void setup(){
    VCC_mV = 4900;
    previousMillis = 0;
    interval = 500;
    //avgTemp.begin();
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
      int tC100 = readTMP36(SENSOR_PIN);  // read the sensor
      tempC_current = tC100/100;
      
      // Update the filtered value
      //tempC_filtered = filter.Update((vPin - 500) / 10.0);
      } // end of the If statement
      } // end of the loop
    
    long readTMP36(int muxChannel){
      long uV = (analogRead(muxChannel) * 5000000L + 512) / 1024;    //microvolts from the TMP36 sensor
      return (uV - 500000 + 50) / 100;
      }
};
