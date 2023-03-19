#include <iostream>
#include "Vector.h"
#include "Stack.h"

void vector_test() {
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
}

void stack_test() {
	// check the default ctor
	Stack s1(1);
	Stack s2(2, 1);
	std::cout << "s1: " << s1 << "\ns2: " << s2;

	// check the copy ctor
	Stack s3(s1);
	Stack s4(s2);
	std::cout << "\ns3: " << s3 << "\ns4: " << s4;

	// check the move ctor
	Stack s5(std::move(s3)); //s3 is now empty
	std::cout << "\ns5: " << s5;

	// check the operator=
	Stack s6 = s4;
	std::cout << "\ns6: " << s6;

	// check the moving operator=
	Stack s7 = std::move(s5); //s5 is now empty
	std::cout << "\ns7: " << s7;

	// check the push and pop methods
	s2.push(3);
	s2.push(4);
	s2.push(5);
	std::cout << "\ns2: " << s2;
	s2.pop();
	std::cout << "\ns2: " << s2;

	// check the isEmpty method
	std::cout << "\ns2.empty(): " << (s2.isEmpty() ? "empty" : "not empty");

	//check the comparation operators
	std::cout << "\ns2 == s4: " << (s2 == s4 ? "true" : "false");
	std::cout << "\ns4 == s6: " << (s4 == s6 ? "true" : "false");
	std::cout << "\ns4 != s6: " << (s4 != s6 ? "true" : "false");
	std::cout << "\ns4 < s6: " << (s4 < s6 ? "true" : "false");
	std::cout << "\ns4 <= s6: " << (s4 <= s6 ? "true" : "false");
	std::cout << "\ns4 > s6: " << (s4 > s6 ? "true" : "false");
	std::cout << "\ns4 > s2: " << (s4 > s2 ? "true" : "false");
	std::cout << "\ns4 >= s6: " << (s4 >= s6 ? "true" : "false");

	// check the arithmetic operators
	s2 += 3;
	std::cout << "\ns2+=3: " << s2;
	s2 -= 2;
	std::cout << "\ns2-=2: " << s2;
	s2 *= 3;
	std::cout << "\ns2*=3: " << s2;
	s2 /= 3;
	std::cout << "\ns2/=3: " << s2;

	// check the operators between two stacks
	s2+=s4+=s1+=s2;
	std::cout << "\ns2+=s4+=s1+=s2: " << s2;
}


int main()
{
	vector_test();
	stack_test();
	return 0;
}

