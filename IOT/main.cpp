/*
 * main.cpp
 *
 *  Created on: Nov 5, 2018
 *      Author: pc
 */

#include <iostream>
#include "HIH8120.h"
namespace exploringBB
{

int main(int argc , char* argv[])
{
	unsigned int i2c_bus = 2 ;
	HIH8120 sensor(i2c_bus,0x27);
	// display values
	sensor.displayData();
	return 0;

}
}
