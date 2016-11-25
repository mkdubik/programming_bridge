#include <iostream>

#include "Vector.h"

int main()
{
	Vector<int> vc = Vector<int>::random(10);

	//vc[1] = 3;

	std::vector<int> v2;
	v2.push_back(5);
	v2.push_back(6);
	Vector<int> vx = Vector<int>::set(v2);
	std::cout << vx.to_string() << std::endl;

	/*std::vector<int> v2;
	v2.push_back(5);
	v2.push_back(6);

	Vector<int> vx(v2);

	Vector<int> vy = vc * vx;*/

	return 0;
}