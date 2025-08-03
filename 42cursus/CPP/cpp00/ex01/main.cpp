#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>

int	main()
{
	PhoneBook phonebook;
	std::string input;

	std::cout << "ADD: save a new contact" << std::endl;
	std::cout << "SEARCH: display a specific contact" << std::endl;
	std::cout << "EXIT: quit program. contacts are lost forever!" << std::endl;
	while (true)
	{
		std::cout << "> ";
		if (!(std::getline(std::cin, input)))
			break;
		else if (input == "ADD" || input == "add")
			phonebook.add_contact();
		else if (input == "SEARCH" || input == "search")
			phonebook.search_phonebook();
		else if (input == "EXIT" || input == "exit")
			break;
	}
	return 0;
}