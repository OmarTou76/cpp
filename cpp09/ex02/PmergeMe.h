#pragma once
#include <exception>
#include <iostream>
#include <iomanip>
#include <list>
#include <deque>
class PmergeMe {
private:
  std::list<unsigned int> _list;
  std::deque<unsigned int> _dq;
  double _elapsedTimeList;
  double _elapsedTimeDeque;

  void storeValues(int argc, char **argv);
  int convertValue(const char *val);
  template <typename Container>
  void merge(Container &, Container &);
  template <typename Container>
  void sortList(Container &);
  void displayValues(const std::string label) const;
  void displayTimeToProceed() const;
  void sort();
  PmergeMe();

public:
  PmergeMe(int argc, char **argv);
  PmergeMe(const PmergeMe &);
  PmergeMe &operator=(const PmergeMe &);
  ~PmergeMe();

  void run();

  class InvalidImput : public std::exception {
  public:
    const char *what() const throw() { return "Invalid input !"; }
  };
};
