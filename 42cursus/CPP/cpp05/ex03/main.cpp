#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
	Bureaucrat lowGrade("LowGrade", 150);
	std::cout << lowGrade << std::endl;
	Bureaucrat highGrade("HighGrade", 1);
	std::cout << highGrade << std::endl;

	std::cout << "Trying to construct Bureaucrat with too low grade." << std::endl;
	try {Bureaucrat tooLow("tooLow", 151);}
	catch (std::exception &e) {std::cout << e.what() << std::endl;}
	std::cout << std::endl;

	//invalid decrement
	std::cout << "Trying to decrease grade of " << lowGrade << std::endl;
	try	{lowGrade.decrementGrade();}
	catch(const std::exception& e) {std::cerr << e.what() << '\n';}
	std::cout << std::endl;

	//valid increment
	std::cout << "Trying to increase grade of " << lowGrade << std::endl;
	try	{lowGrade.incrementGrade();}
	catch(const std::exception& e) {std::cerr << e.what() << '\n';}
	std::cout << std::endl;

	//invalid increment
	std::cout << "Trying to increase grade of " << highGrade << std::endl;
	try	{highGrade.incrementGrade();}
	catch(const std::exception& e) {std::cerr << e.what() << '\n';}
	std::cout << std::endl;

	//valid decrement
	std::cout << "Trying to decrease grade of " << highGrade << std::endl;
	try	{highGrade.decrementGrade();}
	catch(const std::exception& e) {std::cerr << e.what() << '\n';}
	std::cout << std::endl;


	//Shrubbery Creation Form
	std::cout << "===Shrubbery Creation Form===" << std::endl;
	ShrubberyCreationForm SCF("Tree");
	try { highGrade.signForm(SCF); }
	catch (const std::exception& e) { std::cerr << e.what() << std::endl; }
	try { highGrade.executeForm(SCF); }
	catch (const std::exception& e) { std::cerr << e.what() << std::endl; }
	try { lowGrade.executeForm(SCF); }
	catch (const std::exception& e) { std::cerr << e.what() << std::endl; }
	std::cout << std::endl;

	//Robotomy Request Form
	std::cout << "===Robotomy Request Form===" << std::endl;
	RobotomyRequestForm RRF("Robot");
	try { highGrade.signForm(RRF); }
	catch (const std::exception& e) { std::cerr << e.what() << std::endl; }
	try { highGrade.executeForm(RRF); }
	catch (const std::exception& e) { std::cerr << e.what() << std::endl; }
	try { lowGrade.executeForm(RRF); }
	catch (const std::exception& e) { std::cerr << e.what() << std::endl; }
	std::cout << std::endl;


	//Presidential Pardon Form
	std::cout << "===Presidential Pardon Form===" << std::endl;
	PresidentialPardonForm PPF("Pardon");
	try { highGrade.signForm(PPF); }
	catch (const std::exception& e) { std::cerr << e.what() << std::endl; }
	try { highGrade.executeForm(PPF); }
	catch (const std::exception& e) { std::cerr << e.what() << std::endl; }
	try { lowGrade.executeForm(PPF); }
	catch (const std::exception& e) { std::cerr << e.what() << std::endl; }
	std::cout << std::endl;
}
