#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix
{
	public:
		Matrix(std::vector<std::vector<int> > a);

		/*
		Matrix(std::vector<std::vector<float>> a);
		Matrix(std::vector<std::vector<double>> a);

		friend Matrix operator*(const Matrix &c1, const Matrix &c2);
		template<typename T>
		friend Matrix operator*(T&a , const Matrix &c2);
		template<typename T>
		friend Matrix operator*(const Matrix &c1, T&b);*/

	private:
		template<typename T>
		std::vector<std::vector<T> > a;
};

#endif