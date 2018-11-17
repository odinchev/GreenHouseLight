/*
 * LedControl.cpp
 *
 *  Created on: Nov 12, 2018
 *      Author: pc
 */




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "string.h"

#include<iostream>
//placed in the current directory for ease of use


using namespace std;






void changeBrightness( std::string mode , int value); // function prototypes controlls brighness by adjusting period
bool checkPWM( std::string mode);
bool enablePWM( std::string mode);



int main(int argc, char* argv[])
{
#define PATH "/sys/class/pwm/pwmchip1" // the path to pwmchip1 which is p9_21 after the pwm is initialized
	//int value; // for adjusting brightness

	char argument;
	char* p;
	p = &argument;
//    std::string value;
//	value(argv[2]);


	if(strcmp(argv[1],"LED")==0)
	{



		printf("starting the GreenhouseLedControlProgram \n");

		printf("checking if pwm is enabled \n");

		if(checkPWM("LED")== true)
		{
			printf("pwm is enabled \n");
		}
		else
		{
			printf("pwm is not enabled. enabling pwm \n");

			enablePWM("LED");
			checkPWM("LED");

		}



		long input = strtol(argv[2],&p,10); // convert argc from char to int
		int number = input;
		changeBrightness("LED" , number);



		printf("Finished the GreenhouseLightControl program \n");
		return 0;
	}
	else if (strcmp(argv[1],"Motor")==0)
	{
		printf("starting the MotorControlProgram \n");

		printf("checking if pwm is enabled \n");

		if(checkPWM("Motor")== true)
		{
			printf("pwm is enabled \n");
		}
		else
		{
			printf("pwm is not enabled. enabling pwm \n");

			enablePWM("Motor");
			checkPWM("Motor");

		}



		long input = strtol(argv[2],&p,10); // convert argc from char to int
		int number = input;
		changeBrightness("Motor" , number);



		printf("Finished the MotorControl program \n");
		return 0;
	}
}

void changeBrightness(std::string mode , int value)
{
	int dutyTime= value*10; // to get the dutytime
	int period = value*100;   // to get the period


	//system("cd /sys/class/pwm/pwmchip1");
	//system("sh -c cd pwm-1\:1");
	FILE * fp;
	if(mode == "LED")
	{

		printf("setting period \n");
		fp = fopen("/sys/class/pwm/pwmchip1/pwm-1:1/period","w");
		printf(" cd into pwm-1:1\ \n");
		fprintf(fp,"%d",20000000);

		fclose(fp);
		printf("period is set \n ");

		printf("setting duty_cycle \n");
		fp = fopen("/sys/class/pwm/pwmchip1/pwm-1:1/duty_cycle","w");
		fprintf(fp,"%d",dutyTime);
		fclose(fp);
		printf("duty_cycle is set \n");


		fp = fopen("/sys/class/pwm/pwmchip1/pwm-1:1/enable","w");
		fprintf(fp,"%s","1");
		fclose(fp);
		//system("sh -c \"echo 1 > enable\"");
	}
	else if (mode == "Motor")
	{

		printf("setting period \n");
		fp = fopen("/sys/class/pwm/pwmchip1/pwm-1:0/period","w");
		printf(" cd into pwm-1:0\ \n");
		fprintf(fp,"%d",20000000);

		fclose(fp);
		printf("period is set \n ");

		printf("setting duty_cycle \n");
		fp = fopen("/sys/class/pwm/pwmchip1/pwm-1:0/duty_cycle","w");
		fprintf(fp,"%d",dutyTime);
		fclose(fp);
		printf("duty_cycle is set \n");


		fp = fopen("/sys/class/pwm/pwmchip1/pwm-1:0/enable","w");
		fprintf(fp,"%s","1");
		fclose(fp);
	}



}
bool checkPWM(std::string mode)
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
		fp = fopen(fullFileName,"w"); // reading text now

		if (mode == "Motor")
		{
			fprintf(fp,"%s","0");
		}
		else
		{
			fprintf(fp,"%s","1");
		}
		fclose(fp);
		system("sleep 1");
		printf("sleeping for 1 seccond");

		if (mode == "Motor")
		{
			enablePWM("Motor");

		}
		else
		{
			enablePWM("LED");

		}


		return true;
	}
}



bool enablePWM(std::string mode)
{
	if(mode == "LED")
	{
		if(system("config-pin -a  P9-21 pwm")== -1)
		{
			return false;
		}
	}
	else if (mode == "Motor")
	{
		if(system("config-pin -a  P9-22 pwm")== -1)
		{
			return false;
		}
	}
	else
	{
		system("sleep 1");
		printf("sleeping for 1 seccond");
		return true; // the operation was successful
	}





}
