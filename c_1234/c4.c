#include <stdio.h>
#include <math.h>
#include <stdlib.h>

static double k = 300;
static double m = 5;
static double g = 9.81;
static double my = 0.1;

typedef struct pair {
	double y,z;
} pair;

int sign(double x) {
	if (x < 0) return -1;
	else if (x > 0) return 1;
	else return 0;
}


//yp = yi + hp(xi ; yi; zi )
//zp = zi + hq(xi; yi; zi )
//yi+1 = yi +1/2*h(p(xi ; yi; zi ) + p(xi+1; yp; zp))
//zi+1 = zi +1/2*h(q(xi; yi; zi ) + q(xi+1 ; yp; zp))

/* the p function */
double p(double x, double y, double z) {
	return 0;
}

/* the q function */
double q(double x, double y, double z) {
	return 0;
}

/*
the predictor/corrector function, returns one pair
of y and z for each call
*/
pair predcorr(double x, double y, double z, double h) {
	return NULL;
}

int main() {
/*
define h and the limit epsilon
iterate over friction values
create two arrays x and y
iterate over the pred-corr function to fill
x and y with values
analyze the result according to the problem
*/
	int t = 0;
	double x = 0.2
	double y = 0;
	return 0;
}