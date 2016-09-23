#include <stdio.h>
#include <math.h>
#include <stdlib.h>

static double k = 300.0;
static double m = 5.0;
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




double dydt(double muj, double x, double y) {
	return -k/m * x - muj * g * sign(y);
}

//yp = yi + hp(xi ; yi; zi )
//zp = zi + hq(xi; yi; zi )
//yi+1 = yi +1/2*h(p(xi ; yi; zi ) + p(xi+1; yp; zp))
//zi+1 = zi +1/2*h(q(xi; yi; zi ) + q(xi+1 ; yp; zp))

/* the p function */
double p(double x, double y, double z) {
	return y;
}

/* the q function */
double q(double x, double y, double z) {
	return dydt(x, y, z);
}

/*
the predictor/corrector function, returns one pair
of y and z for each call
*/
pair predcorr(double x, double y, double z, double h) {
	pair next;

	double p_i = p(x, y, z);
	double q_i = q(x, y, z);

	double yp = y + h * p_i;
	double zp = z + h * q_i;

	double x_next = x;

	next.y = y + 0.5 * h * (p_i + p(x_next, yp, zp));
	next.z = z + 0.5 * h * (q_i + q(x_next, yp, zp));
	return next;
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
	double x = 0.2;
	double y = 0;
	double z = 0;

	/*
	for (float muj = 0; muj < 1; muj += my) {
		for (float t = 0; t < 3.0; t += 0.2){
			pair p = predcorr(x, y, z, t);
		}
	}*/

	for (float t = 0; t < 3.0; t += 0.2){
		pair p = predcorr(x, y, z, t);
		printf("%lf %lf\n", p.y, p.z);
		y = p.y;
		z = p.z;
	}

	return 0;
}