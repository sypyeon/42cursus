#ifndef FORM_HPP
#define FORM_HPP

#include <ostream>
#include <string>
#include <exception>

class Bureaucrat;
class Form
{
private:
	const std::string name;
	bool isSigned;
	const int toSign;
	const int toExec;
public:
	Form();
	Form(std::string name, int toSign, int toExec);
	Form(Form& other);
	~Form();

	Form &operator=(Form& other);

	std::string getName() const;
	bool getIsSigned() const;
	int getToSign() const;
	int getToExec() const;

	void beSigned(Bureaucrat& bureaucrat);

	class GradeTooHighException: public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream& os, Form& form);

#endif
