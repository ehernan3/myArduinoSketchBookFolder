class Temperature {
  #include "classMovingAverage.h"
  // Members
  public:
  int reading;
  float vPin;
  float tempC_current;
  
  private:
  // These seem to be private
  const byte pin;
  float VCC_mV = 4900;// Actual voltage supplied to the TMP36 from the Arduino(measured with multimeter), mV
  
  // Constructor
  public:
  Temperature(byte attachTo):
    // The colon syntax allows you to initialise things inside your class that themselves have constructors
    // which we will be doing later.
    pin(attachTo)
    {
  }
  
  // Methods
  void setup(){
    // Composition: Temperature has an instance of MovingAverage
  }
  void loop(){
  // Read the pin value from the temperature sensor
  reading = analogRead(pin);
  vPin = (reading) * (VCC_mV/1024);
  // Subtract the offset(mV) and divide by the slope(mV) to convert into degC
  tempC_current = (vPin - 500) / 10.0;
  }
};
