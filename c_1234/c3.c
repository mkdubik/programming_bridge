#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdlib.h>

/* calculate the sum of all numbers in an array */
double sumone(double *v, int n) {
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i];
	}
	return sum;
}

/* calculate the dot product of two arrays */
double sumtwo(double *v, double *w, int n) {
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += v[i] * w[i];
	}
	return sum;
}

/* calculate the power sum */
double sumpow(double *v, int n) {
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += pow(v[i], 2);
	}
	return sum;
}

double a(double *x, double *y, int n, double D) {
	return ((double)n * sumtwo(x,y,n) - sumone(x,n) * sumone(y, n)) / D;
}

double b(double *x, double *y, int n, double D) {
	return (sumpow(x, n) * sumone(y, n) - sumtwo(x, y, n) * sumone(x, n)) / D;
}
/*
do the calculations, parameters are the arrays {\tt x},{\tt y}
and {\tt n} (the size of the array)
results are {\tt a} and {\tt b}
*/

double lsfit (double *x, double *y, int n, double a, double b) {
	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += pow(y[i] - (a * x[i] + b), 2);
	}
	return sum;
}

double *solve(double *x, double *y, int n) {
	double D = (double)n * sumpow(x, n) - pow(sumone(x, n), 2);
	double _a = a(x, y, n, D);
	double _b = b(x, y, n, D);
	return (double[2]) {_a, _b};
}

int main() {
/*
create two arrays, fill them with numbers
call solve to get a and b. Then calculate
k and L
*/
	int k = 0;
	if (k > 0) {
		int n;
		printf("How many pairs? ");
		scanf("%d", &n);

		double *x = malloc(n * sizeof(double));
		double *y = malloc(n * sizeof(double));

		for (int i = 0; i < n; i++) {
			printf("Give a pair (%d/%d): ", i, n);
			double p1, p2;
			scanf("%lf %lf", &p1, &p2);
			x[i] = p1;
			y[i] = p2;
		}

		if (n > 0) {
			solve(x, y, n);
			free(x);
			free(y);
		}
	} else {
		int n = 5;
		double *x;
		double *y;
		x = (double[5]){1.1, 2.2, 2.9, 4.1, 5.0};
		y = (double[5]){1.1, 2.2, 3.1, 4.2, 5.0};

		double *result = solve(x, y, n);

		double a = result[0];
		double b = result[1];

		double k = a;
		double L = -b / a;

		printf("%lf %lf %lf\n", a, b, L);

		printf("The corresponding line is: %lfx + %lf\n", k, b);
		printf("This means that k = %lf and L = %lf\n", k, L);

	}
	return 0;

}
