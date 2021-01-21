void read_temp(){
  // Read the pin value from the temperature sensor
  reading = analogRead(TMP36_1);
    // This 10-bit reading will range between 0-1023 to represent 0-5V.
  // So divide by 1024 to get the fraction of 5V
  // Then multiply by 5000 to get the voltage in mV
  vPin = (reading) * (VCC_mV/1024);
  // Subtract the offset(mV) and divide by the slope(mV) to convert into degC
  tempC = (vPin - 500) / 10.0;
  // Update the moving average with a new value, where new value is (vPin - 500) / 10
  // Consider applying the moving average to the pin reading, far upstream as possible.
  ps0_temp = ps0_filter.Update((vPin - 500) / 10);
  // now convert to Fahrenheight
  tempF = (ps0_temp * 9.0 / 5.0) + 32.0;

// This code should never be repeated like this. Make it a class and instantiate it twice.

  // Read the pin value from the temperature sensor
  reading = analogRead(TMP36_2);
    // This 10-bit reading will range between 0-1023 to represent 0-5V.
  // So divide by 1024 to get the fraction of 5V
  // Then multiply by 5000 to get the voltage in mV
  vPin = (reading) * (VCC_mV/1024);
  // Subtract the offset(mV) and divide by the slope(mV) to convert into degC
  tempC = (vPin - 500) / 10.0;
  ps1_temp = ps1_filter.Update((vPin - 500) / 10);
  // now convert to Fahrenheight
  tempF = (ps1_temp * 9.0 / 5.0) + 32.0;
}
