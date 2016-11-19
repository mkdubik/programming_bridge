#include <Vector.h>
#include <iostream>

template class Vector<int>;
template class Vector<float>;
template class Vector<double>;

template<typename T>
Vector<T>::Vector(std::vector<T> t)
{
	v = t;
}

template<typename T>
void Vector<T>::write()
{
	for (unsigned int i = 0; i < v.size(); i++) {
		std::cout << v[i] << std::endl;
	}
}

template<typename T>
void Vector<T>::put(int ix, T value)
{
	v[ix] = value;
}


template<typename T>
T Vector<T>::get(int ix)
{
	return v[ix];
}
