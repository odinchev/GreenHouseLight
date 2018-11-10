#include <iostream>
#include <uninstd.h>
#include <pthread.h>
#include "HIH8120.h"

//using namespace std;

namespace exploringBB
{

int main(int argc , char* argv[])
{
	unsigned int i2c_bus = 2 ;
	if(argc > 1)
	{
		if(*argv[1] >= '0' && *argv[1] <= '2')
		{
			i2c_bus = *argv[1] - 0x30;
		}
		else
		{
			std::cout << "Usage:"<< argv[0] << "[i2c_bus] \r\n";
			std::cout << "i2c-bus is either 0,1 or 2. Default is 2 \r\n";
			return 1;
		}
	}
	HIH8120 sensor(i2c_bus,0x27);
	sensor.displayData();
	return 0;

}
}
