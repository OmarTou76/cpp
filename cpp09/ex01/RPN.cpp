#include "RPN.h"

RPN::RPN() {}
RPN::~RPN() {}
RPN::RPN(std::string &s)
{
    std::stringstream stream(s);
    std::string token;
    while (stream >> token)
    {
        if (this->isOperator(token) && this->_numbers.size() > 1)
            this->compute(token);
        else if (token.length() == 1 && std::isdigit(token[0]))
            this->_numbers.push(std::atof(token.c_str()));
        else
            throw InvalidToken();
    }
}

RPN::RPN(RPN const &cp) { *this = cp; }
RPN &RPN::operator=(RPN const &rhs)
{
    if (this != &rhs)
        this->_numbers = rhs._numbers;
    return *this;
}

void RPN::compute(std::string &op)
{
    int top = this->_numbers.top();
    this->_numbers.pop();
    int bottom = this->_numbers.top();
    this->_numbers.pop();

    if (op == "+")
        this->_numbers.push(bottom + top);
    else if (op == "-")
        this->_numbers.push(bottom - top);
    else if (op == "/")
        this->_numbers.push(bottom / top);
    else if (op == "*")
        this->_numbers.push(bottom * top);
}

bool RPN::isOperator(std::string &str) const
{
    if (str.length() != 1)
        return false;
    else if (str[0] != '-' && str[0] != '+' && str[0] != '*' && str[0] != '/')
        return false;
    return true;
}

int RPN::getResult() const
{
    if (this->_numbers.empty())
        throw InvalidToken();
    return this->_numbers.top();
}