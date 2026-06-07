#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	this->formats.push_back("robotomy request");
	this->formats.push_back("presidential request");
	this->formats.push_back("shrubbery creation");
	this->formatCreateFunction[0] = &Intern::robotomyForm;
	this->formatCreateFunction[1] = &Intern::presidentialForm;
	this->formatCreateFunction[2] = &Intern::shrubberyForm;
}

AForm* Intern::robotomyForm(std::string target)
{
	return new RobotomyRequestForm(target);
}
AForm* Intern::presidentialForm(std::string target)
{
	return new PresidentialPardonForm(target);
}
AForm* Intern::shrubberyForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

Intern::Intern(Intern &other) { *this = other; }

Intern::~Intern() {}

Intern& Intern::operator=(Intern &other)
{
	(void)other;
	return *this;
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	for (int i = 0; i < 3; i++)
	{
		if (name == this->formats[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return (this->*formatCreateFunction[i])(target);
		}
	}
	std::cerr << "FAIL: Intern failed to create " << name << std::endl;
	return NULL;
}
