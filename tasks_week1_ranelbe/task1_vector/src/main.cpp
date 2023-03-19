#include <iostream>
#include <iostream>
#include "Vector.h"
#include <vector>

int main()
{
	// check the default ctor
	Vector v1(1);
	Vector v2(2, 1);
	std::cout << "v1: " << v1 << "\nv2: " << v2;

	// check the copy ctor
	Vector v3(v1);
	Vector v4(v2);
	std::cout << "\nv3: " << v3 << "\nv4: " << v4;

	// check the move ctor
	Vector v5(std::move(v3)); //v3 is now empty
	std::cout << "\nv5: " << v5;
	
	// check the operator=
	Vector v6 = v4;
	std::cout << "\nv6: " << v6;

	// check the moving operator=
	Vector v7 = std::move(v5); //v5 is now empty
	std::cout << "\nv7: " << v7;

	// check the operator[] the regular version
	v2[1] = 5;
	std::cout << "\nv2: " << v2;

	// check the operator[] the const version
	const Vector v8(2, 1);
	std::cout << "\nv8[0]: " << v8[0];

	// check the data method
	std::cout << "\nv2.data(): " << v2.data();

	// check the empty method
	std::cout << "\nv2.empty(): " << (v2.empty() ? "empty" : "not empty");
	
	// check the push_back method and insert method
	v2.push_back(3);
	v2.insert(1, 4);
	v2.push_back(5);
	v2.insert(4, 6);
	std::cout << "\nv2: " << v2;

	// check the size and capacity methods
	std::cout << "\nv2.size(): " << v2.size();
	std::cout << "\nv2.capacity(): " << v2.capacity();
	
	//check the pop_back method and erase method
	v2.pop_back();
	v2.erase(1);
	std::cout << "\nv2: " << v2;

	//check the resize method
	v2.resize(10, 1);
	v2.resize(6);
	std::cout << "\nv2: " << v2;
	std::cout << "\nv2.size(): " << v2.size();
	std::cout << "\nv2.capacity(): " << v2.capacity();

	//check the clear method
	v2.clear();
	std::cout << "\nv2.clear(): " << v2;

	//check the swap method
	v2.swap(v4);
	std::cout << "\nv2: " << v2 << "\nv4: " << v4;

	//check the comparation operators
	std::cout << "\nv2 == v4: " << (v2 == v4 ? "true" : "false");
	std::cout << "\nv2 == v6: " << (v2 == v6 ? "true" : "false");
	std::cout << "\nv2 != v4: " << (v2 != v4 ? "true" : "false");
	std::cout << "\nv2 < v4: " << (v2 < v4 ? "true" : "false");
	std::cout << "\nv2 <= v4: " << (v2 <= v4 ? "true" : "false");
	std::cout << "\nv2 > v4: " << (v2 > v4 ? "true" : "false");
	std::cout << "\nv2 >= v4: " << (v2 >= v4 ? "true" : "false");

	return 0;
}