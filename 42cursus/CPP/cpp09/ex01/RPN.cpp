#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(RPN& other) { (void)other; }
RPN& RPN::operator=(RPN& other) { (void)other; return *this;}

static bool is_operator(std::string token)
{
	if (token.empty())
		return false;
	if (token == "+" || token == "-" || token == "*" || token == "/")
		return true;
	return false;
}

static bool is_num(std::string token)
{
	if (token.empty())
		return false;
	return token.find_first_not_of("0123456789") == std::string::npos;
}

static bool operate_stack(std::stack<int>& stack, char op)
{
	int b = stack.top();
	stack.pop();
	int a = stack.top();
	stack.pop();

	if (op == '+')
		stack.push(a + b);
	else if (op == '-')
		stack.push(a - b);
	else if (op == '*')
		stack.push(a * b);
	else if (op == '/' && b != 0)
		stack.push(a / b);
	else
		return false;
	return true;
}

bool RPN::calculate(std::string input)
{
	std::stringstream ss(input);
	std::string token;
	std::stack<int> stack;

	while (ss >> token)
	{
		if (token.length() != 1)
			return false;
		if (is_num(token))
			stack.push(token.at(0) - '0');
		else if (is_operator(token))
		{
			if (stack.size() < 2)
				return false;
			else if (!operate_stack(stack, token.at(0)))
				return false;
		}
	}
	if (stack.size() != 1)
		return false;
	std::cout << stack.top() << std::endl;
	return true;
}
