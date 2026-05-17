#ifndef SPAN_HPP
#define SPAN_HPP

#include <set>
#include <exception>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <ostream>

class ErrorMaxSizeReached : public std::exception
{
	virtual const char* what() const throw()
	{
		return "max size reached";
	}
};

class ErrorNoSpanFound : public std::exception
{
	virtual const char* what() const throw()
	{
		return "no span can be found";
	}
};

class Span
{
private:
	std::set<int> set;
	unsigned int max_size;
public:
	Span(unsigned int max_size) : max_size(max_size) {}
	~Span() {}

	void addNumber(int number);
	int shortestSpan();
	int longestSpan();

	void fillSpan();

	const std::set<int> &getSet() const;
};

std::ostream &operator<<(std::ostream &os, Span &span);

#endif
