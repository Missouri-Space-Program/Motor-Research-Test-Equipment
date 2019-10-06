# Motor Research Test Equipment
There are two main sensors used in motor testing, a load cell and a pressure transducer. The load cell measures the force of the motor and the pressure transducer measures the chamber pressure. With these two sets of data, the fuel can be correctly characterized which is vital to creating your own motors. This guide goes through how the current system works and how to calibrate and hook it up.

There are two main sensors used in motor testing, a load cell and a pressure transducer. The load cell measures the force of the motor and the pressure transducer measures the chamber pressure. With these two sets of data, the fuel can be correctly characterized which is vital to creating your own motors. This guide goes through how the current system works and how to calibrate and hook it up.

# Load Cell
The voltage that comes out of the load cell needs to be amplified so that a computer can read the data. A load cell amplifier does this and the model that we use is a SparkFun HX711. There is documentation for this amplifier on SparkFun’s website. The amplifier is hooked up to an arduino that then writes the data to an sd card. Below is a wiring diagram.

# Load Cell Arduino
The Arduino takes the data from the load cell amplifier and converts it to newtons using a calibration factor that is determined in calibration. The code can be found on SparkFun’s website. The code that writes the data to the sd card can be found on MSP’s github.


# Pressure Transducer
The pressure transducer will create a voltage drop across it based on the pressure. This voltage drop is recorded by the DATAQ system, which is then recorded to a computer as the test is happening. This DATAQ file can then be exported to excel.

# Pressure Transducer Calibration
Steps
Wire transducer to DATAQ
Connect DATAQ to computer
Zero the transducer at room pressure
In DATAQ software press Ctrl-t or look for toolbox, find calibration and press the eyedropper on the low end spot. Then type in zero for what the reading should be
Type in the values for the transducer for the high end.
Ex. 5v at 2500psi
This information can often be found on the side of the transducer or on the sellers website/datasheet.
Test a midpoint with the pressure around the middle of the range or as high as you can go.
Save the sensor profile as default and the DATAQ/pressure transducer should be ready for the test.

# Pre-Test Checklist
(Print this page off and bring it to test location. Failure to follow these steps will result in a waste of money equal to the cost of the motor.)

Pressure Transducer
- [ ] Pressure transducer calibration checked (calibration can be done on-site).
- [ ] Pressure transducer attached to motor and wired to DATAQ according to wiring diagram.
- [ ] DATAQ is wired to laptop usb port.
- [ ] Laptop running Windaq has the correct sensor profile open and has started to record data.
Load Cell
- [ ] Load cell calibration checked (calibration cannot be done on-site).
- [ ] Load cell securely attached to rocket motor test stand.
- [ ] Load cell wired to amplifier according to wiring diagram
- [ ] Load cell amplifier wired to arduino according to wiring diagram
- [ ] SD card checked to make sure it is collecting data by turning arduino on and then checking sd card in computer.
- [ ] Arduino connected to laptop usb port.
General
- [ ] Electronics are in a safe location relative to rocket motor.
- [ ] All personel are a safe distance away from rocket motor test.
- [ ] The test equipment is now ready to collect data.

