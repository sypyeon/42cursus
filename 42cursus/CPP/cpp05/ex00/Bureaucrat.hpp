#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
private:
	const std::string name;
	int grade;
public:
	Bureaucrat();
	Bureaucrat(Bureaucrat &other);
	~Bureaucrat();
	Bureaucrat operator=(Bureaucrat &other);

	const std::string getName();
	int getGrade();

	void incrementGrade()
	void decrementGrade()

	GradeTooHighException();
	GradeTooLowException();
};

#endif
