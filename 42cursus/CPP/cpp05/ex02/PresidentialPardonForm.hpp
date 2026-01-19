#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <ostream>
#include <string>
#include <exception>

#include "AForm.hpp"

//Required grades: sign 25, exec 5
class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string name, int toSign, int toExec);
	PresidentialPardonForm(PresidentialPardonForm& other);
	virtual ~PresidentialPardonForm();

	PresidentialPardonForm &operator=(PresidentialPardonForm& other);
};

std::ostream &operator<<(std::ostream& os, PresidentialPardonForm& form);

#endif
