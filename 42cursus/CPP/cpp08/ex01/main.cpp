#include "Span.hpp"
#include <iostream>

int main()
{
	Span span(12);
	Span empty(12);

	span.fillSpan();
	std::cout << span << std::endl;
	
	std::cout << "\n=== random values ===" << std::endl;
	try
	{
		int longest = span.longestSpan();
		std::cout << "The longest span: " << longest << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		int shortest = span.shortestSpan();
		std::cout << "The shortest span: " << shortest << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n=== subject provided ===" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "shortest span:" << sp.shortestSpan() << std::endl;
	std::cout << "longest span:" << sp.longestSpan() << std::endl;

	std::cout << "\n=== exception handling ===" << std::endl;
	try
	{
		int longest = empty.longestSpan();
		std::cout << "The longest span: " << longest << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		int shortest = empty.shortestSpan();
		std::cout << "The shortest span: " << shortest << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		span.addNumber(1234);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}