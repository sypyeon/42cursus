#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	void clear_contact();

public:
	void input_contact();
	void display_search(int i) const;
	void display_contact() const;
};

#endif