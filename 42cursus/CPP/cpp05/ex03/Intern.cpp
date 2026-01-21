#include "Intern.hpp"

Intern::Intern()
{
	this->formats.push_back("robotomy request");
	this->formats.push_back("presidential request");
	this->formats.push_back("shrubbery creation");
}

Intern::Intern(Intern &other) { *this = other; }

Intern::~Intern() {}

Intern& Intern::operator=(Intern &other)
{
	(void)other;
	return *this;
}

AForm* Intern::makeForm(std::string name, std::string target) const
{
	for (int i = 0; i < 3; i++)
	{
		if (name == this->formats[i])
			
	}
}
