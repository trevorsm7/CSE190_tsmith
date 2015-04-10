void setup() {
  Serial.begin(9600);
  
  // Can use the AREF pin to supply a different upper range for the
  // analog input. The internal reference is ~1.6 volts.
  //analogReference(EXTERNAL);
  analogReference(INTERNAL);
}

void loop() {
  // Read from pin A1
  int inVal = analogRead(1);
  
  // Map the 10bit input value (~290 to ~1023 in our case) to an 8-bit
  // value (0 to 255) which the analogWrite function uses.
  int outVal = map(inVal, 290, 1023, 0, 255);
  outVal = min(max(outVal, 0), 255);
  
  // Periodically print the in/out values for debugging.
  static int counter = 0;
  if (++counter >= 1000)
  {
    Serial.print("inVal: ");
    Serial.print(inVal);
    Serial.print("  outVal: ");
    Serial.println(outVal);
    counter = 0;
  }
  
  // Write the value to a PWM pin (E3 in this case).
  analogWrite(3, outVal);
}
