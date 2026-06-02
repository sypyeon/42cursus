#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <map>

class BitcoinExchange
{
private:
	std::map<std::string, float> data;
	std::map<std::string, float> input;

	BitcoinExchange(BitcoinExchange& other);
	BitcoinExchange& operator=(BitcoinExchange& other);
public:
	BitcoinExchange();
	~BitcoinExchange();

	void processInput(std::string& file_name);
};

#endif