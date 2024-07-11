#pragma once
#include <exception>
#include <iostream>
#include <list>
class PmergeMe {
private:
  std::list<unsigned int> _values;
  PmergeMe();
  void storeValues(int argc, char **argv);
  int convertValue(const char *val);

public:
  PmergeMe(int argc, char **argv);
  PmergeMe(const PmergeMe &);
  PmergeMe &operator=(const PmergeMe &);
  ~PmergeMe();
  void displayValues() const;

  class InvalidImput : public std::exception {
  public:
    const char *what() const throw() { return "Invalid input !"; }
  };
};
