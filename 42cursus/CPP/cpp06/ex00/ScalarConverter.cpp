#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter& other) { *this = other; }
ScalarConverter& ScalarConverter::operator=(ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

#define INT_MAX 2147483647
#define INT_MIN -2147483648

bool isChar(std::string input)
{
	if (input.empty())
		return false;
	if (input.length() > 1 || std::strtol(input.c_str(), NULL, 10) > 255)
		return false;
	return true;
}

bool isInt(std::string input)
{
	char* end = NULL;
	long num = std::strtol(input.c_str(), &end, 10);
	std::cout << end << std::endl;
	if (num > INT_MAX || num < INT_MIN || *end != '\0')
		return false;
	return true;
}

bool isFloat(std::string input)
{
	char* end = NULL;
	long num = std::strtof(input.c_str(), &end);
	if (num > INT_MAX || num < INT_MIN || strlen(end) > 1 || *end != 'f')
		return false;
	return true;
}

bool isDouble(std::string input)
{
	char* end = NULL;
	long num = std::strtod(input.c_str(), &end);
	if (num > INT_MAX || num < INT_MIN || *end != '\0')
		return false;
	return true;
}

// void printChar(std::string input)
// {
// }

// void printInt(std::string input)
// {
// }

// void printFloat(std::string input)
// {
// }

// void printDouble(std::string input)
// {
// }

void ScalarConverter::convert(std::string input)
{
	// printChar(input);
	// printInt(input);
	// printFloat(input);
	// printDouble(input);
	if (isChar(input))
		std::cout << input << ": is char" << std::endl;
	else
		std::cout << input << ": is NOT char" << std::endl;
	if (isInt(input))
		std::cout << input << ": is int" << std::endl;
	else
		std::cout << input << ": is NOT int" << std::endl;
	if (isFloat(input))
		std::cout << input << ": is float" << std::endl;
	else
		std::cout << input << ": is NOT float" << std::endl;
	if (isDouble(input))
		std::cout << input << ": is double" << std::endl;
	else
		std::cout << input << ": is NOT double" << std::endl;
}
