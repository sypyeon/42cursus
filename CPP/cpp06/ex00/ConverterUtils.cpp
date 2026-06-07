#include "ConverterUtils.hpp"

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

bool isNum(std::string input) { return (isInt(input) || isFloat(input) || isDouble(input)); }

bool isPseudo(double dvalue) { return (std::isnan(dvalue) || std::isinf(dvalue)); }

bool isInRange(long min, long max, long lvalue) { return (min <= lvalue && lvalue <= max); }

bool isInRange(double min, double max, double dvalue) { return (min <= dvalue && dvalue <= max); }
