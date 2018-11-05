/*
 * HIH8120.h
 *
 *  Created on: Nov 5, 2018
 *      Author: pc
 */

#ifndef EXAMPLES_HIH8120_H_
#define EXAMPLES_HIH8120_H_


private:
	unsigned int I2CBus, I2CAddress;
	unsigned char *registers;
	float temperature, humidity;

	short combineRegisters(unsigned char msb, unsigned char lsb);
	void calculatePitchAndRoll();
	virtual int updateRegisters();

public:
	HIH2180(unsigned int I2CBus, unsigned int I2CAddress=0x27);
	virtual int readSensorState();



	virtual float getHumidity() { return humidity; }
	virtual float getTemperature() { return temperature; }

	// Debugging method to display and update the pitch/roll on the one line

};


#endif /* EXAMPLES_HIH8120_H_ */
