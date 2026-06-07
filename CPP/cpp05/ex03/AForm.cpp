#include "AForm.hpp"
#include "Bureaucrat.hpp"

//constructor and destructor
AForm::AForm(): name("unknown"), isSigned(false), toSign(150), toExec(150) {}

AForm::AForm(std::string name, std::string target, int toSign, int toExec): name(name), target(target), isSigned(false), toSign(toSign), toExec(toExec)
{
	if (toSign < 1 || toExec < 1)
		throw AForm::GradeTooHighException();
	if (toSign > 150 || toExec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm& other): name(other.name), isSigned(other.isSigned), toSign(other.toSign), toExec(other.toExec){}

AForm &AForm::operator=(AForm& other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	return *this;
}

AForm::~AForm() {}

//getter
const std::string &AForm::getName() const { return this->name; }

const std::string &AForm::getTarget() const { return this->target; }

bool AForm::getIsSigned() const { return this->isSigned; }

const int &AForm::getToSign() const { return this->toSign; }

const int &AForm::getToExec() const { return this->toExec; }

//functions
void AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->toSign)
		throw AForm::GradeTooLowException();
	else
		this->isSigned = true;
}

bool AForm::execute(Bureaucrat const & executor) const
{
	if (!this->isSigned)
		throw AForm::FormNotSigned();
	else if (this->toExec < executor.getGrade())
		throw AForm::GradeTooLowException();
	return true;
}

//exception
const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char* AForm::FormNotSigned::what() const throw()
{
	return "Form not signed";
}


std::ostream& operator<<(std::ostream& os, AForm& form)
{
	os <<"Name: " << form.getName() 
		<< ", is signed: " << form.getIsSigned()
		<< ", required grade to sign: " << form.getToSign()
		<< ", required grade to execute: " << form.getToExec();
	return os;
}
