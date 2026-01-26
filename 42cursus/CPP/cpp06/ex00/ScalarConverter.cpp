#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter& other) { *this = other; }
ScalarConverter& ScalarConverter::operator=(ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

bool isChar(std::string input)
{
	return (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]));
}

bool isInt(std::string input)
{
	char* end = NULL;
	long num = static_cast<long>(std::strtod(input.c_str(), &end));
	if (num > i_lim::max() || num < i_lim::min() || *end != '\0')
		return false;
	return true;
}

bool isFloat(std::string input)
{
	char* end = NULL;
	double num = std::strtod(input.c_str(), &end);
	if (num > f_lim::max() || num < f_lim::min() || strlen(end) > 1 || *end != 'f')
		return false;
	return true;
}

bool isDouble(std::string input)
{
	char* end = NULL;
	double num = std::strtod(input.c_str(), &end);
	if (num > d_lim::max() || num < d_lim::min() || *end != '\0')
		return false;
	return true;
}

bool isNum(std::string input)
{
	return (isInt(input) || isFloat(input) || isDouble(input));
}

bool isPseudo(double dvalue)
{
	return (std::isnan(dvalue) || std::isinf(dvalue));
}

bool isInRange(long min, long max, long lvalue)
{
	return (min <= lvalue && lvalue <= max);
}

bool isInRange(double min, double max, double dvalue)
{
	return (min <= dvalue && dvalue <= max);
}

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

	// if (isChar(input))
	// 	std::cout << input << ": is char" << std::endl;
	// else
	// 	std::cout << input << ": is NOT char" << std::endl;
	// if (isInt(input))
	// 	std::cout << input << ": is int" << std::endl;
	// else
	// 	std::cout << input << ": is NOT int" << std::endl;
	// if (isFloat(input))
	// 	std::cout << input << ": is float" << std::endl;
	// else
	// 	std::cout << input << ": is NOT float" << std::endl;
	// if (isDouble(input))
	// 	std::cout << input << ": is double" << std::endl;
	// else
	// 	std::cout << input << ": is NOT double" << std::endl;
}
