#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", "unknown", 25, 5) {}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", target, 25, 5) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) { *this = other; }
PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	(void)other;
	return *this;
}

bool PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try
	{
		AForm::execute(executor);

		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	catch (std::exception& e) { std::cerr << e.what() << std::endl; return false; }
	return true;
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& form)
{
	os << form.getTarget();
	return os;
}
