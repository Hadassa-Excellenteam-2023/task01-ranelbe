#pragma once
#include <compare>
#include <iostream>

class Vector
{

public:
	// ========== c-tors & d-tor ===============
	explicit Vector(size_t size = 0, int value = 0);
	Vector(const Vector& other);
	Vector(Vector&& other) noexcept;
	~Vector();

	// ========== methods ======================
	int* data();
	const int* data() const;
	bool empty() const;
	size_t size() const;
	size_t capacity() const;
	void clear();
	void reserve(size_t size);
	void resize(size_t size, int value = 0);
	void swap(Vector& other) noexcept;
	void push_back(int value);
	void pop_back();
	void insert(size_t pos, int value);
	void erase(size_t pos);

	// ========= operators overloading =========
	Vector& operator=(const Vector& other);
	Vector& operator=(Vector&& other) noexcept;

	int& operator[](size_t index);
	const int& operator[](size_t index) const;

	bool operator==(const Vector& other) const;
	std::strong_ordering operator<=>(const Vector& other) const noexcept;


private:
	// ========= private methods ================
	void check_capacity();

	// ========= private members ================
	size_t m_size;
	size_t m_capacity;
	int* m_vector = nullptr;
};

//print the vector
std::ostream& operator<<(std::ostream& os, const Vector& vector);