#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <ostream>
#include <string>
#include <exception>

#include "AForm.hpp"

class Bureaucrat;
//Required grades: sign 25, exec 5
class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string name, int toSign, int toExec);
	PresidentialPardonForm(PresidentialPardonForm& other);
	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(PresidentialPardonForm& other);

	bool execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<(std::ostream& os, PresidentialPardonForm& form);

#endif
