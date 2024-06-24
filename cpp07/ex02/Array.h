#pragma once
#include <iostream>
#include <iterator>

template <typename T> class Array {
private:
  unsigned int _N;
  T *_content;

public:
  Array() : _N(0), _content(new T()){};
  ~Array() {
    if (_content)
      delete[] _content;
  };

  Array(unsigned int size) : _N(size), _content(new T[size]){};

  Array(Array const &c) : _N(c.size()), _content(new T[c.size()]) {
    for (unsigned int i = 0; i < this->_N; i++)
      this->_content[i] = c._content[i];
  };

  const Array &operator=(Array const &rhs) {
    if (this != &rhs) {
      delete[] _content;
      _N = rhs.size();
      _content = new T[_N];
      for (unsigned int i = 0; i < _N; i++)
        _content[i] = rhs._content[i];
    }
    return *this;
  };

  T &operator[](int index) {
    if (index < 0 || index >= static_cast<int>(_N))
      throw IndexOutOfBounds();
    return _content[index];
  };

  unsigned int size() const { return _N; };

  class IndexOutOfBounds : public std::exception {
  public:
    virtual const char *what() const throw() {
      return "Index out of bounds !";
    };
  };
};
