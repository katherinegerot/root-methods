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
void print(int i, double p);

int main(int argc, char **argv) {
	int store[4][50]; //stores p values up to 50
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
	int iterations = 0;
	fa = f(a, eq); //f(a)
	
	//BISECTION METHOD
	while(iterations <= MAX_I) {
		iterations++;
		p = a + (b - a)/2;
		fp = f(p, eq); //f(p)
		if(fp == 0 || (b - a)/2 < TOL) { // if a root is found or the midpoint is
										 // within a certain tolerance
			store[0][]
			break;
		}
		if(fa * fp > 0) { // if the product is positive or not zero
			a = p;
			fa = fp;
			print(iterations, p);
		} else { // if the product is negative or zero
			b = p;
			print(iterations, p);
		}
	}
	
	//NEWTON'S METHOD
	
	//FIXED POINT METHOD
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


void print(int arr[4][50]) {
	for(int i = 0; i < 50; i++) {
		printf("%3d ", i);
		for(int j = 0; j < 4; j++) {
			printf("%14.6lf ", arr[j][i]);
		}
		printf("\n");
	}
}