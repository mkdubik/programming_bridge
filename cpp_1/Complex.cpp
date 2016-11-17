#include "Complex.h"
#include <sstream>
#include <cmath>
#include <iostream>
#include <stdexcept>

Complex::Complex(double a, double b)
{
	real = a;
	img = b;
}

Complex operator+(const Complex &c1, const Complex &c2)
{
	return Complex(c1.real + c2.real, c1.img + c2.img);
}

Complex operator+(const double a, const Complex &c2)
{
	return Complex(a + c2.real, c2.img);
}

Complex operator+(const Complex &c1, const double b)
{
	return Complex(c1.real + b, c1.img);
}

Complex operator-(const Complex &c1, const Complex &c2)
{
	return Complex(c1.real - c2.real, c1.img - c2.img);
}

Complex operator-(const double a, const Complex &c2)
{
	return Complex(a - c2.real, c2.img);
}

Complex operator-(const Complex &c1, const double b)
{
	return Complex(c1.real - b, c1.img);
}

Complex operator*(const Complex &c1, const Complex &c2)
{
	return Complex(c1.real * c2.real - c1.img * c2.img,
				c1.real * c2.img + c1.img * c2.real);
}

Complex operator*(const double a, const Complex &c2)
{
	return Complex(a * c2.real, a * c2.img);
}

Complex operator*(const Complex &c1, const double b)
{
	return Complex(c1.real * b, c1.img * b);
}

Complex operator/(const Complex &c1, const Complex &c2)
{
	Complex cj = Complex(c2.real, -1 * c2.img);

	double real_numerator = c1.real * cj.real + (c1.img * cj.img * -1);
	double imaginary_numerator = c1.real * cj.img + c1.img * cj.real;

	double real_divisor = c2.real * cj.real + (c2.img * cj.img * -1);
	double imaginary_divisor = c2.real * cj.img + c2.img * cj.real;

	if (imaginary_divisor != 0.0)
		throw std::invalid_argument( "Imaginary divisor has to be 0!" );

	if (real_divisor == 0.0)
		return Complex(nan(" "), nan(" "));

	return Complex(real_numerator / real_divisor,
					imaginary_numerator / real_divisor);
}

Complex operator/(const double a, const Complex &c2)
{
	if (c2.real == 0.0 || c2.img == 0.0)
		return Complex(nan(" "), nan(" "));
	return Complex(a / c2.real, a / c2.img);
}

Complex operator/(const Complex &c1, const double b)
{
	if (b == 0.0)
		return Complex(nan(" "), nan(" "));
	return Complex(c1.real / b, c1.img / b);
}

double Complex::get_absolute()
{
	return std::sqrt(std::pow(this->real, 2) + std::pow(this->img, 2));
}

double Complex::get_real()
{
	return real;
}

double Complex::get_imaginary()
{
	return img;
}

void Complex::write()
{
	std::ostringstream r, i;
	r << this->real;
	if (this->img < 0) {
		i << -1 * this->img;
		std::cout << r.str() + " - " + i.str() + "i" << std::endl;
		return;
	}
	i << this->img;
	std::cout << r.str() + " + " + i.str() + "i" << std::endl;
}

Complex Complex::read()
{
	double real, img;
	std::cout << "Enter a real number and an imaginary, seperated by space: ";
	std::cin >>  real >> img;
	return Complex(real, img);
}

