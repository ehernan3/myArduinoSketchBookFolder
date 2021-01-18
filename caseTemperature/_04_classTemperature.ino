class Temperature {
  const byte pin;
  // Constructor
  public:
  Temperature(byte attachTo):
    pin(attachTo)
    {
  }
  // Methods
  void read(void){
  // Read the pin value from the temperature sensor
  analogRead(pin);  
  }
  
  // Members
  private:
};
