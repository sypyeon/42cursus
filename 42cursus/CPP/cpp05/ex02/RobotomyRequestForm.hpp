#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <ostream>
#include <string>
#include <exception>

#include "AForm.hpp"

class Bureaucrat;
//Required grades: sign 72, exec 45
class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(const RobotomyRequestForm& other);

	bool execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& os, RobotomyRequestForm& form);

#endif
