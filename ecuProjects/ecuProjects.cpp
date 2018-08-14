/*
Conor Hall -- 10466225
Edith Cowan University
Workshop 2 : 

*/
#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#define MAXBUFFERSIZE   50

//Function Declaration for Workshop 1
float error(float var);

void cleartoendofline(void);

int getDistance(void);

void cleartoendofline(void)
{
	char ch;
	ch = getchar();
	while (ch != '\n')
		ch = getchar();
}

//Function Generation for Workshop 2
float calculate_speed(int finish_line_distance);
int calculate_strength();
int calculate_combat(float speed, int strength);


int main(void) {
start:

	//Variable Declaration
	int distance = 0;
	float speed = 0;
	int strength = 0;
	int combatWins = 0;
	//User Interface
	distance = getDistance();
	//distance = error(distance);
	speed = calculate_speed(distance);

	//Result output
	printf("\nThe robot has an average speed of %g meters per second.\n", speed);

	strength = calculate_strength();

	combatWins = calculate_combat(speed, strength);

	printf("\nThe robot won %d games.\n\n", combatWins);
	printf("Continue? [y/n] : ");

	int c;
	do {
		c = getchar();
		if (c == 'y') { printf("\n\n\n");  goto start; }
		putchar(c);
	} while (c != 'n');

	//End of File
	return 0;
}

int getDistance(void)
{
	char ch;
	char buffer[MAXBUFFERSIZE];
	int char_count;
	int exit_flag = 0, number, valid_choice;

	while (exit_flag == 0) {
		valid_choice = 0;
		while (valid_choice == 0) {
			printf("Please enter a whole number distance of the robot racetrack [1-10000] : ");
			ch = getchar();
			char_count = 0;
			while ((ch != '\n') && (char_count < MAXBUFFERSIZE)) {
				buffer[char_count++] = ch;
				ch = getchar();
			}
			buffer[char_count] = 0x00;      /* null terminate buffer */
			number = atoi(buffer);
			if ((number < 1) || (number > 10000))
				printf("\007Error. Number outside range\n");
			else
				valid_choice = 1;
		}
		exit_flag = 1;
		return number;
	}
}

float calculate_speed(int finish_line_distance)
{
	float time;

	printf("Time taken to reach the end of the track: ");
	scanf("%f", &time);
	time = error(time);

	return finish_line_distance / time;
}

int calculate_strength(void)
{
	int st;

	printf("Please enter the strength of robot on a scale of 0 - 100 : ");
	scanf("%2d", &st);

	if (st < 0 || st > 100) {
		do {
			printf("\nInvalid strength variable - Enter a whole number between 0 - 100 : ");
			scanf("%2d", &st);

		} while (st < 0 || st > 100);
	}
	return st;
}

int calculate_combat(float speed, int strength)
{
	int i = 0;
	float strenggy = strength;
	float winchance = 50;

	int wins = 0;

	float firstRand;
	float secondRand;

	while (i < 100) {
		srand(rand() % 1000);

		winchance = fmax(speed, 50);
		winchance = winchance + ((strenggy / 100) * 50);

		firstRand = rand() % 20;

		firstRand = (0.1 - firstRand / 100);
		winchance = winchance + (winchance*firstRand);

		secondRand = rand() % 101;

		if (secondRand <= winchance) 
		{ 
			wins++; 
			//printf("\nwinchance %f, firstRand %f, secondRand %f, win", winchance, firstRand, secondRand); 
		}
		if (secondRand >= winchance) 
		{ 
			//printf("\nwinchance %f, firstRand %f, secondRand %f, loss", winchance, firstRand, secondRand); 
		}

		i++;
	}


	return wins;
}