#include "RPN.hpp"

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./RPN \"postfix expression\"" << std::endl;
		return 1;
	}
	if (!RPN::calculate(av[1]))
		std::cerr << "Error" << std::endl;
	return 0;
}