#ifndef COMPLEX_H
#define COMPLEX_H

#include <vector>
#include <string>

class Complex
{
	public:
		Complex(double a, double b);

		friend Complex operator+(const Complex &c1, const Complex &c2);
		friend Complex operator+(const double a, const Complex &c2);
		friend Complex operator+(const Complex &c1, const double b);

		friend Complex operator-(const Complex &c1, const Complex &c2);
		friend Complex operator-(const double a, const Complex &c2);
		friend Complex operator-(const Complex &c1, const double b);

		friend Complex operator*(const Complex &c1, const Complex &c2);
		friend Complex operator*(const double a, const Complex &c2);
		friend Complex operator*(const Complex &c1, const double b);

		friend Complex operator/(const Complex &c1, const Complex &c2);
		friend Complex operator/(const double a, const Complex &c2);
		friend Complex operator/(const Complex &c1, const double b);

		double get_absolute();
		double get_real();
		double get_imaginary();

		static Complex read();
		void write();


	private:
		double real;
		double img;
};

#endif