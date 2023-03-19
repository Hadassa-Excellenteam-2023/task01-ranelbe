#pragma once
#include "Vector.h"

class Stack
{
public:
	// ========== c-tors & d-tor ===============
	explicit Stack(size_t size = 0, int value = 0);
	Stack(const Stack& other);
	Stack(Stack&& other) noexcept;
	~Stack() {}

	// ========== methods ======================
	void push(int value);
	void pop();
	bool isEmpty() const;


	// ========= operators overloading =========
	Stack& operator=(const Stack& other);
	Stack& operator=(Stack&& other) noexcept;
	bool operator==(const Stack& other) const;
	bool operator!=(const Stack& other) const;
	std::strong_ordering operator<=>(const Stack& other) const noexcept;

	//arithmetic operators
	Stack& operator+=(int value);
	Stack& operator-=(int value);
	Stack& operator*=(int value);
	Stack& operator/=(int value);

	//operators between two stacks
	Stack operator+(const Stack& other) const;
	Stack& operator+=(const Stack& other);


private:
	// ========= private members ================
	Vector m_stack;
	friend std::ostream& operator<<(std::ostream& os, const Stack& stack);
};

//print the stack
std::ostream& operator<<(std::ostream& os, const Stack& stack);