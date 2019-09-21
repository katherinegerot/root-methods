/**
* Author: Katie Gerot
* Date: 09/20/2019
* Class: CSCE 440
* 
* Program computing Newton's Method with the following equations:
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
	double p; 
	double p0 = 0.5;
	double p1 = 1;
	
	printf("i\tp\n"); //headers for output table
	int i = 1;
	double f0 = f(p0, eq);
	double f1 = f(p1, eq);
	
	//SECANT METHOD
	while(i <= MAX_I) {
		i++;
		printf("%2d", i);
		p = p1 - f1 * (p1 - p0)/(f1 - f0);
		if(fabs(p - p0) < TOL) {
			printf("%14.6lf\n", p);
			break;
		}			
		printf("%14.6lf\n", p);
		f0 = f1;
		p1 = p;
		f1 = f(p, eq);
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