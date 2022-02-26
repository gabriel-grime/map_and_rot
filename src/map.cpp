// Parâmetros definidos no main e passados como argumento para as funções

#include <iostream>
#include <fstream>
#include <math.h>
#include "functions.hpp"

int main()
{
    // ------------------------------------------------------------------------
        // Parameters od the map
    double alpha = 0.3;
    double beta  = 0.4;
    double gamma = 0.5;

    // Initial conditions od Map 
    double x0i =  0.0;
    double y0i = -2.0;
    double x0f =  0.5;
    double y0f =  2.0;

    // Parameters od the map plot
    int numberIterations = 1e3;

    // Initial conditions of rotation number profile
    double omegax0i =  0.0;
    double omegay0i = -2.0;
    double omegax0f =  0.5;
    double omegay0f =  2.0;
    
    // Parameters of rotation profile plot
    int iterationsRotation = 1e4;
    int numberStepsRotation = 1e3;


    double beginInitialConditions[2] = { x0i , y0i };
    double finalInitialConditions[2] = { x0f , y0f };

    double omegaBeginInitialCond[2] = { omegax0i , omegay0i };
    double omegaFinalInitialCond[2] = { omegax0f , omegay0f };

    double parameters[3] = { alpha, beta, gamma };

    // Plot the map through a grid of initial conditions
    mapGrid(numberIterations, beginInitialConditions, finalInitialConditions, parameters);
    
    // Plot the rotation number profile
    rotationProfile(iterationsRotation, omegaBeginInitialCond, omegaFinalInitialCond, numberStepsRotation, parameters);

    return 0;
}
