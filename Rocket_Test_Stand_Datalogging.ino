/*
 The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 (for MKRZero SD: SDCARD_SS_PIN)
 */
#include <HX711.h> //This library can be obtained here http://librarymanager/All#Avia_HX711
#include <SPI.h>
#include <SD.h>

#define calibration_factor 8980 //This value is obtained using the SparkFun_HX711_Calibration sketch
#define LOADCELL_DOUT_PIN  3
#define LOADCELL_SCK_PIN  2
HX711 scale;
const int chipSelect = 4;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(19200);
  Serial.println("Load Cell Datalogging");
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1);
  }
  Serial.println("card initialized.");  
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(calibration_factor); //This value is obtained by using the SparkFun_HX711_Calibration sketch
  scale.tare();  //Assuming there is no weight on the scale at start up, reset the scale to 0
  Serial.println("Readings:");
}

void loop() {
  File dataFile = SD.open("datalog.txt", FILE_WRITE);
  

  // if the file is available, write to it:
  if (dataFile) {
    +
    dataFile.print(scale.get_units(),1); //scale.get_units() returns a float
    dataFile.print(" ");
    dataFile.println(millis());
    dataFile.close();
    // print to the serial port too:
    Serial.println(scale.get_units(), 1); //scale.get_units() returns a float
  }
}
