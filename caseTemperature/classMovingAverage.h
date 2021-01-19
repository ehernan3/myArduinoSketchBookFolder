class MovingAverage {
  // Constructor
  public:
  MovingAverage(const float InitialValue)
    {
      k = 0;
      for (int i = 0; i < NSAMPLES; i++) 
      {
        samples[i] = 0.0;  
      }
      mean = Update(InitialValue);
    }

    // Destructor
    ~MovingAverage() {}

    // Method
    float Update(const float NewValue)
    {
        // make space for new value
        for (int i = k; i < NSAMPLES-1; i++) {
          samples[i+1] = samples[i];
        }
        samples[k] = NewValue;
        float sum = 0;  
        for (int i = 0; i < k + 1; i++) {
          sum += samples[i];  
        }
        mean = sum / (k+1);
        k = (k+1) % NSAMPLES;

        return mean;
    }
    
    void setup() {
    }

    void loop() {
    }
    // Members
    private:
    int NSAMPLES;// = 10;          // Number of samples for the MovingAverage class
    float mean;
    float samples[10];  // Can't use sample[NSAMPLES] here because you don't understand this error: invalid use of non-static data member 'Temperature::MovingAverage::NSAMPLES
    int k;
};
