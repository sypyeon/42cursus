#include "Form.hpp"

//constructor
Form::Form(): name("unknown"), isSigned(false), toSign(150), toExec(150) {}

Form::Form(std::string name, bool isSigned, int toSign, int toExec): name(name), isSigned(isSigned), toSign(toSign), toExec(toExec)
{
}

Form::Form(Form& other): name(other.name), isSigned(other.isSigned), toSign(other.toSign), toExec(other.toExec)
{}

Form &Form::operator=(Form& other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	return *this;
}

Form::~Form() {}

//getter
std::string Form::getName() const
{
	return this->name;
}

bool Form::getIsSigned() const
{
	return this->isSigned;
}

int Form::getToSign() const
{
	return this->toSign;
}

int Form::getToExec() const
{
	return this->toExec;
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() < this->toSign)
	std::cout << bureaucrat.getName() << "signed" << this->name << std::endl;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, Form& form)
{
	os <<"Name: " << form.getName() 
		<< ", is signed: " << form.getIsSigned()
		<< ", required grade to sign: " << form.getToSign()
		<< ", required grade to execute: " << form.getToExec();
	return os;
}
