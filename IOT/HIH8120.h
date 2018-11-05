/*
 * HIH8120.h
 *
 *  Created on: Nov 5, 2018
 *      Author: pc
 */

#ifndef EXAMPLES_HIH8120_H_
#define EXAMPLES_HIH8120_H_

namespace exploringBB
{
class HIH8120
{
 private:
	unsigned int I2CBus, I2CAddress;





public :
	HIH8120(unsigned int I2CBus, unsigned int I2CAddress=0x27);
	void displayData();




	// Debugging method to display and update the pitch/roll on the one line


};
}

#endif /* EXAMPLES_HIH8120_H_ */
