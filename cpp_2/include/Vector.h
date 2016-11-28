#ifndef VECTOR_H_
#define VECTOR_H_

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <cmath>

template <class T>
class Vector
{
	public:
		/*
			Data invariant:
				Vector is a class that wraps the STL container vector
				and adds additional mathematical operations to it.
				Supported types are int, float and double
		*/
		Vector<T> (void);

		/*
			Usage: Vector<T> v = Vector<T>::set_vector(std::vector t);
			Post: New Vector is created from a STL vector
		*/
		static Vector<T> set_vector(std::vector<T> t);

		/*
			Usage: Vector<T> v = Vector<T>::ones(std::vector t);
			Post: New Vector is created of size size and contains only 1's
		*/
		static Vector<T> ones(unsigned int size);

		/*
			Usage: Vector<T> v = Vector<T>::random(std::vector t);
			Post: New Vector is created of size size and contains random numbers
			if int: contains only 0's
			if float/double: Range from 0 to 1
		*/
		static Vector<T> random(unsigned int size);

		/*
			Usage: T v = Vector<T> * Vector<T>;
			Post: Vector * vector will result in a scalar value
		*/
		T operator*(const Vector<T> &c1);

		/*
			Usage: Vector<double> v = Vector<T> - Vector<T>;
			Post: Subtract 2 vectors, result is a double vector
		*/
		Vector<double> operator-(const Vector<T> &c1);

		/*
			Usage: Vector<double> v = Vector<T> / T;
			Post: Divide vector with a scalar, result is a double vector
		*/
		Vector<double> operator/(const T &t);

		/*
			Usage: T v = Vector<T>[<unsigned int x>];
			Post: Returns element T from Vector at position x
		*/
		T operator[](unsigned int x) const;

		/*
			Usage: Vector<T>[<unsigned int x>] = T;
			Post: Sets element T to Vector at position x
		*/
		T& operator[](unsigned int x);

		/*
			Usage: T t = Vector<T>.vsum();
			Post: Returns the sum of all values in Vector
		*/
		T vsum();

		/*
			Usage: T t = Vector<T>.vmax();
			Post: Returns the largest element in Vector
		*/
		T vmax();

		/*
			Usage: Vector<T>.push(T);
			Post: pushes value T into the vector, increasing its size by 1
		*/
		void push(T t);

		/*
			Usage: unsigned int i = Vector<T>.size();
			Post: Return the size of Vector
		*/
		unsigned int size() const;

		/*
			Usage: std::string s = Vector<T>.to_string();
			Post: Get string representation of Vector
		*/
		std::string to_string();

	private:
		std::vector<T> v;
};

template<typename T>
Vector<T>::Vector(void) {}

template<typename T>
Vector<T> Vector<T>::set_vector(std::vector<T> t)
{
	Vector<T> v;
	v.v = t;
	return v;
}

template<typename T>
Vector<T> Vector<T>::ones(unsigned int size)
{
	Vector<T> r;
	for (unsigned int i = 0; i < size; i++)
	{
		r.v.push_back((T)1);
	}
	return r;
}

template<typename T>
Vector<T> Vector<T>::random(unsigned int size)
{

	Vector<T> r;
	for (unsigned int i = 0; i < size; i++)
	{
		r.v.push_back(((T)rand() / (T)RAND_MAX));
	}
	return r;
}

template<typename T>
T Vector<T>::operator*(const Vector<T> &c1)
{
	if (v.size() != c1.v.size()) {
		throw std::runtime_error("Vectors must be equal size");
	}

	T t = 0;
	for (unsigned int i = 0, length = v.size(); i < length; ++i) {
		t += v[i] * c1.v[i];
	}

	return t;
}

template<typename T>
Vector<double> Vector<T>::operator-(const Vector<T> &c1)
{
	Vector<double> vr;
	if (v.size() != c1.v.size()) {
		throw std::runtime_error("Vectors must be equal size");
	}

	for (unsigned int i = 0, length = v.size(); i < length; ++i) {
		vr.push((double)(v[i]) - (double)(c1.v[i]));
	}

	return vr;
}

template<typename T>
Vector<double> Vector<T>::operator/(const T &t)
{
	Vector<double> vr;
	for (unsigned int i = 0, length = v.size(); i < length; ++i) {
		if (t == 0) {
			vr.push(nan(""));
		} else {
			vr.push((double)v[i] / (double)t);
		}
	}
	return vr;
}

template<typename T>
T Vector<T>::operator[](unsigned int ix) const
{
	return v[ix];
}

template<typename T>
T& Vector<T>::operator[](unsigned int ix)
{
	return v[ix];
}

template<typename T>
void Vector<T>::push(T t)
{
	v.push_back(t);
}

template<typename T>
unsigned int Vector<T>::size() const
{
	return v.size();
}

template<typename T>
T Vector<T>::vsum()
{
	T t = 0;
	for(typename std::vector<T>::iterator it = v.begin(); it != v.end(); ++it)
	{
		t += *it;
	}
	return t;
}

template<typename T>
T Vector<T>::vmax()
{
	return *std::max_element(v.begin(), v.end());
}

template<typename T>
std::string Vector<T>::to_string()
{
	unsigned int size = v.size();
	if (size == 0)
	{
		return "[]";
	}

	std::stringstream ss;
	ss << "[";
	for (unsigned int i = 0; i < size; i++)
	{
		ss << v[i] << ", ";
	}
	ss << "]";
	std::string str = ss.str();
	str.erase(str.size() - 3, 2);
	return str;
}

#endif
