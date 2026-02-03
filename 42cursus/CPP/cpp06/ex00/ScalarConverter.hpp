#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP	

#include <iomanip>
#include "ConverterUtils.hpp"

class ScalarConverter
{
private:
	ScalarConverter();
	ScalarConverter(ScalarConverter& other);
	ScalarConverter& operator=(ScalarConverter& other);
	~ScalarConverter();
public:
	static void convert(std::string str);
};

#endif