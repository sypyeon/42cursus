#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <ostream>
#include <string>
#include <exception>

#include "AForm.hpp"

//Required grades: sign 145, exec 137
class Bureaucrat;
class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm& other);
	virtual ~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(ShrubberyCreationForm& other);

	bool execute();
};

std::ostream &operator<<(std::ostream& os, ShrubberyCreationForm& form);

#endif
