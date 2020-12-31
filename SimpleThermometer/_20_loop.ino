void loop() {
  read_temp();

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
