#include <iostream>

#include "Vector.h"

int main()
{
	std::vector<int> v1;
	v1.push_back(5);
	v1.push_back(6);

	Vector<int> vc(v1);
	std::cout << vc[0] << std::endl;
	//vc[1] = 3;


	/*std::vector<int> v2;
	v2.push_back(5);
	v2.push_back(6);

	Vector<int> vx(v2);

	Vector<int> vy = vc * vx;*/

	return 0;
}