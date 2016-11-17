#include <iostream>
#include <math.h>
#include "Complex.h"
#define MAX_ITERATIONS 1000

class Newton_Raphson {

	public:
		virtual Complex f(Complex x)=0;
		virtual Complex f_prime(Complex x)=0;

		Complex newton_raphson(Complex x0, double epsilon)
		{
			Complex xi = x0 - (f(x0) / f_prime(x0));

			int i = 0;
			while (fabs((xi - x0).get_absolute()) > epsilon) {
				x0 = xi;
				xi = xi - (f(xi) / f_prime(xi));

				if (i > MAX_ITERATIONS) {
					// Make sure not to end up in an endless loop
					// for bad input functions
					return xi;
				}
				i++;
			}
			return xi;
		}

};

class Equation : public Newton_Raphson
{
	public:
		Complex f(Complex x)
		{
			return x * x + 2 * x + 2;
		}

		Complex f_prime(Complex x)
		{
			return 2 * x + 2;
		}

};


int main()
{
	double eps;
	std::cout << "Please type in epsilon (double) ";
	std::cin >> eps;
	Equation eq;
	Complex c = Complex::read();
	Complex result = eq.newton_raphson(c, eps);
	result.write();
	return 0;
}