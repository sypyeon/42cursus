#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
private:
	T *array;
	unsigned int n;
public:
	Array();
	Array(unsigned int n);
	Array(const Array &other);
	Array &operator=(const Array &other);

	T operator[](unsigned int n) const;
	T &operator[](unsigned int n);
	unsigned int size() const;
	~Array();
};

#include "Array.tpp"

#endif