#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP	

#include <string>
#include <iostream>
#include <sstream>
#include <math.h>
#include <cstdlib>
#include <cstring>

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