#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
	public:
		Complex(int a, int b);

		friend Complex operator+(const Complex &c1, const Complex &c2);
		int getReal();
		int getImaginary();

		//Complex sub(Complex a, Complex b);
		//Complex mul(Complex a, Complex b);
		//Complex div(Complex a, Complex b);

	private:
		int real;
		int imaginary;

};

#endif