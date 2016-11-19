#include <iostream>

#include "Vector.h"

int main()
{
	std::vector<int> v1;
	v1.push_back(5);
	v1.push_back(6);

	Vector<int> vc(v1);
	vc.put(0, 10);
	vc.put(1, 20);

	std::vector<int> v2;
	v2.push_back(5);
	v2.push_back(6);

	Vector<int> vx(v2);
	vx.put(0, 10);
	vx.put(1, 20);

	Vector<int> vy = vc * vx;
	vc.write();

	return 0;
}