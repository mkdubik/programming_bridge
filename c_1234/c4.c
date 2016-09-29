#include <stdio.h>
#include <math.h>
#include <stdlib.h>

static const double k = 300.0;
static const double m = 5.0;
static const double g = 9.81;
static double my = 0.1;

typedef struct pair {
	double y,z;
} pair;

double sign(double x) {
	if (x < 0.0) return -1.0;
	else if (x > 0.0) return 1.0;
	else return 0.0;
}

/* the p function */
double p(double x, double y, double z) {
	return z;
}

/* the q function */
double q(double x, double y, double z) {
	return (-k * y)/m  - my * g * sign(z);
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

	double x_next = x + h;

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
	double t = 0.0;
	double y = 0.0;
	double h = 0.005;
	double x = 0.2;
	double eps = 0.0;

	printf("Start values:\n");
	printf("t = %lf\n", t);
	printf("x = %lf\n", x);
	printf("y = %lf\n", y);
	printf("h = %lf\n", h);
	printf("my = %lf\n", my);
	printf("epsilon = %lf\n", eps);

	double **table;
	table = (double *) malloc (sizeof(double) * ((int)(3.0 / h) * 3));

	pair r;
	r.y = x;
	r.z = y;

	for (t = 0; t < 3.0; t += h){
		pair p = predcorr(t, r.y, r.z, h);
		r.y = p.y;
		r.z = p.z;
		printf("%lf %lf %lf\n", t, r.y, r.z);
	}

	/*
	for (float muj = 0; muj < 1; muj += my) {
		for (float t = 0; t < 3.0; t += 0.2){
			pair p = predcorr(x, y, z, t);
		}
	}*/


	int i;
	for (t = 0; t < 3.0; t += h) {
		free(table[i]);
		i++;
	}
	free(table);
	return 0;
}