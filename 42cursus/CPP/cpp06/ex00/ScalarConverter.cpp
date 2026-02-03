#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter& other) { *this = other; }
ScalarConverter& ScalarConverter::operator=(ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

void printChar(long lvalue, double dvalue)
{
	unsigned char c = static_cast<unsigned char>(lvalue);
	std::cout << "char: ";
	if (isPseudo(dvalue) || !isInRange(c_lim::min(), c_lim::max(), lvalue))
		std::cout << "impossible" << std::endl;
	else if (std::isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void printInt(long lvalue, double dvalue)
{
	int num = static_cast<int>(lvalue);
	std::cout << "int: ";
	if (isPseudo(dvalue))
		std::cout << "impossible" << std::endl;
	else if (!isInRange(i_lim::min(), i_lim::max(), lvalue))
		std::cout << "out of range" << std::endl;
	else
		std::cout << num << std::endl;
}

void printFloat(double dvalue)
{
	std::cout << std::fixed << std::setprecision(1);
	float num = static_cast<float>(dvalue);
	std::cout << "float: ";
	if (isPseudo(dvalue))
		std::cout << dvalue << "f" << std::endl;
	else if (!isInRange(-f_lim::max(), f_lim::max(), dvalue))
		std::cout << "out of range" << std::endl;
	else
		std::cout << num << "f" << std::endl;
}

void printDouble(double dvalue)
{
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "double: ";
	if (isPseudo(dvalue))
		std::cout << dvalue << std::endl;
	else if (!isInRange(-d_lim::max(), d_lim::max(), dvalue))
		std::cout << "out of range" << std::endl;
	else
		std::cout << dvalue << std::endl;
}

void convertInputValue(std::string& input, long& lvalue, double& dvalue)
{
	if (isChar(input))
	{
		lvalue = input[0];
		dvalue = input[0];
	}
	else if (isFloat(input) || isDouble(input))
	{
		lvalue = std::strtod(input.c_str(), NULL);
		dvalue = std::strtod(input.c_str(), NULL);
	}
	else
	{
		lvalue = std::strtol(input.c_str(), NULL, 10);
		dvalue = std::strtod(input.c_str(), NULL);
	}
}

void printInvalidInput()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

bool invalidInput(std::string input, double dvalue)
{
	if (isPseudo(dvalue) || isChar(input) || isNum(input))
		return false;
	std::cout << "invalid input" << std::endl;
	printInvalidInput();
	return true;
}

void ScalarConverter::convert(std::string input)
{
	long lvalue;
	double dvalue;

	convertInputValue(input, lvalue, dvalue);
	if (invalidInput(input, dvalue))
		return ;
	std::cout << "Long Value: " << lvalue << std::endl;
	std::cout << "Double Value: " << dvalue << std::endl << std::endl;
	printChar(lvalue, dvalue);
	printInt(lvalue, dvalue);
	printFloat(dvalue);
	printDouble(dvalue);
}
