#include <string>
#include <iostream>

class Contact
{
	private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string phone_number;
	std::string darkest_secret;
	public:
	void display_contact();
    void input_contact();
};

class PhoneBook
{
	private:
	int		noc;
	Contact contact[8];
	public:
	PhoneBook() : noc(0) {}
	void add_contact();
	void search_phonebook();
};

void Contact::input_contact()
{
    std::cout << "First Name: ";
    std::cin >> first_name;
    std::cout << "Last Name: ";
    std::cin >> last_name;
    std::cout << "Nickname: ";
    std::cin >> nickname;
    std::cout << "Phone Number: ";
    std::cin >> phone_number;
    std::cout << "Darkest Secret: ";
    std::cin >> darkest_secret;
}

void PhoneBook::add_contact()
{
    contact[noc].input_contact();
    noc++;
    if (noc >= 8)
        noc = 0;
}

void	display_(std::string str)
{
	int i = 0;

	if (str.length() > 10)
	{
		str.erase(str.begin() + 9, str.end());
		str.push_back('.');
	}
	while (i < str.length())
	{
		std::cout << str[i];
		i++;
	}
	while (i < 10)
	{
		std::cout << ' ';
		i++;
	}
}

void	Contact::display_contact()
{
	display_(first_name);
	std::cout << '|';
	display_(last_name);
	std::cout << '|';
	display_(nickname);
	std::cout << '|';
	display_(phone_number);
	std::cout << '\n';
}

void	PhoneBook::search_phonebook()
{
	int i = 0;

	while (noc > i)
	{
		contact[i].display_contact();
		i++;
	}
}

int	main()
{
	PhoneBook phonebook;
	std::string input;

	while(true)
	{
		std::cin >> input;
		if (input == "ADD" || input == "add")
			phonebook.add_contact();
		if (input == "SEARCH" || input == "search")
			phonebook.search_phonebook();
		if (input == "EXIT" || input == "exit")
			break;
	}
	return 0;
}
