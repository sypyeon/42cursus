#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
private:
	T *array;
	unsigned int n;
public:
	Array();
	Array(unsigned int n);
	Array(Array &other);
	Array &operator=(Array &other);
	~Array();
};

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
Array<T>::Array(Array &other)
{
	this->array = new T[this->n];
}

template <typename T>
Array<T>::~Array() {}

#endif