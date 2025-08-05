#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <sstream>
# include <iostream>

class Zombie{
private:
	std::string name;
public:
	void announce();
	void setName(std::string name);
	std::string get_name() const;
};

Zombie* zombieHorde(int N, std::string name);

#endif
