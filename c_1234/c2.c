#include <stdio.h>
#include <math.h>

const static int MAX_ITERATIONS = 10000;

double newton(double x0, double epsilon,
			double (*f)(double), double (*fprim)(double)) {

	double xi = x0 - (f(x0) / fprim(x0));
	int i = 0;
	while (fabs(xi - x0) > epsilon) {
		x0 = xi;
		xi = xi - (f(xi) / fprim(xi));

		if (i > MAX_ITERATIONS) {
			// Make sure not to end up in an endless loop
			// for bad input functions
			return xi;
		}
		i++;
	}
	return xi;
}

double f(double v) {
	return 70.0 * pow(v, 3.0) - 3.0 * pow(v, 2.0) + 4.0 * v - 16.0;
}

double fprim(double v) {
	return 210.0 * pow(v, 2.0) - 6.0 * v + 4.0;
}

int main() {
	double ini_est;

	printf("Input your initial estimate: ");
	scanf("%lf", &ini_est);

	double eps;
	printf("Input your epsilon: ");
	scanf("%lf", &eps);

	ini_est = 1.0;
	eps = 0.001;

	printf("Root of f: %lf\n", newton(ini_est, eps, &f, &fprim));

}