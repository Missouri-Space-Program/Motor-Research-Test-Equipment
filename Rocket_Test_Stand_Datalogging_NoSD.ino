
/* 
 *  This sketch is for MPS's rocket motor test datalogging sytem, it allows an HX711 sensor to be used with a DATAQ so there is no need for sd card collection.
 *  creator: Kendall Feist 10/6/2019
 */
#include <HX711.h> //This library can be obtained here http://librarymanager/All#Avia_HX711
#include <SPI.h>
#define calibration_factor 8980 //This value is obtained using the SparkFun_HX711_Calibration sketch
#define LOADCELL_DOUT_PIN  3
#define LOADCELL_SCK_PIN  2
#define DATAQ_pin 1 //arduino analog 1 is attached to channel on DATAQ and arduino gnd is connected
float reading;
float rawreading;
HX711 scale;

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(19200);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale.tare();  //Assuming there is no weight on the scale at start up, reset the scale to 0
}

void loop()
{
    rawreading = (scale.get_units(),1); //scale.get_units() returns a float
    reading = map(rawreading, 0, 490.5, 0, 255);
    Serial.println(scale.get_units(), 1); //scale.get_units() returns a float
    analogWrite(DATAQ_pin,reading);
}
