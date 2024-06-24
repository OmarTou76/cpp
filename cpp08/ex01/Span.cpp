#include "Span.h"
#include <algorithm>
#include <cmath>
#include <stdexcept>

Span::Span() : _N(0) {}
Span::Span(unsigned int size) : _N(size) {}
Span::Span(Span const &c) { *this = c; }
Span &Span::operator=(Span const &rhs) {
  if (this != &rhs) {
    this->_N = rhs._N;
    this->_content = rhs._content;
  }
  return *this;
}
Span::~Span() {}

void Span::addNumber(int number) {
  if (_content.size() >= _N)
    throw std::out_of_range("Cannot add number to list, it's full !");
  this->_content.push_back(number);
}

unsigned int Span::longestSpan() const {
  if (this->_N < 2)
    throw std::out_of_range(
        "Cannot find longest span range, we need min 2 numbers !");
  return *std::max_element(this->_content.begin(), this->_content.end()) -
         *std::min_element(this->_content.begin(), this->_content.end());
}

unsigned int Span::shortestSpan() const {
  if (this->_N < 2)
    throw std::out_of_range(
        "Cannot find shortest span range, we need min 2 numbers !");
  int shortest = INFINITY;
  for (int i = 0; i < this->_content.size(); i++) {
    // Implement double for loops.
  }
  return 1;
}
