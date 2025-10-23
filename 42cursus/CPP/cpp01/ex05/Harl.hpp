#ifndef HARL_HPP
#define HARL_HPP
#include <string>
#include <iostream>

#define HARL_HASH 53

class Harl {
private:
	int  complainIndex[HARL_HASH];
	void (Harl::*functions[HARL_HASH])();
	void doNothing();
    void debug();
    void info();
    void warning();
    void error();
public:
    Harl();	
    ~Harl();
    void complain(std::string level);
};

int	hashcode(std::string str);

#endif