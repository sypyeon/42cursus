#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
public:
	MutantStack();
	MutantStack(MutantStack &other);
	MutantStack &operator=(MutantStack &other);
	~MutantStack();

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;

	T top();
	bool empty();
	std::size_t size();
	void push(const T &value);
	void pop();
};

#include "MutantStack.tpp"

#endif
