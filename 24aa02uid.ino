uint32_t read_uid()
{
  uint32_t dval;
  const int uidaddr = 0b1010000;
  Wire.beginTransmission(uidaddr);
  Wire.write(0xFC);
  Wire.endTransmission();
  Wire.requestFrom(uidaddr, 4);
  dval = Wire.read();
  dval <<= 8;
  dval |= Wire.read();
  dval <<= 8;
  dval |= Wire.read();
  dval <<= 8;
  dval |= Wire.read();
  // Get the Manufacturer code and device code (just to check the chip is working)
  Wire.beginTransmission(uidaddr);
  Wire.write(0xFA);
  Wire.endTransmission();
  Wire.requestFrom(uidaddr, 2);
  byte mc = Wire.read();            // Manufacturer code should be 0x29
  byte id = Wire.read();            // Device code should be 0x41
  Serial.print(F("ID:"));
  Serial.print(dval);
  Serial.print(F(" "));
  Serial.print(mc, HEX);
  Serial.print(F(" "));
  Serial.println(id, HEX);
  return dval;
  
}
