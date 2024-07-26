#include "PmergeMe.h"
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <exception>
#include <iomanip>
#include <ios>

PmergeMe::PmergeMe()
    : _list(), _dq(), _elapsedTimeList(-1), _elapsedTimeDeque(-1) {}
PmergeMe::PmergeMe(int argc, char **argv)
    : _list(), _dq(), _elapsedTimeList(-1), _elapsedTimeDeque(-1) {
  this->storeValues(argc, argv);
}
PmergeMe::PmergeMe(const PmergeMe &cp) { *this = cp; }
PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
  if (this != &rhs) {
    this->_list = rhs._list;
    this->_dq = rhs._dq;
    this->_elapsedTimeList = rhs._elapsedTimeList;
    this->_elapsedTimeDeque = rhs._elapsedTimeDeque;
  }
  return *this;
}
PmergeMe::~PmergeMe() {}

void PmergeMe::storeValues(int argc, char **argv) {
  for (int i = 1; i < argc; i++) {
    try {
      unsigned int v = static_cast<unsigned int>(convertValue(argv[i]));
      _list.push_back(v);
      _dq.push_back(v);
    } catch (...) {
      _list.clear();
      _dq.clear();
      throw InvalidImput();
    }
  }
}

void PmergeMe::run() {
  displayValues("Before");
  sort();
  displayValues("After");
  displayTimeToProceed();
}

template <typename Container>
void PmergeMe::merge(Container &start, Container &end) {
  Container result;
  while (!start.empty() && !end.empty()) {
    if (start.front() < end.front()) {
      result.push_back(start.front());
      start.pop_front();
    } else {
      result.push_back(end.front());
      end.pop_front();
    }
  }

  while (!start.empty()) {
    result.push_back(start.front());
    start.pop_front();
  }

  while (!end.empty()) {
    result.push_back(end.front());
    end.pop_front();
  }
  start = result;
}

template <typename Container> void PmergeMe::sortList(Container &list) {
  if (list.size() <= 1)
    return;

  Container start, end;

  int n = list.size() / 2;
  for (int i = 0; i < n; i++) {
    start.push_back(list.front());
    list.pop_front();
  }

  while (!list.empty()) {
    end.push_back(list.front());
    list.pop_front();
  }

  sortList(start);
  sortList(end);

  merge(start, end);
  list = start;
}

int PmergeMe::convertValue(const char *val) {
  int ret = atoi(val);
  if (ret < 0 || (ret == 0 && (strlen(val) != 1 || val[0] != '0')))
    throw InvalidImput();
  return ret;
}

void PmergeMe::sort() {
  clock_t start = clock();
  sortList(_list);
  clock_t end = clock();
  _elapsedTimeList = static_cast<double>(end - start) / CLOCKS_PER_SEC;
  start = clock();
  sortList(_dq);
  end = clock();
  _elapsedTimeDeque = static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

// Time to process a range of 5 elements with std::[..] : 0.00031 us
void PmergeMe::displayTimeToProceed() const {
  std::cout << "Time to process a range of " << _list.size()
            << " elements with std::list<unsigned int> : " << std::fixed
            << std::setprecision(6) << _elapsedTimeList << " us" << std::endl;
  std::cout << "Time to process a range of " << _dq.size()
            << " elements with std::deque<unsigned int> : " << std::fixed
            << std::setprecision(6) << _elapsedTimeDeque << " us" << std::endl;
}

void PmergeMe::displayValues(const std::string label) const {
  std::cout << label << ":\t";
  if (_list.size()) {
    std::list<unsigned int>::const_iterator it;
    for (it = _list.begin(); it != _list.end(); it++)
      std::cout << " " << *it;
  }
  std::cout << std::endl;
}
