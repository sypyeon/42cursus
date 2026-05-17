#include "Span.hpp"

void Span::addNumber(int number)
{
	if (this->set.size() == this->max_size)
		throw ErrorMaxSizeReached();
	this->set.insert(number);
}

int Span::shortestSpan()
{
	if (this->set.size() < 2)
		throw ErrorNoSpanFound();

	std::set<int>::iterator it = this->set.begin();
	std::set<int>::iterator prev = it;
	++it;

	int shortest = *it - *prev;
	++it;
	++prev;

	for (; it != this->set.end(); ++it)
	{
		int diff = *it - *prev;
		if (diff < shortest)
			shortest = diff;
		prev = it;
	}
	return std::abs(shortest);
}

int Span::longestSpan()
{
	if (this->set.size() < 2)
		throw ErrorNoSpanFound();
	
	return std::abs(*(this->set.begin()) - *(this->set.rbegin()));
}

void Span::fillSpan()
{
	std::srand(std::time(NULL));
	int rand_val;

	while (this->set.size() != this->max_size)
	{
		rand_val = std::rand() % (this->max_size * 1000);
		if (this->set.find(rand_val) == this->set.end())
			this->addNumber(rand_val);
	}
}

const std::set<int> &Span::getSet() const
{
	return (this->set);
}

std::ostream &operator<<(std::ostream &os, Span &span)
{
	const std::set<int> set = span.getSet();
	os << "Set values: ";
	for (std::set<int>::iterator it = set.begin(); it != set.end(); ++it)
		os << *it << " ";
	return os;
}
