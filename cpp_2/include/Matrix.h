#ifndef MATRIX_H
#define MATRIX_H_

#include <Vector.h>

template <class T>
class Matrix
{
	public:

		/*
			Data invariant:
				Matrix is a class that is a STL vector of Vector class (that is implemented in this project)  and adds additional mathematical operations to it.
				Supported types are int, float and double
		*/
		Matrix<T> (void);

		/*
			Usage: Matrix<T> v = Matrix<T>::set_matrix(std::vector<Vector <T> > t);
			Post: New Matrix is created from a STL vector of Vectors
		*/
		static Matrix<T> set_matrix(std::vector<Vector <T> > m);

		/*
			Usage: Matrix<T> v = Matrix<T>::ones(unsigned int height, unsigned int width);
			Post: New Matrix is with dimensions height * width and contains only 1's
		*/
		static Matrix<T> ones(unsigned int height, unsigned int width);

		/*
			Usage: Matrix<T> v = Matrix<T>::random(unsigned int height, unsigned int width);
			Post: New Matrix is created with dimensions height * width and contains random numbers
			if int: contains only 0's
			if float/double: Range from 0 to 1
		*/
		static Matrix<T> random(unsigned int height, unsigned int width);

		/*
			Usage: Vector<T> v = Matrix<T> * Vector<T>;
			Post: Matrix * Vector will result in a Vector
		*/
		Vector<T> operator*(const Vector<T> &c1);

		/*
			Usage: Vector<T> v = Matrix<T>[<unsigned int x>];
			Post: Returns Vector of type T from Matrix at position x
		*/
		Vector<T> operator[](unsigned int x) const;

		/*
			Usage: Matrix<T>[<unsigned int x>] = Vector<T>;
			Post: Sets Vector T to Matrix at position x
		*/
		Vector<T>& operator[](unsigned int x);

		/*
			Usage: Matrix<T>.push(Vector<T>);
			Post: pushes Vector<T> into the Matrix, increasing its size by 1
		*/
		void push(Vector<T> c1);

		/*
			Usage: unsigned int i = Matrix<T>.size();
			Post: Return the size of Matrix
		*/
		std::vector<unsigned int> size();

		/*
			Usage: std::string s = Matrix<T>.to_string();
			Post: Get string representation of Matrix
		*/
		std::string to_string();

	private:
		std::vector<Vector<T> > m;
};

template<typename T>
Matrix<T>::Matrix(void) {}

template<typename T>
Matrix<T> Matrix<T>::set_matrix(std::vector<Vector <T> > m)
{
	Matrix<T> mc;
	mc.m = m;
	return mc;
}

template<typename T>
Matrix<T> Matrix<T>::ones(unsigned int height, unsigned int width)
{
	Matrix<T> mc;
	for (unsigned int i = 0; i < height; i++)
	{
		mc.m.push_back(Vector<T>::ones(width));
	}
	return mc;
}

template<typename T>
Matrix<T> Matrix<T>::random(unsigned int height, unsigned int width)
{
	Matrix<T> mc;
	for (unsigned int i = 0; i < height; i++)
	{
		mc.m.push_back(Vector<T>::random(width));
	}
	return mc;
}

template<typename T>
Vector<T> Matrix<T>::operator*(const Vector<T> &c1)
{
	std::vector<unsigned int> size_m = this->size();
	const unsigned int size_v = c1.size();
	if (size_m[1] != size_v)
	{
		throw std::runtime_error("The number of columns in Matrix has to equal the number of components in Vector");
	}

	std::vector<T> v;
	for (unsigned int i = 0; i < size_m[0]; ++i)
	{
		T t = 0;
		for (unsigned int j = 0; j < size_m[1]; ++j)
		{
			t += m[i][j] * c1[j];
		}
		v.push_back(t);
	}
	return Vector<T>::set_vector(v);
}

template<typename T>
Vector<T> Matrix<T>::operator[](unsigned int ix) const
{
	return m[ix];
}

template<typename T>
Vector<T>& Matrix<T>::operator[](const unsigned int ix)
{
	std::cout << m[ix].to_string() << std::endl;
	return m[ix];
}

template<typename T>
void Matrix<T>::push(Vector<T> v)
{
	m.push_back(v);
}

template<typename T>
std::vector<unsigned int> Matrix<T>::size()
{
	std::vector<unsigned int> result;
	if (m.size() != 0)
	{
		result.push_back(m.size());
		result.push_back(m[0].size());
	} else
	{
		result.push_back(0);
		result.push_back(0);
	}
	return result;
}

template<typename T>
std::string Matrix<T>::to_string()
{
	unsigned int height = m.size();
	if (height == 0)
	{
		return "[[]]";
	}

	std::stringstream ss;
	for (unsigned int i = 0; i < height; i++)
	{
		ss << m[i].to_string() << "\n";
	}
	std::string str = ss.str();
	str.erase(str.size() - 1, 1);
	return str;
}

#endif
