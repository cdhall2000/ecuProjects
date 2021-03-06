/*
Conor Hall -- 10466225
Edith Cowan University
Workshop 2 :

*/

#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAXBUFFERSIZE   10

//Declarations
int getNumber(int spread, char message[]);
float calculate_speed(int finish_line_distance);
int calculate_strength();
int calculate_combat(float speed, int strength);

//Message for the three times getNumber() is invoked
char message[3][100] = {
	{ "Please enter the distance of the racetrack in meters [0-10000] : " },
	{ "Please enter the number of seconds taken to complete the race [0-3600] : " },
	{ "Please enter the strength of the robot [1-100] : " }
};

int main(void) {
	while (true) {

		//Required const variables
		float speed = 0;
		int wins = 0;

		//Workshop 1's Speed calculator
		speed = calculate_speed(getNumber(10000, message[0]));
		printf("\nThe robot has an average speed of %g meters per second.\n", speed);

		//Workshop 2
		wins = calculate_combat(speed, calculate_strength());

		//printf the results
		printf("\nThe robot won %d games.\n\n", wins);
		printf("Continue? [y/n] : ");

		//Repeat program or terminate program function
		int c;
		do {
			c = getchar();
			if (c == 'y')
			{
				c = getchar();
				while (c != '\n') { c = getchar(); }
			}
			if (c == 'n') { return 0; }
		} while (c != 'n');
		//End of Program
	}
	return 0;
}

//Most important function. Gets and parses input from user to prevent undesired input such as letters and symbols. Overkill for week 7
int getNumber(int spread, char message[])
{
	char ch;
	char buffer[MAXBUFFERSIZE];
	int char_count;
	int exit_flag = 0, number, valid_choice;

	while (exit_flag == 0) {
		valid_choice = 0;
		while (valid_choice == 0) {
			printf("%s", message);

			//start feeding input into buffer
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

			//checks if number is valid, letters entered into the input will result in an out of range error,
			if ((number < 1) || (number > spread)) { printf("\007Out of Range\n"); }
			else { valid_choice = 1; }
		}
		//Sucessful number input and parse, return number to main()
		exit_flag = 1;
		return number;
	}
}

float calculate_speed(int finish_line_distance)
{
	int time;
	time = getNumber(3600, message[1]);
	return finish_line_distance / time;
}

int calculate_strength(void)
{
	int strength;
	strength = getNumber(100, message[2]);
	return strength;
}

int calculate_combat(float speed, int strength)
{
	float winchance = 50;

	int wins = 0;

	float firstRand; //firstRand = the +-10% random element of the robots calculated win chance
	float secondRand; //secondRand = the random 1-100 int that is used to determine whether or not the robot wins the fight.

	for (int i = 0; i < 100; i++) {
		srand(rand() % 1000);

		winchance = fmax(speed, 50);
		winchance = winchance + ((strength / 100) * 50);

		firstRand = rand() % 20;
		firstRand = (0.1 - firstRand / 100);

		winchance = winchance + (winchance*firstRand);

		secondRand = rand() % 101;

		if (secondRand <= winchance) { wins++; }
	}
	return wins;
}