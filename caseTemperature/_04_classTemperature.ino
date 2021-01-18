class Temperature {
  const byte pin;
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
  analogRead(pin);  
  }
  
  // Members
  private:
};
