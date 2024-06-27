#pragma once
#include <iostream>
#include <map>

typedef struct Data {
  std::string date;
  std::string quantity;
} t_data;

class BitcoinExchange {
private:
  std::map<std::string, float> _imputValues;
  float convertQuantityToFloat(std::string &);

public:
  BitcoinExchange();
  BitcoinExchange(BitcoinExchange const &);
  BitcoinExchange &operator=(BitcoinExchange const &);

  void appendValue(t_data data);
};
