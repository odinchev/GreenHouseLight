/*
 * HIH8120.h
 *
 *  Created on: Nov 5, 2018
 *      Author: pc
 */

#ifndef EXAMPLES_HIH8120_H_
#define EXAMPLES_HIH8120_H_
#include "I2CDevice.h"

namespace exploringBB
{
	class HIH8120 : protected I2CDevice
	{
 		private:
			unsigned int I2CBus, I2CAddress;





		public:
			HIH8120(unsigned int I2CBus, unsigned int I2CAddress=0x27);
			void displayData();

	};
}

#endif /* EXAMPLES_HIH8120_H_ */
