#pragma once
#include <iostream>
#include <map>

typedef struct Data {
  std::string date;
  float quantity;
} t_data;

class BitcoinExchange {
private:
	std::map<std::string, float> _imputValues;
public:
	BitcoinExchange();
	BitcoinExchange(BitcoinExchange const &);
	BitcoinExchange &operator=(BitcoinExchange const &);

	void appendValue(std::string date, float quantity);
};  
