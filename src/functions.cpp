#include <iostream>
#include <fstream>
#include <math.h>
#include "functions.hpp"

// Iterates the map one time
void mapIteration(double (&pointBefore)[2], double (&pointAfter)[2], double parameters[3])
{
    double alpha = parameters[0];
    double beta  = parameters[1];
    double gamma = parameters[2];
    pointAfter[1] = pointBefore[1] - gamma*sin(2.0*M_PI*pointBefore[0]);	
	pointAfter[0] = pointBefore[0] + alpha*(1.0 - pointAfter[1]*pointAfter[1])*(1.0 - beta*pointAfter[1]*pointAfter[1]);
}



// Reduce the angle to the first turn in trigonometric circle
double reduceAngle(double (&pointAfter)[2])
{
    double angle;

    angle = pointAfter[0] - floor(pointAfter[0]/1.0);
	if (angle <= 1.0 && angle >= 0.0)
        angle = angle;
	else
	    angle = angle - 1.0;
    return angle;
}



// Plot the map through a grid of initial conditions
void mapGrid(int iterations, double (&initial)[2], double (&final)[2], double parameters[3])
{
    double pointBefore[2];
    double pointAfter[2];
    double angle;

    std::ofstream myfile ("../data/map.dat");

    while (initial[0] <= 0.6)
    {
        while (initial[1] <= 2.0)
        {
            pointBefore[0] = initial[0];
            pointBefore[1] = initial[1];

            for (int i = 1; i <= iterations; i++)
            {
                mapIteration(pointBefore, pointAfter, parameters);

                angle = reduceAngle(pointAfter);
                myfile << angle << "\t" << pointAfter[1] << std::endl;

                pointBefore[0] = pointAfter[0];
                pointBefore[1] = pointAfter[1];
            }

            initial[1] += 0.05;
        }
        initial[1] = -2.0;
        initial[0] += 0.5;
    }
}



// Calculates the rotation number for a given initial condition
double rotationNumberCalculator(double initialCondition[2], int numberSteps, int iterations, double parameters[3])
{
    double omega = 0.0;
    double pointBefore[2] = {initialCondition[0], initialCondition[1]};
    double pointAfter[2];
    
    for (int i = 1; i <= iterations; i++)
            {
                mapIteration(pointBefore, pointAfter, parameters);
                pointBefore[0] = pointAfter[0];
                pointBefore[1] = pointAfter[1];
            }
    omega = (pointAfter[0] - initialCondition[0])/iterations;

    return omega;
}



// Calculates the rotation number profile
void rotationProfile(int iterations, double initial[2], double final[2], int numberSteps, double param[3])
{
    double rotationNumber = 0.0;
    double sizeStep = (final[1] - initial[1])/numberSteps;
    double actual[2] = {initial[0], initial[1]};
    std::ofstream fileRotation ("../data/rotation.dat");

    for (int i = 1; i <= numberSteps; i++)
    {
        actual[1] = initial[1] + (float)i * sizeStep;
        rotationNumber = rotationNumberCalculator(actual, numberSteps, iterations, param);
        fileRotation << actual[1] << "\t" << rotationNumber <<std::endl;
    }
}


