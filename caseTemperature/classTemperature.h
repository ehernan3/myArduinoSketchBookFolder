class Temperature {
  const byte pin;
  int reading;
  float vPin;
  float VCC_mV = 4900;// Actual voltage supplied to the TMP36 from the Arduino(measured with multimeter), mV
  float tempC_current;        // Variable to hold the temperature, degC
  // Constructor
  public:
  Temperature(byte attachTo):
    pin(attachTo)
    {
  }
  // Methods
  void setup(){
    // Currently does nothing
  }
  void loop(){
  // Read the pin value from the temperature sensor
  reading = analogRead(pin);
  vPin = (reading) * (VCC_mV/1024);
  // Subtract the offset(mV) and divide by the slope(mV) to convert into degC
  tempC_current = (vPin - 500) / 10.0;
  }
  
  // Members
  private:
};
