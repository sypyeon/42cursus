#include "Harl.hpp"
#include <iostream>

Harl::Harl() {
	for (int i = 0; i < HARL_HASH; i++)
		complainIndex[i] = 0;
	this->complainIndex[hashcode("DEBUG")] = 1;
	this->complainIndex[hashcode("INFO")] = 2;
	this->complainIndex[hashcode("WARNING")] = 3;
	this->complainIndex[hashcode("ERROR")] = 4;
	this->functions[0] = &Harl::doNothing;
	this->functions[1] = &Harl::debug;
	this->functions[2] = &Harl::info;
	this->functions[3] = &Harl::warning;
	this->functions[4] = &Harl::error;
}

Harl::~Harl() {}

void Harl::complain(std::string level) {
	int index = this->complainIndex[hashcode(level)];
	(this->*functions[index])();
}

void Harl::doNothing() {}

void Harl::debug() {
    std::cout << "[DEBUG] I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void Harl::info() {
    std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You don’t put enough! If you did, I would not have to ask for it!" << std::endl;
}

void Harl::warning() {
    std::cout << "[WARNING] I think I deserve to have some extra bacon for free. I’ve been coming here for years and there’s never enough bacon!" << std::endl;
}

void Harl::error() {
    std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now." << std::endl;
}
