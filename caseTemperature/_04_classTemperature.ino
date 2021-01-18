class Temperature {
  // Constructor
  public:
  Temperature (int p){
    pin = p;
  }
  // Methods
  void read(void){
  // Read the pin value from the temperature sensor
  analogRead(pin);  
  }
  
  // Members
  private:
  int pin;
};
