#include "Stack.h"

// ======================== c-tors & d-tor =======================

/**
 * ctor creates a stack with a given size and value
 * @param size the size of the stack 
 * @param value the value to initialize the stack with 
 **/
Stack::Stack(size_t size, int value)
	: m_stack(size, value) {}

/**
 * copy ctor creates a stack from another stack
 * @param other the stack to copy
 **/
Stack::Stack(const Stack& other)
	: m_stack(other.m_stack) {}

/**
 * moving ctor move a stack to another stack
 * @param other the stack to move
 **/
Stack::Stack(Stack&& other) noexcept
	: m_stack(std::move(other.m_stack)) {}

// ======================== methods ==============================

/**
 * pushing a value to the stack
 * @param value the value to push
 **/
void Stack::push(int value)
{
	m_stack.push_back(value);
}

/**
 * poping a value from the stack
 **/
void Stack::pop()
{
	m_stack.pop_back();
}

/**
 * check if the stack is empty
 * @return true if the stack is empty, false otherwise
 **/
bool Stack::isEmpty() const
{
	return m_stack.empty();
}

// ==================== operators overloading ====================

/**
 * operator= assigns a stack to another stack
 * @param other the stack to assign
 * @return the stack after the assignment
 **/
Stack& Stack::operator=(const Stack& other)
{
	m_stack = other.m_stack;
	return *this;
}

/**
 * operator= move a stack to another stack
 * @param other the stack to move
 * @return the stack after the assignment
 **/
Stack& Stack::operator=(Stack&& other) noexcept
{
	m_stack = std::move(other.m_stack);
	return *this;
}

/**
 * operator== checks if two stacks are equal
 * @param other the stack to compare to
 * @return true if the stacks are equal, false otherwise
 **/
bool Stack::operator==(const Stack& other) const
{
	return m_stack == other.m_stack;
}

/**
 * operator!= checks if two stacks are not equal
 * @param other the stack to compare to
 * @return true if the stacks are not equal, false otherwise
 **/
bool Stack::operator!=(const Stack& other) const
{
	return m_stack != other.m_stack;
}

/**
 * operator += adds a value to all the elements in the stack
 * @param value the value to add 
 * @return the stack after the addition
 **/
Stack& Stack::operator+=(int value)
{
	for (auto& element : m_stack) {
		element += value;
	}
	return *this;
}

/**
 * operator -= substract a value from all the elements in the stack
 * @param value the value to substract
 * @return the stack after the substraction
 **/
Stack& Stack::operator-=(int value)
{
	*this += -value;
	return *this;
}

/**
 * operator *= multiplies all values in the stack by a given value
 * @param value the value to multiply by
 * @return the stack after the multiplication
 **/
Stack& Stack::operator*=(int value)
{
	for (auto& element : m_stack) {
		element *= value;
	}
	return *this;
}

/**
 * operator /= divides all values in the stack by a given value
 * * @param value the value to divide by
 * * @return the stack after the division
 * **/
Stack& Stack::operator/=(int value)
{
	if (value == 0) {
		throw std::invalid_argument("cannot divide by zero");
	}
	for (auto& element : m_stack) {
		element /= value;
	}
	return *this;
}

/**
 * operator + concatenate two stacks
 * @param other the stack to concatenate
 * @return the new stack after the concatenation
 **/
Stack Stack::operator+(const Stack& other) const
{
	//concatinate the two stacks
	Stack newStack(*this);
	for (auto& element : other.m_stack) {
		newStack.push(element);
	}
	return newStack;
}

Stack& Stack::operator+=(const Stack& other)
{
	*this = *this + other;
	return *this;
}

/**
 * operator<=> compares two stacks
 * @param other the stack to compare to
 * @return std::strong_ordering of the stacks
 **/
std::strong_ordering Stack::operator<=>(const Stack& other) const noexcept
{
	return m_stack <=> other.m_stack;
}

// ==================== global functions =========================

/**
 * operator<< prints the stack
 * @param os the output stream
 * @param stack the stack to print
 * @return the output stream
 **/
std::ostream& operator<<(std::ostream& os, const Stack& stack)
{
    os << stack.m_stack;
    return os;
}