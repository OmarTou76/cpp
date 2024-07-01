#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <sstream>

class RPN
{
private:
    std::stack<int> _numbers;
    RPN();
    bool isOperator(std::string &str) const;
    void compute(std::string &);

public:
    RPN(std::string &);
    RPN(RPN const &);
    RPN &operator=(RPN const &);
    ~RPN();

    int getResult() const;

    class InvalidToken : public std::exception
    {
    public:
        const char *what() const throw() { return "Invalid input !"; }
    };
};