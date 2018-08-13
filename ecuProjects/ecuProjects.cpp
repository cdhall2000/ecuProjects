// ecuProjects.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>;
#include <math.h>
#include <stdlib.h>
#include <time.h>

//Function Declaration for Workshop 1
float error(float var);


//Function Generation for Workshop 2
float calculate_speed(float finish_line_distance);
int calculate_strength();
int calculate_combat(float speed, int strength);


int main(void) {
	//Variable Declaration
	float distance;
	float finish_time;
	float speed;
	int strength;
	int combatWins;
	//User Interface
	printf("Distance of the robot racetrack: ");
	scanf("%f", &distance);
	distance = error(distance);

	speed = calculate_speed(distance);

	//Result output
	printf("\nThe robot has an average speed of %g meters per second.\n", speed);

	strength = calculate_strength();

	combatWins = calculate_combat(speed, strength);

	printf("The robot won %d games.", combatWins);

	int c;
	do {
		c = getchar();
		putchar(c);
	} while (c != 'n');

	//End of File
	return 0;
}
//Function to ensure valid variable
float error(float var)
{
	if (var < 0) {
		do {
			printf("\nOutOfRange - Please enter a positive value : ");
			scanf("%f", &var);
		} while (var < 0);
	}
	return var;
}

float calculate_speed(float finish_line_distance)
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

		if (secondRand <= winchance) { wins++; printf("\nwinchance %f, firstRand %f, secondRand %f, win", winchance, firstRand, secondRand); }
		if (secondRand >= winchance) { printf("\nwinchance %f, firstRand %f, secondRand %f, loss", winchance, firstRand, secondRand); }

		i++;
	}


	return wins;
}