#pragma once
#include <cstddef>
#include <deque>
#include <exception>
#include <iomanip>
#include <iostream>
#include <list>
typedef std::pair<unsigned int, unsigned int> unsignedPair;
typedef std::deque<unsignedPair> pairDq;
typedef std::list<unsignedPair> pairList;

class PmergeMe {
private:
  std::list<unsigned int> _list;
  std::deque<unsigned int> _dq;
  unsigned _last;
  double _elapsedTimeList;
  double _elapsedTimeDeque;

  void storeValues(int argc, char **argv);
  int convertValue(const char *val);
  void displayValues(const std::string label) const;
  void displayTimeToProceed() const;
  void sortContainers();
  void insertDq(pairDq list);
  template <typename ContainerPair, typename Container>
  void insert(ContainerPair list, Container &container);
  void sortDq(pairDq &);
  void sortList(pairList &);
  template <typename ContainerPair, typename Container>
  ContainerPair getPair(Container);
  template <typename Container>
  Container getSubPair(typename Container::iterator start,
                       typename Container::iterator end);
  pairDq getSubPairDq(pairDq::iterator start, pairDq::iterator end);
  pairList getSubPairList(pairList::iterator start, pairList::iterator end);
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
