#ifndef VECTOR_H_
#define VECTOR_H_

#include <vector>

template <class T>
class Vector
{
	public:
		Vector (std::vector<T> t);

		void put(int ix, T value);
		T get(int ix);

		void write();


	private:
		std::vector<T> v;
};

template<typename T>
Vector<T> operator*(const Vector<T> &c1, const Vector<T> &c2)
{
	return c2;
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