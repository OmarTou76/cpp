#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

typedef struct Data {
  std::string date;
  unsigned int timestamp;
  float quantity;
  float nearestPrice;
  bool isValidInput;
} t_data;

class BitcoinExchange {
private:
  std::vector<t_data> _values;
  float getNearestPrice(t_data &) const;
  void saveNearestPrice();
  void displayLineConversion(t_data &d) const;

public:
  BitcoinExchange();
  BitcoinExchange(BitcoinExchange const &);
  BitcoinExchange &operator=(BitcoinExchange const &);

  void add(t_data data);
  void showConversions();

  static unsigned int toTimestamp(std::string date);

  class BtcDidNotExist : public std::exception {
  public:
    const char *what() const throw() {
      return "at that time, btc did not exist => ";
    }
  };
  class InvalidInput : public std::exception {
  public:
    const char *what() const throw() { return "bad input => "; }
  };

  class NotPositiveNumber : public std::exception {
  public:
    const char *what() const throw() { return "not a positive number."; }
  };

  class TooLargeQuantity : public std::exception {
  public:
    const char *what() const throw() { return "too large a number."; }
  };
};
