#ifndef CONVERTERUTILS_HPP
#define CONVERTERUTILS_HPP	

#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <cstring>
#include <math.h>

typedef std::numeric_limits<char>	c_lim;
typedef std::numeric_limits<int>	i_lim;
typedef std::numeric_limits<float>	f_lim;
typedef std::numeric_limits<double>	d_lim;

bool isChar(std::string input);
bool isInt(std::string input);
bool isFloat(std::string input);
bool isDouble(std::string input);
bool isNum(std::string input);
bool isPseudo(double dvalue);
bool isInRange(long min, long max, long lvalue);
bool isInRange(double min, double max, double dvalue);

#endif