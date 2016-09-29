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

void analysis(double ***table, int total_runs, int total_pred, double eps) {
	int i, j, k;

	/* Simple analysis function:
		if code enters a region that is under the eps this index is marked
		if at one point the eps get higher the switch is set to being outside the region.
		Once the region is back under eps the switch is set to being back in.
		This goes on until it eventually will not exit anymore. Total time is the
		t step summed.  */

	int in_region = 0;
	for (i = 0; i < total_runs; i++) {
		int below_eps_index_permanent = -1;
		for (j = 0; j < total_pred; j++) {
			if (fabs(table[i][j][0]) < eps) {
				if (in_region == 0) {
					below_eps_index_permanent = j;
					in_region = 1;
				}
			} else {
				in_region = 0;
			}
		}

		if (below_eps_index_permanent == -1) {
			printf("abs(x) never drops below eps for my = %lf\n", table[i][0][2]);
		} else {
			double sum = 0.0;
			for (k = 0; k < below_eps_index_permanent; k++) {
				sum += 0.005;
			}
			printf("The time when abs(x) permanently drops below %lf for my = %.2lf is %lf\n", eps, table[i][0][2], sum);
		}
	}
}

int main() {
	double eps;
	printf("Input epsilon: ");
	scanf("%lf", &eps);

	double t = 0.0;
	double y = 0.0;
	double h = 0.005;
	double x = 0.2;

	printf("Start values:\n");
	printf("t = %lf\n", t);
	printf("x = %lf\n", x);
	printf("y = %lf\n", y);
	printf("h = %lf\n", h);
	printf("my = %lf\n", my);
	printf("epsilon = %lf\n", eps);

	int total_runs = (int)(1 / my) - 1;
	int total_pred = (int)(3.0 / h);


	/* A 3D array,
		my (0.1 to 0.9) *
		number of iteration (3 / 0.005) *
		3 (x, y, and the my value) */
	double ***table;
	table = (double ***) malloc (total_runs * sizeof(double**));

	int i = 0;
	int j = 0;
	while (my <= 0.9) {
		printf("t, x and y for my = %.1lf\n", my);
		table[i] = (double **) malloc (total_pred * sizeof(double *));

		pair r;
		r.y = x;
		r.z = y;

		while (t < 3.0) {
			table[i][j] = (double *) malloc (3 * sizeof(double));

			pair p = predcorr(t, r.y, r.z, h);
			r.y = p.y;
			r.z = p.z;
			table[i][j][0] = p.y;
			table[i][j][1] = p.z;
			table[i][j][2] = my;

			printf("%.3lf %.3lf %.3lf\n", t, r.y, r.z);
			j++;
			t += h;
		}
		j = 0;
		t = 0.0;


		i++;
		my += 0.1;
	}

	analysis(table, total_runs, total_pred, eps);

	/* Free data the data collection since we won't use it anymore */
	for (i = 0; i < total_runs; i++) {
		for (j = 0; j < total_pred; j++) {
			free(table[i][j]);
		}
		free(table[i]);
	}
	free(table);
	return 0;
}