#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

//constructor destructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", "unknown", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", target, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) { *this = other; }

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	(void)other;
	return *this;
}

// Form execution
bool RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try
	{
		AForm::execute(executor);

		int rand = std::time(NULL);
		std::cout << "**drilling noises**" << std::endl;
		if ((rand % 2) == 0)
			std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
		else if ((rand % 2) == 1)
			std::cout << this->getTarget() << " robotomy failed." << std::endl;
	}
	catch (std::exception& e) { std::cerr << e.what() << std::endl; return false; }
	return true;
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& form)
{
	os << form.getName();
	return os;
}
