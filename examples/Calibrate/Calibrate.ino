/******************************************************************************
 *  Calibrate
 *  An example sketch that calibrates the compass.
 *
 *  Tested with the Compass Module - HMC6352 Breakout from SparkFun Electronics
 *  http://www.sparkfun.com/products/7915
 ******************************************************************************/

#include <Wire.h>
#include <HMC6352.h>


void setup()
{
  Wire.begin();
  Serial.begin(9600);

  // must be at least 6 seconds
  int numSeconds = 10;

  HMC6352.Wake();

  Serial.println("Starting calibration in ");
  for (int i=5; i>0; i--) {
    Serial.println(i);
    delay(1000);
  }
  Serial.println("Calibrating ....");

  HMC6352.BeginCalibration();
  for (int i=1; i<=numSeconds; i++) {
    Serial.print(i);
    Serial.print(" of ");
    Serial.println(numSeconds);
    delay(1000);
  }
  HMC6352.EndCalibration();

  Serial.println("Calibration completed ....");

  HMC6352.Sleep();
}

void loop()
{
    delay(1000);
}
