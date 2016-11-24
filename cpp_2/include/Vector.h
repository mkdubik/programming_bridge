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
		Vector<T> ();
		Vector<T> (std::vector<T> t);
		Vector<T> ones(unsigned int size);

		T operator*(const Vector<T> &c1);
		T operator[](unsigned int x) const;
		T& operator[](unsigned int x);

		std::string to_string();

	private:
		std::vector<T> v;
};

template<typename T>
Vector<T>::Vector() {}

template<typename T>
Vector<T>::Vector(std::vector<T> t)
{
	v = t;
}

template<typename T>
Vector<T> Vector<T>::ones(unsigned int size)
{
	Vector<T> r;
	std::srand(std::time(0));
	for (unsigned int i = 0; i < size; i++)
	{
		r.v.push_back((T)1);
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
std::string Vector<T>::to_string()
{
	size_t vsz = v.size();
	if (vsz < 1) {
		return "";
	}

	std::stringstream ss;
	unsigned int i = 0;
	while (1) {
		ss << v[i];

		if (i >= vsz)
			break;

		ss << " ";
		i++;
	}
	return ss.str();
}


#endif
