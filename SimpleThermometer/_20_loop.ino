void loop() {
  // Build a timer that determines when to update the sensor reading
  /// without blocking the rest of the program with a delay().

  unsigned long currentMillis = millis(); // variable local to loop
  
  // If the following conditional is not met, nothing happens here, BUT
  // the rest of the loop will finish.
  if (currentMillis - previousMillis >= interval) {
    // If the conditions is met, perform these actions
    
    // save the last time you updated the sensor reading
    previousMillis = currentMillis;
    
    // Update the sensor reading
    read_temp();
    
    // Update the stats
    readingMin = min(readingMin,reading);
    readingMax = max(readingMax,reading);
    vPinMin = min(vPinMin,vPin);
    vPinMax = max(vPinMax,vPin);
    tempC_min = min(tempC_min,tempC);
    tempC_max = max(tempC_max,tempC);
  } // end of the If statement

  // The rest of the loop
  
  writeDisplay();
  
  // eliminated delay() here, yay!
}
