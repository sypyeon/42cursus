#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : name("unknown"), grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat &other): name(other.name), grade(other.grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat &other)
{
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return *this;
}

std::string  Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

// promotion and relagation
void Bureaucrat::incrementGrade()
{
	if (grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

void Bureaucrat::signForm(AForm& form)
{
	form.beSigned(*this);
	if (form.getIsSigned())
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	else
		std::cout << this->getName() << " couldn't sign " << form.getName() << std::endl;
}

void Bureaucrat::executeForm(AForm const & form) const
{
	if (form.execute(*this))
		std::cout << this->name << " executed " << form.getName() << std::endl;
	else
		std::cerr << this->name << " FAILED to execute " << form.getName() << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	std::cout << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}
