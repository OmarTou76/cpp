#include "BitcoinExchange.h"
#include <cstdlib>
#include <string>
#include <algorithm>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(BitcoinExchange const &cp) { *this = cp; }
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
  if (this != &rhs)
    this->_values = rhs._values;
  return *this;
}

void BitcoinExchange::add(t_data data)
{
  this->_values.push_back(data);
}

void BitcoinExchange::displayLineConversion(t_data &d) const
{
  if (!d.isValidInput)
    throw InvalidInput();
  else if (d.quantity < 0)
    throw NotPositiveNumber();
  else if (d.quantity > 1000)
    throw TooLargeQuantity();
  else
    std::cout << d.date << " => " << d.quantity << " = " << d.nearestPrice * d.quantity << std::endl;
}

void BitcoinExchange::showConversions()
{
  this->saveNearestPrice();
  std::vector<t_data>::const_iterator it;
  for (it = this->_values.begin(); it != this->_values.end(); it++)
  {
    t_data line = *it;
    try
    {
      this->displayLineConversion(line);
    }
    catch (const BitcoinExchange::InvalidInput &e)
    {
      std::cerr << "Error: " << e.what() << line.date << std::endl;
    }
    catch (const std::exception &e)
    {
      std::cerr << "Error: " << e.what() << std::endl;
    }
  }
}

float BitcoinExchange::getNearestPrice(t_data &req) const
{
  std::fstream db("./data.csv");
  t_data target;
  memset(&target, 0, sizeof(t_data));
  if (db.is_open())
  {
    std::string line;
    while (std::getline(db, line))
    {
      int pos = 0;
      pos = line.find(",");
      std::string date = line.substr(0, pos);
      float tm = this->toTimestamp(date);
      if (tm > req.timestamp)
        break;
      if (!target.isValidInput || req.timestamp - tm < req.timestamp - target.timestamp)
      {
        target.isValidInput = true;
        target.timestamp = tm;
        target.date = date;
        target.nearestPrice = static_cast<float>(atof(line.substr(pos + 1).c_str()));
      }
    }
  }
  db.close();
  return target.nearestPrice;
}

void BitcoinExchange::saveNearestPrice()
{
  std::map<unsigned int, float> alreadyFound;
  std::vector<t_data>::iterator it;
  for (it = this->_values.begin(); it != this->_values.end(); it++)
  {
    t_data &d = *it;
    if (alreadyFound.find(d.timestamp) != alreadyFound.end())
      d.nearestPrice = alreadyFound.at(d.timestamp);
    else if (d.isValidInput && d.quantity > 0 && d.quantity <= 1000)
    {
      float np = this->getNearestPrice(d);
      d.nearestPrice = np;
      alreadyFound.insert(std::make_pair(d.timestamp, np));
    }
  }
}

unsigned int BitcoinExchange::toTimestamp(std::string date)
{
  struct tm timeinfo;
  memset(&timeinfo, 0, sizeof(tm));
  if (strptime(date.c_str(), "%Y-%m-%d", &timeinfo) != NULL)
  {
    time_t ts = mktime(&timeinfo);
    return ts;
  }
  return 0;
}