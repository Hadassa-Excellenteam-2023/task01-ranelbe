#include <Vector.h>
#include <stdexcept>


// ======================== c-tors & d-tor =======================

/**
 * ctor creates a vector with a given size and value
 * @param size the size of the vector
 * @param value the value to initialize the vector with
 **/
Vector::Vector(size_t size, int value):
	m_size(size),
	m_capacity(size),
	m_vector(new int[size])
{
	for (size_t i = 0; i < m_size; ++i) {
		m_vector[i] = value; 
	}
}

/**
 * copy ctor creates a vector from another vector
 * @param other the vector to copy
 **/
Vector::Vector(const Vector& other):
	m_size(other.m_size),
	m_capacity(other.m_capacity),
	m_vector(new int[m_capacity])
{
	for (size_t i = 0; i < m_size && i < m_capacity; ++i) {
		m_vector[i] = other.m_vector[i];
	}
}

/**
 * moving ctor move a vector to another vector
 * @param other the vector to move
 **/
Vector::Vector(Vector&& other) noexcept:
	m_size(other.m_size),
	m_capacity(other.m_capacity),
	m_vector(other.m_vector)
{
	// prevent access of the moved vector to the memory
	other.m_vector = nullptr; 
	other.m_size = other.m_capacity = 0;
}

/**
 * d-tor deletes the vector and frees the memory
 **/
Vector::~Vector()
{
	delete[] m_vector;
}


// ======================== methods ==============================

int* Vector::data()
{
	return m_vector;
}

const int* Vector::data() const
{
	return m_vector;
}

bool Vector::empty() const
{
	return m_size == 0;
}

size_t Vector::size() const
{
	return m_size;
}

size_t Vector::capacity() const
{
	return m_capacity;
}

/**
 * clear the vector and free the memory
 **/
void Vector::clear()
{
	delete[] m_vector;
	m_vector = nullptr;
	m_size = m_capacity = 0;
}

/**
 * reserve memory for the vector
 * @param size the new size of the vector
 **/
void Vector::reserve(size_t size)
{
	if (size > m_capacity) {
		// allocate new memory
		int* newVector = new int[size];
		// copy the old vector to the new vector
		for (size_t i = 0; i < m_size; ++i) {
			newVector[i] = m_vector[i];
		}
		// free the old memory and update the vector
		delete[] m_vector;
		m_vector = newVector;
		m_capacity = size;
	}
}

/**
 * resize the vector
 * @param size the new size of the vector
 * @param value the value to fill the new cells with default is 0
 **/
void Vector::resize(size_t size, int value)
{
	reserve(size); // increase the capacity if needed
	// fill the rest of the vector with the given value
	for (size_t i = m_size; i < size; ++i) {
		m_vector[i] = value;
	}
	m_size = size;
}


/**
 * swap the current vector with another vector
 * @param other the vector to swap with
 **/
void Vector::swap(Vector& other) noexcept
{
	std::swap(m_size, other.m_size);
	std::swap(m_capacity, other.m_capacity);
	std::swap(m_vector, other.m_vector);
}


/**
 * push_back adds a new element to the end of the vector
 * @param value the value to add to the vector
 **/
void Vector::push_back(int value)
{
	check_capacity();
	m_vector[m_size++] = value;
}


/**
 * pop_back removes the last element from the vector
 **/
void Vector::pop_back()
{
	if (m_size > 0) {
		--m_size;
	}
}

/**
 * insert new element to the vector at the given position
 * @param pos the position to insert     
 * @param value the value to insert
 **/
void Vector::insert(size_t pos, int value)
{
	//insert value at the given pos
	if (pos > m_size) {
		throw std::out_of_range("Index is out of range");
	}
	check_capacity();
	for (size_t i = m_size; i > pos; --i) {
		m_vector[i] = m_vector[i - 1];
	}
	m_vector[pos] = value;
	++m_size;	
}

/**
 * erase the element at the given position
 * @param pos the position to erase
 **/
void Vector::erase(size_t pos)
{
	//erase the element at the given pos
	if (pos >= m_size) {
		throw std::out_of_range("Index is out of range");
	}
	for (size_t i = pos; i < m_size - 1; ++i) {
		m_vector[i] = m_vector[i + 1];
	}
	--m_size;
}

// ==================== operators overloading ====================

/**
 * operator= assigns a vector to another vector
 * @param other the vector to assign
 * @return the vector after the assignment
 **/
Vector& Vector::operator=(const Vector& other)
{
	// copy and swap idiom implementation
	if (this != &other)
	{
		Vector tmp(other); // use the copy ctor to create a new temp vector
		this->swap(tmp); // swap the current vector with the temp vector
	}
	return *this; 
}

/**
* operator= move a vector to another vector
* @param other the vector to move
* @return the vector after moving other to it
**/
Vector& Vector::operator=(Vector&& other) noexcept
{
	if (this != &other)
	{
		// move and swap idiom implementation
		this->swap(other);
		other.m_vector = nullptr;
		other.m_size = other.m_capacity = 0;
	}
	return *this;
}


/**
 * operator[] regular and const versions
 * @param index the index of the element to return
 * @return the element at the given index
 **/
int& Vector::operator[](size_t index)
{
	if (index >= m_size) {
		throw std::out_of_range("Index out of range");
	}
	return m_vector[index];
}
const int& Vector::operator[](size_t index) const
{
	if (index >= m_size) {
		throw std::out_of_range("Index out of range");
	}
	return m_vector[index];
}

/**
 * operator== checks if two vectors are equal
 * @param other the vector to compare with
 * @return true if the vectors are equal, false otherwise
 **/
bool Vector::operator==(const Vector& other) const
{
	if (m_size == other.m_size && 
		std::equal(m_vector, m_vector + m_size, other.m_vector)) {
			return true;
	}
	return false;
}


/**
 * operator<=> compares two vectors
 * @param other the the vector to compare with  
 * @return the equal less or greater  
 **/
std::strong_ordering Vector::operator<=>(const Vector& other) const noexcept
{
	if (*this == other) {
		return std::strong_ordering::equal;
	} 
	else if (m_size < other.m_size) {
		return std::strong_ordering::less;
	}
	return std::strong_ordering::greater;
}


// ==================== private methods ==========================

/**
 * check_capacity checks if the vector is full and if so, reserve more memory
 **/
void Vector::check_capacity()
{
	// if capacity is 0, reserve 1 cell
	if (m_capacity == 0) {
		reserve(1);
	}
	// if capacity is equal to size, reserve more memory
	else if (m_capacity == m_size) {
		m_capacity < 128 ? reserve(m_capacity * 2) : reserve(m_capacity * 1.5);
	}
}