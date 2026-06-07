#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>

int	main()
{
	PhoneBook phonebook;
	std::string input;

	while (true)
	{
		std::cout << "> ";
		std::getline(std::cin, input);
		if (!std::cin)
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