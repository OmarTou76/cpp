#pragma once
#include "cstdlib"
#include <iostream>

class ScalarConverter {
private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter &copy);
  ScalarConverter &operator=(const ScalarConverter &rhs);
  bool isString(std::string &str);

public:
  ~ScalarConverter();
  static void convert(const std::string &);
};
