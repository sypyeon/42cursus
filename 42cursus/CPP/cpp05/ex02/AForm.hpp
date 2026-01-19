#ifndef AFORM_HPP
#define AFORM_HPP

#include <ostream>
#include <string>
#include <exception>

class Bureaucrat;
class AForm
{
private:
	const std::string name;
	bool isSigned;
	const std::string target;
	const int toSign;
	const int toExec;
public:
	AForm();
	AForm(std::string name, std::string target, int toSign, int toExec);
	AForm(AForm& other);
	virtual ~AForm();

	AForm &operator=(AForm& other);

	const std::string &getName() const;
	const std::string &getTarget() const;
	bool getIsSigned() const;
	const int &getToSign() const;
	const int &getToExec() const;

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

std::ostream &operator<<(std::ostream& os, AForm& form);

#endif
