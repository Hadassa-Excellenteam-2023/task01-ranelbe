#include <iostream>
#include <iostream>
#include "Vector.h"
#include <vector>

int main()
{
	Vector v1(2,3);
	Vector v2(2,3);

	std::cout << (v1 != v2) << std::endl;
	
	return 0;
}