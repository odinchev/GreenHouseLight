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
#include "string.h"
//${COMMAND} ${FLAGS} -E -P -v -dD "${INPUTS}"
using namespace std;

namespace exploringBB
{

	#define SENSOR          0x27   // HIH8120 sesnsor



  HIH8120::HIH8120(unsigned int I2CBus, unsigned int I2CAddress ):I2CDevice(I2CBus, I2CAddress)
  {
	 
	this->I2CAddress = I2CAddress;
	this->I2CBus = I2CBus;
  }

 void  HIH8120::displayData()
  {
	  double humidity;
	  double temp;
	  int humidityADC;
	  int tempADC;
	  //char bytes [4] ;

      
	//  I2CDevice device(2, 0x27);
	 write(0);
      sleep(1);
	  unsigned char * deviceData  = readDevice(4);
//	  const char* test =deviceData;
	  if(deviceData[0] <= 0x3F)
	  {
		  for(int i=0; i< strlen((const char*)deviceData);i++)
		  {
			  std::cout << "device data ["<< i << "]" << "is" << deviceData[i] << endl;
		  }
		  
		  humidityADC = (deviceData[0] << 8 )| deviceData[1];
	      tempADC =  (deviceData[2] << 8 )| deviceData[3];
	      tempADC=tempADC >> 2;
	  // convert the adc output into percent and degrees
	      humidity= (humidityADC / (2^14 - 2))*100;
	      temp =(tempADC / (2^14 - 2)) * 165-40;

	  }


     
	//extract bits from each byte
	 
	 //bytes= device.readDevice(4);
	 // strcpy(bytes,deviceData);


	  // store the bytes into variables for humidity and temperature and shift the bits
	  



	//   std::cout << " humidity(adc) is "<< humidityADC << "\n" ;
	//    std::cout << "temperature(adc) is "<< tempADC << "\n" ;



	 // print the values for the humidity and temperature 
	  std::printf("humidity %d  \n",humidity );
	  std::printf("temperature %d  \n",temp );
  }

}

 /* namespace exploringBB */

