#include "Matrix.h"

Matrix::Matrix(std::vector<std::vector<int> > input)
{
	a = input;
}

/*
Matrix::Matrix(std::vector<std::vector<float>> input)
{
	a = input;
}

Matrix::Matrix(std::vector<std::vector<double>> input)
{
	a = input;
}

Matrix operator*(const Complex &c1, const Complex &c2)
{
	return Complex(c1.real * c2.real - c1.img * c2.img,
				c1.real * c2.img + c1.img * c2.real);
}

Matrix operator*(const double a, const Complex &c2)
{
	return Complex(a * c2.real, a * c2.img);
}

Matrix operator*(const Complex &c1, const double b)
{
	return Complex(c1.real * b, c1.img * b);
}*/
