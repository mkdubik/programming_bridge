#ifndef VECTOR_H_
#define VECTOR_H_

#include <vector>
#include <sstream>

template <class T>
class Vector
{
	public:
		Vector<T> (std::vector<T> t);

		Vector<T> operator*(const Vector<T> &c1) const;

		T operator[](unsigned int x) const;
		T& operator[](unsigned int x);

		std::string to_string();

	private:
		std::vector<T> v;
};

template<typename T>
Vector<T>::Vector(std::vector<T> t)
{
	v = t;
}

template<typename T>
Vector<T> Vector<T>::operator*(Vector<T> &c1)
{
	/* NOTE
		Vector * Vector = int/float/double
		Matrix * Vector = Vector
		Matrix * Matrix = Matrix
		Vector * Matrix = NOT NEED TO IMPLEMENT
	*/

	return c1;
}

template<typename T>
std::string Vector<T>::to_string()
{
	std::stringstream ss;
	for(size_t i = 0; i < v.size(); ++i)
	{
		ss << v[i];
		ss << " ";
	}
	return ss.str();
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

/*template<typename T>
Vector<T> operator*(const Vector<T> &c1, T c2)
{
	return c1;
}

template<typename T>
Vector<T> operator*(T c1, const Vector<T> &c2)
{
	return c2;
}*/


#endif