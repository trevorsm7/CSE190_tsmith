#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LSM9DS0.h>
#include <Adafruit_Sensor.h>  // not used in this demo but required!

// i2c
Adafruit_LSM9DS0 lsm = Adafruit_LSM9DS0();

void setupSensor()
{
  // 1.) Set the accelerometer range
  lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_2G);
  //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_4G);
  //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_6G);
  //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_8G);
  //lsm.setupAccel(lsm.LSM9DS0_ACCELRANGE_16G);
  
  // 2.) Set the magnetometer sensitivity
  lsm.setupMag(lsm.LSM9DS0_MAGGAIN_2GAUSS);
  //lsm.setupMag(lsm.LSM9DS0_MAGGAIN_4GAUSS);
  //lsm.setupMag(lsm.LSM9DS0_MAGGAIN_8GAUSS);
  //lsm.setupMag(lsm.LSM9DS0_MAGGAIN_12GAUSS);

  // 3.) Setup the gyroscope
  lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_245DPS);
  //lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_500DPS);
  //lsm.setupGyro(lsm.LSM9DS0_GYROSCALE_2000DPS);
}

void setup() 
{
  Serial.begin(9600);
  
  // Try to initialise and warn if we couldn't detect the chip
  if (!lsm.begin())
  {
    Serial.println("Oops ... unable to initialize the LSM9DS0. Check your wiring!");
    while (1);
  }
  
  // Output in CSV format
  Serial.println("a.x, a.y, a.z, m.x, m.y, m.z, g.x, g.y, g.z");
}

void loop() 
{
  lsm.read();

  // Accel x, y, z, Mag x, y, z, Gyro x, y, z
  Serial.print((int)lsm.accelData.x); Serial.print(", ");
  Serial.print((int)lsm.accelData.y); Serial.print(", ");
  Serial.print((int)lsm.accelData.z); Serial.print(", ");
  Serial.print((int)lsm.magData.x); Serial.print(", ");
  Serial.print((int)lsm.magData.y); Serial.print(", ");
  Serial.print((int)lsm.magData.z); Serial.print(", ");
  Serial.print((int)lsm.gyroData.x); Serial.print(", ");
  Serial.print((int)lsm.gyroData.y); Serial.print(", ");
  Serial.println((int)lsm.gyroData.z);
  
  //Serial.print("Temp: "); Serial.print((int)lsm.temperature);    Serial.println(" ");
  delay(50);
}
