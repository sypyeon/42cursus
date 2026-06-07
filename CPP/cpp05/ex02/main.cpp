#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
	Bureaucrat lowGrade("LOWGRADE", 150);
	std::cout << lowGrade << std::endl;
	Bureaucrat highGrade("HIGHGRADE", 1);
	std::cout << highGrade << std::endl;
	std::cout << std::endl;

	//Shrubbery Creation Form
	std::cout << "=== Shrubbery Creation Form ===" << std::endl;
	ShrubberyCreationForm SCF("TREE");
	std::cout << SCF.getName() << " has been created." << std::endl;
	try { highGrade.signForm(SCF); }
	catch (const std::exception& e) { std::cerr << e.what() << std::endl; }
	try { highGrade.executeForm(SCF); }
	catch (const std::exception& e) { std::cerr << e.what() << std::endl; }
	try { lowGrade.executeForm(SCF); }
	catch (const std::exception& e) { std::cerr << e.what() << std::endl; }
	std::cout << std::endl;

	//Robotomy Request Form
	std::cout << "=== Robotomy Request Form ===" << std::endl;
	RobotomyRequestForm RRF("ROBOT");
	std::cout << RRF.getName() << " has been created." << std::endl;
	try { highGrade.signForm(RRF); }
	catch (const std::exception& e) { std::cerr << e.what() << std::endl; }
	try { highGrade.executeForm(RRF); }
	catch (const std::exception& e) { std::cerr << e.what() << std::endl; }
	try { lowGrade.executeForm(RRF); }
	catch (const std::exception& e) { std::cerr << e.what() << std::endl; }
	std::cout << std::endl;


	//Presidential Pardon Form
	std::cout << "=== Presidential Pardon Form ===" << std::endl;
	PresidentialPardonForm PPF("PARDON");
	std::cout << PPF.getName() << " has been created." << std::endl;
	try { highGrade.signForm(PPF); }
	catch (const std::exception& e) { std::cerr << e.what() << std::endl; }
	try { highGrade.executeForm(PPF); }
	catch (const std::exception& e) { std::cerr << e.what() << std::endl; }
	try { lowGrade.executeForm(PPF); }
	catch (const std::exception& e) { std::cerr << e.what() << std::endl; }
	std::cout << std::endl;
}
