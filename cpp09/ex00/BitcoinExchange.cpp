#include "BitcoinExchange.h"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &cp) { *this = cp; }
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) 
{
  if (this != &rhs)
    this->_imputValues = rhs._imputValues;
  return *this;
}
