#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat bob("Bob", 150);
		std::cout << bob << std::endl;
		try
		{
			bob.decrementGrade();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}