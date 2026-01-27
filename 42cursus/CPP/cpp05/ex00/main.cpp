#include "Bureaucrat.hpp"

int main()
{
	try
	{
		std::cout << "=== testing Bureaucrat construction and functions ===" << std::endl;
		std::cout << std::endl << "--- valid Bureaucrat creation ---" << std::endl;
		Bureaucrat lowB("Low Grade Bureaucrat", 150);
		std::cout << lowB << std::endl;
		Bureaucrat highB("High Grade Bureaucrat", 1);
		std::cout << highB << std::endl;

		std::cout << std::endl << "--- invalid Bureaucrat creation ---" << std::endl;
		try { Bureaucrat invalid("invalid Grade Bureaucrat", 0); }
		catch (std::exception& e) { std::cerr << e.what() << std::endl; }
		try { Bureaucrat invalid("invalid Grade Bureaucrat", 151); }
		catch (std::exception& e) { std::cerr << e.what() << std::endl; }

		std::cout << std::endl << "--- invalid Bureaucrat grade decrement and increment ---" << std::endl;
		try { lowB.decrementGrade(); }
		catch(const std::exception& e) { std::cerr << e.what() << std::endl; }
		try { highB.incrementGrade(); }
		catch(const std::exception& e) { std::cerr << e.what() << std::endl; }

		std::cout << std::endl << "--- valid Bureaucrat grade decrement and increment ---" << std::endl;
		try { lowB.incrementGrade(); }
		catch(const std::exception& e) { std::cerr << e.what() << std::endl; }
		try { highB.decrementGrade(); }
		catch(const std::exception& e) { std::cerr << e.what() << std::endl; }
		std::cout << lowB << std::endl << highB << std::endl;

		std::cout << std::endl << "=== checking what happens if exception is thrown while TRY ===" << std::endl;
		Bureaucrat invalid("invalid", -123);
		std::cerr << "Exception thrown due to invalid construction.\n This message should NOT display." << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}