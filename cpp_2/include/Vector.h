#ifndef VECTOR_H_
#define VECTOR_H_

#include <vector>
#include <sstream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

template <class T>
class Vector
{
	public:
		Vector<T> (void);

		static Vector<T> set_vector(std::vector<T> t);
		static Vector<T> ones(unsigned int size);
		static Vector<T> random(unsigned int size);


		T operator*(const Vector<T> &c1);
		T operator[](unsigned int x) const;
		T& operator[](unsigned int x);

		unsigned int size();
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
	std::srand(std::time(NULL));

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
unsigned int Vector<T>::size()
{
	return v.size();
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
