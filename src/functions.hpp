#pragma once

void mapIteration(double (&pointBefore)[2], double (&pointAfter)[2], double parameters[3]);

void mapGrid(int iterations, double (&initial)[2], double (&final)[2], double parameters[3]);

double reduceAngle(double (&pointAfter)[2]);

double rotationNumberCalculator(double initialCondition[2], int numberSteps, int iterations, double parameters[3]);

void rotationProfile(int iterations, double initial[2], double final[2], int numberSteps, double parameters[3]);
