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

int getNumber(int spread, char message[]);
float calculate_speed(int finish_line_distance);
int calculate_strength();
int calculate_combat(float speed, int strength);

char message[3][100] = {
	{ "Please enter the distance of the racetrack in meters [0-10000] : " },
	{ "Please enter the number of seconds taken to complete the race [0-3600] : " },
	{ "Please enter the strength of the robot [1-100] : " }
};

int main(void) {
start:
	//Variable Declaration
	float speed = 0;
	int wins = 0;

	//Workshop 1
	speed = calculate_speed(getNumber(10000, message[0]));

	//Result output
	printf("\nThe robot has an average speed of %g meters per second.\n", speed);

	//Workshop 2
	wins = calculate_combat(speed, calculate_strength());

	printf("\nThe robot won %d games.\n\n", wins);
	printf("Continue? [y/n] : ");

	int c;
	do {
		c = getchar();
		if (c == 'y') { printf("\n\n\n"); getchar(); goto start; }
	} while (c != 'n');

	//End of File
	return 0;
}

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
			ch = getchar();
			char_count = 0;
			while ((ch != '\n') && (char_count < MAXBUFFERSIZE)) {
				buffer[char_count++] = ch;
				ch = getchar();
			}
			buffer[char_count] = 0x00;      /* null terminate buffer */
			number = atoi(buffer);
			if ((number < 1) || (number > spread))
				printf("\007Out of Range\n");
			else
				valid_choice = 1;
		}
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

	float firstRand;
	float secondRand;

	for (int i = 0; i < 100; i++) {
		srand(rand() % 1000);

		winchance = fmax(speed, 50);
		winchance = winchance + ((strength / 100) * 50);

		firstRand = rand() % 20;
		firstRand = (0.1 - firstRand / 100);

		winchance = winchance + (winchance*firstRand);

		secondRand = rand() % 101;

		if (secondRand <= winchance) { wins++;}
	}
	return wins;
}