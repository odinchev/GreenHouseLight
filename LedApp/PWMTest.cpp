/*
 * PWMTest.cpp
 *
 *  Created on: Nov 12, 2018
 *      Author: pc
 */




#include<iostream>
#include"PWM.h"      //placed in the current directory for ease of use

using namespace exploringBB;
using namespace std;

void changeBrightness( int value); // function prototypes controlls brighness by adjusting period
bool checkPWM();
bool enablePWM();

int main(int argc, char* argv[]){
	// PWM pwm("pwm_test_P9_22.15");  // example alternative pin
	PWM pwm("P9_21");  // P9_42 MUST be loaded as a slot before use
	//   pwm.setPeriod(100000);         // Set the period in ns
	//   pwm.setDutyCycle(25.0f);       // Set the duty cycle as a percentage



#define PATH "/sys/class/pwm/pwmchip1" // the path to pwmchip1 which is p9_21 after the pwm is initialized
	int value; // for adjusting brightness

	char argument;
	char* p;
	p = &argument;




	printf("starting the GreenhouseLedControlProgram \n");

	printf("checking if pwm is enabled \n");

	if(checkPWM()== true)
	{
		printf("pwm is enabled \n");
	}
	else
	{
		printf("pwm is not enabled. enabling pwm \n");

		enablePWM();
		checkPWM();

	}



	long input = strtol(argv[1],&p,10); // convert argc from char to int
	float number = input;
	changeBrightness(number);



	printf("Finished the GreenhouseLightControl program \n");
	return 0;
}

void changeBrightness(int value)
{
	PWM pwm("P9_21");
	int dutyTime= value*10; // to get the dutytime
	int period = value*100;   // to get the period


	//system("cd /sys/class/pwm/pwmchip1");
	//system("sh -c cd pwm-1\:1");
	FILE * fp;


	printf("setting period \n");
	//	fp = fopen("/sys/class/pwm/pwmchip1/pwm-1:1/period","w");
	//	fprintf(fp,"%d",20000000);
	pwm.setPeriod(20000000);



	//fclose(fp);
	printf("period is set \n ");

	printf("setting duty_cycle \n");
	//	fp = fopen("/sys/class/pwm/pwmchip1/pwm-1:1/duty_cycle","w");
	//	fprintf(fp,"%d",dutyTime);
	//	fclose(fp);

	float percent =dutyTime;

	pwm.setDutyCycle(percent);
				pwm.setPolarity(PWM::ACTIVE_LOW);  // using active low PWM
	pwm.run();  // start the PWM output
	printf("duty_cycle is set \n");


	fp = fopen("/sys/class/pwm/pwmchip1/pwm-1:1/enable","w");
	fprintf(fp,"%s","1");
	fclose(fp);
	//system("sh -c \"echo 1 > enable\"");




}
bool checkPWM()
{


	FILE * fp;

	char fullFileName[100];

	if(sprintf(fullFileName, "/sys/class/pwm/pwmchip1/export")==-1)
	{
		printf("failed to open the export file");
		return false;
	}
	else
	{
		fp = fopen(fullFileName,"rt"); // reading text now
		fprintf(fp,"%s","1");
		fclose(fp);
		system("sleep 1");
		printf("sleeping for 1 seccond");
		enablePWM();


		return true;
	}


}
bool enablePWM()
{
	if(system("config-pin -a  P9-21 pwm")== -1)
	{
		return false;
	}
	else
	{
		system("sleep 1");
		printf("sleeping for 1 seccond");
		return true; // the operation was successful
	}





}
