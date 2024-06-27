#include "BitcoinExchange.h"
#include <cstdlib>
#include <string>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &cp) { *this = cp; }
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {
  if (this != &rhs)
    this->_imputValues = rhs._imputValues;
  return *this;
}

float BitcoinExchange::convertQuantityToFloat(std::string &qt) {
  float n = std::atof(qt.c_str());
  return n;
}

void BitcoinExchange::appendValue(t_data data) {
  float toFloat = this->convertQuantityToFloat(data.quantity);
  this->_imputValues.insert({data.date, toFloat});
}
