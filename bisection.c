/**
* Author: Katie Gerot
* Date: 09/20/2019
* Class: CSCE 440
* 
* Program computing the Bisection Method with the following equations:
* (a) 3x^3 - 2x^2 + 5x - 2e^x + 1
* (b) x^4 + 3x^2 - 2
* (c) 3x - x^2 - e^x - 2
* (d) x - cos(x)
**/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {
	const double TOL = 0.0001; //tolerance
	const int max = 50; //maximum iterations
	char eq = argv[1][0]; //equation, either a, b, c, or d
	double a, b; // endpoints
	
	
	
	return 0;
}

/**
* Given x, this function will compute the equation designated by char e
**/
double eqA(double x, char e) {
	switch(e) {
		case 'a': 
			return (3 * pow(x, 3)) -
				   (2 * pow(x, 2)) + 
				   (5 * x) - (2 * pow(M_E, x)) + 1;
		case 'b':
			return pow(x, 4) + 
				   (3 * pow(x, 2)) - 2;
		case 'c':
			return (3 * x) - 
				   pow(x, 2) + 
				   pow(M_E, x) - 2;
		case 'd':
			return x- cos(x);
	}
	
}

void formatPrint() {
	
}