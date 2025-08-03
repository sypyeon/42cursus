#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
	int		noc;
	int		curr;
	Contact contact[8];
	public:
	PhoneBook() : noc(0), curr(0) {}
	void add_contact();
	void search_phonebook();
};

#endif