#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <ostream>
#include <string>
#include <exception>

#include "AForm.hpp"

//Required grades: sign 72, exec 45
class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string name, int toSign, int toExec);
	RobotomyRequestForm(RobotomyRequestForm& other);
	virtual ~RobotomyRequestForm();

	RobotomyRequestForm &operator=(RobotomyRequestForm& other);
};

std::ostream &operator<<(std::ostream& os, RobotomyRequestForm& form);

#endif
