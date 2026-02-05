#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	this->array = new T[0];
	this->n = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->array = new T[n];
	this->n = n;
}

template <typename T>
Array<T>::Array(const Array<T> &other)
{
	this->array = new T[other.n];
	this->n = other.n;
	for (unsigned int i = 0; i < this->n; i++)
		this->array[i] = other.array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		delete[] this->array;
		this->array = new T[other.n];
		this->n = other.n;
		for (unsigned int i = 0; i < this->n; i++)
			this->array[i] = other.array[i];
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int n)
{
	if (n >= this->n)
		throw std::exception();
	return (this->array[n]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return this->n;
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->array;
}
