#ifndef RPN_HPP
#define RPN_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>

class RPN
{
private:
	RPN();
	~RPN();
	RPN(RPN& other);
	RPN& operator=(RPN& other);
public:
	static bool calculate(std::string input);
};

#endif