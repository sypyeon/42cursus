#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP	

#include <string>
#include <iostream>
#include <sstream>
#include <math.h>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <iomanip>

typedef std::numeric_limits<char>	c_lim;
typedef std::numeric_limits<int>	i_lim;
typedef std::numeric_limits<float>	f_lim;
typedef std::numeric_limits<double>	d_lim;

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