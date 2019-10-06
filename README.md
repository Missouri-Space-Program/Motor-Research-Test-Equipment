# Motor-Research-Test-Equipment
The information and code for MSP's rocket motor test system.

MSP Motor Testing Electronics Guide

There are two main sensors used in motor testing, a load cell and a pressure transducer. The load cell measures the force of the motor and the pressure transducer measures the chamber pressure. With these two sets of data, the fuel can be correctly characterized which is vital to creating your own motors. This guide goes through how the current system works and how to calibrate and hook it up.

Load Cell
The voltage that comes out of the load cell needs to be amplified so that a computer can read the data. A load cell amplifier does this and the model that we use is a SparkFun HX711. There is documentation for this amplifier on SparkFun’s website. The amplifier is hooked up to an arduino that then writes the data to an sd card. Below is a wiring diagram.

Load Cell Arduino
The Arduino takes the data from the load cell amplifier and converts it to newtons using a calibration factor that is determined in calibration. The code can be found on SparkFun’s website and on the MSP github. The code that writes the data to the sd card can be found on MSP’s github.

Pressure Transducer
	The pressure transducer will create a voltage drop across it based on the pressure. This voltage drop is recorded by the Dataq system, which is then recorded to a computer as the test is happening. This Dataq file can then be exported to excel.

Pressure Transducer Calibration

Pre-Test Checklist
