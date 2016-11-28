#include <iostream>

#include <Matrix.h>
#include <Random.h>

template <typename T>
void run_test(T arg)
{
	if (arg == 0)
		std::cout << "Test int" << std::endl;
	if (arg == 0.33f)
		std::cout << "Test float" << std::endl;
	if (arg == 0.33)
		std::cout << "Test double" << std::endl;

	Vector<T> x0 = Vector<T>::ones(2);
	Matrix<T> A = Matrix<T>::random(2, 2);

	Vector<T> xk = A * x0;
	std::cout << "A:\n" << A.to_string() << std::endl;
	std::cout << "x0: " << x0.to_string() << std::endl;
	std::cout << "xk: " << xk.to_string() << std::endl;
	std::cout << "max of x0: " << x0.vmax() << std::endl;
	std::cout << "sum of x0: " << x0.vsum() << std::endl;
	std::cout << "max of xk: " << xk.vmax() << std::endl;
	std::cout << "sum of xk: " << xk.vsum() << std::endl;

	std::vector<Vector<T> > v;
	Vector<T> row1;
	Vector<T> row2;

	row1.push(0.1183827188940797);
	row1.push(0.19422572522120551);
	row2.push(0.7906182589718848);
	row2.push(0.667710849058064);

	v.push_back(row1);
	v.push_back(row2);
	std::cout << std::endl << "Vector[0] before setting " << row1[0]	 << std::endl;
	row1[0] = 0.99;
	std::cout << std::endl << "Vector[0] after setting " << row1[0] << std::endl;

	Matrix<T> A0 = Matrix<T>::set_matrix(v);
	Vector<T> row0;
	row0.push(0.11);
	row0.push(0.99);

	std::cout << std::endl << "Matrix[0] before setting " << A0[0].to_string() << std::endl;

	A0[0] = row0;
	std::cout << std::endl << "Matrix[0 after setting " << A0[0].to_string() << std::endl;

	A0[0][0] = 1.12345;
	std::cout << std::endl << "Matrix[0][0] after setting " << A0[0][0] << std::endl;
}

int main()
{
	seed_random();

	std::cout << "=====START TEST===="<< std::endl;
	run_test(0);
	std::cout << "=================== "<< std::endl;
	run_test(0.33f);
	std::cout << "=================== "<< std::endl;
	run_test(0.33);
	std::cout << "=================== "<< std::endl;
	return 0;
}