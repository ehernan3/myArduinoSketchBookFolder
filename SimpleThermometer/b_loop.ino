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

  // Write to display
  display.clearDisplay();

  display.setTextSize(textSize);
  display.setTextColor(WHITE);
  
  display.setCursor(0, 0);
  display.print("reading = ");display.print(reading);
  display.print(",");display.print(readingMin);
  display.print(",");display.print(readingMax);
  
  display.setCursor(0, 8);
  display.print("vPin = ");display.print(vPin);
  display.print(",");display.print(vPinMin);
  display.print(",");display.print(vPinMax);
  
  display.setCursor(0, 16);
  display.print("tempC = ");display.print(tempC);
  display.print(",");display.print(tempC_min);
  display.print(",");display.print(tempC_max);
  
  display.setCursor(0, 24);
  display.print("tempF = ");display.print(tempF);

  display.display();

  delay(loopDelay);

}
