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

double f(double x, char e);

int main(int argc, char **argv) {
	const double TOL = 0.0001; //tolerance
	const int MAX_I = 50; //maximum iterations
	char eq = argv[1][0]; //equation, either a, b, c, or d
	double a, b, fa, fp, p; // endpoints
	
	switch(eq) { //sets correct interval
		case 'a': 
			a = -1;
			b = 1;
			break;
		case 'b':
			a = 0;
			b = 2;
			break;
		case 'c':
			a = -2;
			b = 2;
			break;
		case 'd':
			a = -2;
			b = 2;
			break;
		default: exit(1);
	}
	printf("i\tp\n"); //headers for output table
	int i = 0;
	fa = f(a, eq); //f(a)
	
	//FIXED POINT METHOD
	while(i <= MAX_I) {
		i++;
		
		//...
		
		printf("%14.6lf\n", p);
		
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