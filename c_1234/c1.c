#include <stdio.h>

static double E = 20;
static double L = 5;
static double R = 10;
static double h = 0.01;

double dydx(double t, double I) {
	// Calculate Kirchoff's law differential equation
	double E_L = E/L;
	double R_L = R/L;
	return E_L - R_L * I;
}

double predictor_func(double t, double I) {
	// Calculate predictor (yp)
	return I + h * dydx(t, I);
}

double predcorr(double t, double I) {
	// Calculate the corrector
	double yp = predictor_func(t, I);
	return I + 0.5 * h * (dydx(t, I) + dydx(t + h, yp));
}

int main() {
	double t, I;
	for (t = 0.0, I = 0.0; t < 1; t += h) {
		I = predcorr(t, I);
	}
	printf("I at t = 1 %f\n", I);
	return 0;
}
