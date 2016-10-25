#include <iostream>
#include "Complex.h"

int main()
{
	Complex c1(6, 4);
	Complex c2(8, 4);
	Complex sum = c1 + c2;
	std::cout << "Real:" << sum.getReal() << " imaginary:" << sum.getImaginary() << std::endl;

	return 0;
}