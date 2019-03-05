int sign(float num){
  return (num > 0) - (num < 0);
}

float getTime() {
  return millis();
}

float updateAngleKalman(){
  double looptime = (double)(micros() - timer) / 1000000; // Calculate delta time
  timer = micros();
  getIMUReadings();
  float roll = atan2(AcZ, sign(AcY) * sqrt((AcX * AcX) + (AcY * AcY)) ) * 180 / PI;
  double rollRate = -1*GyX;
  xAngle = kalmanCalculate(roll, rollRate, looptime, xAngle);
}

float getAngleIMU() {
  return xAngle;
}

float getAnglePot(){
  float results;
  results = adsLoadXPot.getConversionP2N3();
  return results;
}

float getForce() {
  float results;
  results = adsLoadXPot.getConversionP0N1();
  return results;
}

float getForceX() {
  float results;
  results = adsLoadXPot.getConversionP0N1();
  return results;
}

float getForceY() {
  float results;
  results = adsLoadY.getConversionP0N1();
  return results;
}

String getLocation() {
  GPS.parse(GPS.lastNMEA());
  if (GPS.fix) {
    return (String(GPS.latitudeDegrees, 4) + "," + String(GPS.longitudeDegrees, 4));
  }
  else {
    return "No GPS";
  }
}

String getTimeStamp() {
  GPS.parse(GPS.lastNMEA());
  return "Time: " + String(GPS.hour, DEC) + ":" +
         String(GPS.minute, DEC) + ":" +
         String(GPS.seconds, DEC) + "." +
         String(GPS.milliseconds) + "Date: " +
         String(GPS.day, DEC) + "/" +
         String(GPS.month, DEC) + "/20" +
         String(GPS.year, DEC);
}

float getTemp() {
  return am2315.readTemperature();
}

float getHumidity() {
  return am2315.readHumidity();
}

void getIMUReadings(){
  lsm.readAccel();
  AcX = (float)lsm.calcAccel(lsm.ax);
  AcY = (float)lsm.calcAccel(lsm.ay);
  AcZ = (float)lsm.calcAccel(lsm.az);
  lsm.readGyro();
  GyX = (float)lsm.calcGyro(lsm.gx);
  GyY = (float)lsm.calcGyro(lsm.gy);
  GyZ = (float)lsm.calcGyro(lsm.gz);
}

//Kalman module
float kalmanCalculate(float newAngle, float newRate, double looptime, float angle)
{
  double dt = double(looptime);
  angle += dt * (newRate - xBias);
  P0 += -1 * dt * (P2 + P1) + QAngle * dt;
  P1 -= dt * P3;
  P2 -= dt * P3;
  P3 += QGyro * dt;
  y = newAngle - angle;
  S = P0 + RAngle;
  K0 = P0 / S;
  K1 = P2 / S;
  angle +=  K0 * y;
  xBias  +=  K1 * y;
  P0 -= K0 * P0;
  P1 -= K0 * P1;
  P2 -= K1 * P0;
  P3 -= K1 * P1;
  return angle;
}

void getGPS(boolean GPSLocation, boolean GPSTime) {
  GPS.parse(GPS.lastNMEA());
  if (GPSLocation) {
    getGPSLocation();
  }
  if (GPSTime) {
    getGPSTime();
  }
}


void getGPSLocation() {
  if (GPS.fix) {
    Serial.print("Location: ");
    Serial.print(GPS.latitude, 4); Serial.print(GPS.lat);
    Serial.print(", ");
    Serial.print(GPS.longitude, 4); Serial.println(GPS.lon);
    Serial.print("Location (in degrees, works with Google Maps): ");
    Serial.print(GPS.latitudeDegrees, 4);
    Serial.print(", ");
    Serial.println(GPS.longitudeDegrees, 4);
  }
  else {
    Serial.println("NO GPS FIX");
  }
}
void getGPSTime() {
  Serial.print("Time: ");
  Serial.print(GPS.hour, DEC); Serial.print(':');
  Serial.print(GPS.minute, DEC); Serial.print(':');
  Serial.print(GPS.seconds, DEC); Serial.print('.');
  Serial.println(GPS.milliseconds);
  Serial.print("Date: ");
  Serial.print(GPS.day, DEC); Serial.print('/');
  Serial.print(GPS.month, DEC); Serial.print("/20");
  Serial.println(GPS.year, DEC);
}

// Interrupt is called once a millisecond, looks for any new GPS data, and stores it
SIGNAL(TIMER0_COMPA_vect) {
  char c = GPS.read();
  // if you want to debug, this is a good time to do it!
#ifdef UDR0
  if (GPSECHO)
    if (c) UDR0 = c;
  // writing direct to UDR0 is much much faster than Serial.print
  // but only one character can be written at a time.
#endif
}

void useInterrupt(boolean v) {
  if (v) {
    // Timer0 is already used for millis() - we'll just interrupt somewhere
    // in the middle and call the "Compare A" function above
    OCR0A = 0xAF;
    TIMSK0 |= _BV(OCIE0A);
    usingInterrupt = true;
  } else {
    // do not call the interrupt function COMPA anymore
    TIMSK0 &= ~_BV(OCIE0A);
    usingInterrupt = false;
  }
}
