/*
Conor Hall (10466225)
Edith Cowan University
Workshop 1 Assignment: "Robot Speed"
Tutor: Rob McKnight

Email: cdhall@our.ecu.edu.au
*/

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXBUFFERSIZE   10

int getNumber(int spread, char message[]);

//Messages to be used when calling getNumber().
char message[2][100] = {
	{"\nPlease enter the distance of the robot's racetrack in meters [1-10000] : "},
	{"\nPlease enter the time taken for the robot to reach the end of the racetrack in seconds [1-3600] : "}
};

int main(void) {
	//Variable Declaration
	float distance;
	float finish_time;
	float speed;
	//User Interface
	distance = getNumber(10000, message[0]);
	finish_time = getNumber(3600, message[1]);
	speed = distance / finish_time;

	//Result output
	printf("\nThe robot has an average speed of %g meters per second.\n", speed);
	getchar();
	//End of File
	return 0;
}

int getNumber(int spread, char message[])
{
	//declare variables
	char ch;
	char buffer[MAXBUFFERSIZE];
	int char_count;
	int exit_flag = 0, number, valid_choice;


	while (exit_flag == 0) {
		valid_choice = 0;
		while (valid_choice == 0) {
			printf("%s", message);
			ch = getchar();
			char_count = 0;
			while ((ch != '\n') && (char_count < MAXBUFFERSIZE)) {
				buffer[char_count++] = ch;
				ch = getchar();
			}
			//Always add an end of stream zero.
			buffer[char_count] = 0x00;      
			//Convert text to an int
			number = atoi(buffer);

			//checks if number is valid, letters entered into the input will result in an out of range error.
			if ((number < 1) || (number > spread)) { printf("\007Out of Range\n"); }
			else { valid_choice = 1; }
		}
		//Successful number input and parse, return number to parent function
		exit_flag = 1;
		return number;
	}
}
