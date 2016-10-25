class Complex {

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


Complex::Complex(int a, int b) {
	real = a;
	imaginary = b;
}

Complex operator+(const Complex &c1, const Complex &c2)
{
	return Complex(c1.real + c2.real, c1.imaginary + c2.imaginary);
}

int Complex::getReal()
{
	return real;

}

int Complex::getImaginary()
{
	return imaginary;
}
