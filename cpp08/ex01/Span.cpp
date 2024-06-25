#include "Span.h"
#include <algorithm>
#include <cstdlib>
#include <stdexcept>

Span::Span() : _N(0) {}
Span::Span(unsigned int size) : _N(size) {}
Span::Span(Span const &c) { *this = c; }
Span &Span::operator=(Span const &rhs)
{
  if (this != &rhs)
  {
    this->_N = rhs._N;
    this->_content = rhs._content;
  }
  return *this;
}
Span::~Span() {}

void Span::addRange(std::list<int>::const_iterator start, std::list<int>::const_iterator end)
{
  int r_size = *end;
  if (this->_content.size() + r_size >= this->_N)
    throw ImpossibleToAddThisRange();
  for (; start != end; start++)
    this->_content.push_back(*start);
}

void Span::addNumber(int number)
{
  if (this->_content.size() >= _N)
    throw ImpossibleToAddElement();
  this->_content.push_back(number);
}

unsigned int Span::longestSpan() const
{
  if (this->_N < 2)
    throw SpanNotBigEnough();
  return *std::max_element(this->_content.begin(), this->_content.end()) -
         *std::min_element(this->_content.begin(), this->_content.end());
}

unsigned int Span::shortestSpan() const
{
  if (this->_N < 2)
    throw SpanNotBigEnough();
  int shortest = INT_MAX;
  std::list<int>::const_iterator it;
  for (it = this->_content.begin(); it != this->_content.end(); it++)
  {
    std::list<int>::const_iterator next = it;
    for (; next != this->_content.end(); next++)
    {
      if (next != it && abs(*it - *next) < shortest)
        shortest = abs(*it - *next);
    }
  }
  return shortest;
}

void Span::status() const
{
  std::cout << "Size: " << this->_content.size() << std::endl;
  std::cout << "Max size: " << this->_N << std::endl;
  std::cout << "Content: " << std::endl;
  std::list<int>::const_iterator it;
  for (it = this->_content.begin(); it != this->_content.end(); it++)
    std::cout << *it << "\t";
  std::cout << std::endl;
}

const char *Span::SpanNotBigEnough::what() const throw()
{
  return "Span is not big enough to use this function !";
}

const char *Span::ImpossibleToAddElement::what() const throw()
{
  return "Impossible to add an element, this span is already full !";
}

const char *Span::ImpossibleToAddThisRange::what() const throw()
{
  return "Impossible to add this range, it will be an overflow !";
}