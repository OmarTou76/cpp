#pragma once
#include <iostream>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &copy);
    ScalarConverter &operator=(const ScalarConverter &rhs);

public:
    ~ScalarConverter();
    static void convert(const std::string &);
};
