#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {};

template <typename T>
MutantStack<T>::MutantStack(MutantStack &other) : std::stack<T>(other) {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack &other)
{
	if (this != other)
	{
		std::stack<T>::operator=(other);
	}
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() { return this->c.begin(); }

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() { return this->c.end(); }

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const { return this->c.begin(); }

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const { return this->c.end(); }

template <typename T>
T MutantStack<T>::top() { return std::stack<T>::top(); }

template <typename T>
bool MutantStack<T>::empty() { return std::stack<T>::empty(); }

template <typename T>
std::size_t MutantStack<T>::size() { return std::stack<T>::size(); }

template <typename T>
void MutantStack<T>::push(const T &value) { return std::stack<T>::push(value); }

template <typename T>
void MutantStack<T>::pop() { return std::stack<T>::pop(); }
