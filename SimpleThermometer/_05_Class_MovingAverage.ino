class MovingAverage {
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
    ~MovingAverage() {}
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
  private:
    float mean;
    float samples[NSAMPLES];
    int k;
    
};
