/*
 * HIH8120.cpp
 *
 *  Created on: Nov 5, 2018
 *      Author: pc
 */
#include "HIH8120.h"
#include "I2CDevice.h"
#include <iostream>
#include <unistd.h>
#include <math.h>
#include <stdio.h>

using namespace std;

namespace exploringBB
{

	#define SENSOR          0x27   // HIH8120 sesnsor



  public HIH8120::HIH8120(unsigned int I2CBus, unsigned int SENSOR):

   I2CDevice(I2CBus, I2CAddress)
  {
	this->I2CAddress = I2CAddress;
	this->I2CBus = I2CBus;
  }

  void displayData()
  {
	  int humidity;
	  int temp;
	  char bytes [];
	  write(0);
	  sleep(1);
	 bytes=readDevice(4);
	 data = bytes[0] << 8 | data[1];
	 humidity =  bytes[2] << 8 | data[3];
	  temp=temp >> 2;
	  humidity= (humidity / (2^14 - 2))*100;
	  temperature =(temperature / (2^14 - 2)) * (165-40);
	 //what value should it be in here ??
      // char array ? that takes the readDevice() and then what
	  // do some calculations
	 // How to do the calculations
	  printf(humidity);
	  printf(temperature);
  }

}

 /* namespace exploringBB */

