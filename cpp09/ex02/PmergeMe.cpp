#include "PmergeMe.h"
#include <cstdlib>
#include <cstring>
#include <exception>

PmergeMe::PmergeMe() : _values() {}
PmergeMe::PmergeMe(int argc, char **argv) : _values() {
  this->storeValues(argc, argv);
}
PmergeMe::PmergeMe(const PmergeMe &cp) { *this = cp; }
PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
  if (this != &rhs)
    this->_values = rhs._values;
  return *this;
}
PmergeMe::~PmergeMe() {}

void PmergeMe::storeValues(int argc, char **argv) {
  for (int i = 1; i < argc; i++) {
    try {
      unsigned int v = static_cast<unsigned int>(convertValue(argv[i]));
      _values.push_back(v);
    } catch (std::exception &e) {
      std::cerr << "Error: " << e.what() << std::endl;
      _values.clear();
      break;
    }
  }
}

int PmergeMe::convertValue(const char *val) {
  int ret = atoi(val);
  if (ret < 0 || (ret == 0 && (strlen(val) != 1 || val[0] != '0')))
    throw InvalidImput();
  return ret;
}

void PmergeMe::displayValues() const {
  if (_values.size()) {
  std::list<unsigned int>::const_iterator it;
  std::cout << "Values: " << std::endl;
  for (it = _values.begin(); it != _values.end(); it++)
    std::cout << "\t" << *it << std::endl;
  }
}
