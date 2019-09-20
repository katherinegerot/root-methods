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
	const int MAX_I = 50; //maximum iterations
	char eq = argv[1][0]; //equation, either a, b, c, or d
	double a, b, fa, fp, p; // endpoints
	
	switch(eq) { //sets correct interval
		case 'a': 
			a = -1;
			b = 1;
		case 'b':
			a = 0;
			b = 2;
		case 'c':
			a = -2;
			b = 2;
		case 'd':
			a = -2;
			b = 2;
		default: exit(1);
	}
	printf("i\tf(a)\tf(p)\tp\n");
	int iterations = 1;
	fa = f(a, eq); //f(a)
	
	while(iterations <= MAX_I) {
		p = a + (b - a)/2;
		fp = f(p, eq); //f(p)
		if(fp == 0 || (b - a)/2 < TOL) { // if a root is found or the midpoint is
										 // within a certain tolerance
			print(iterations, fa, fp, p);
			break;
		}
		iterations++;
		if(fa * fp > 0) { // if the product is positive or not zero
			a = p;
			f(a) = f(p);
			print(iterations, fa, fp, p):
		} else { // if the product is negative or zero
			b = p;
			print(iterations, fa, fp, p):
		}
	}
	
	return 0;
}



/**
* Given x, this function will compute the equation designated by char e
**/
double f(double x, char e) {
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
		default: exit(1);
	}
	
}


void print(int i, double fa, double fp, double p) {
	printf("%5d %2.4lf %2.4lf %6.6lf\n", i, fa, fp, p);
}