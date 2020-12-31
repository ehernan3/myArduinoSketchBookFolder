void loop() {
  // Read the pin value from the temperature sensor
  reading = analogRead(TMP36);
  // This 10-bit reading will range between 0-1023 to represent 0-5V.
  // So divide by 1024 to get the fraction of 5V
  // Then multiply by 5000 to get the voltage in mV
  vPin = (reading) * (5000/1024);
  // Subtract the offset(mV) and divide by the slope(mV) to convert into degC
  tempC = (vPin - 500) / 10;
  // now convert to Fahrenheight
  tempF = (tempC * 9.0 / 5.0) + 32.0;

  // Stats
  readingMin = min(readingMin,reading);
  readingMax = max(readingMax,reading);
  vPinMin = min(vPinMin,vPin);
  vPinMax = max(vPinMax,vPin);
  tempC_min = min(tempC_min,tempC);
  tempC_max = max(tempC_max,tempC);

  writeDisplay();

  delay(loopDelay);

}
