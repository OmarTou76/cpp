#include "PmergeMe.h"
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <exception>
#include <iomanip>
#include <ios>
#include <iterator>
#include <list>
#include <utility>

PmergeMe::PmergeMe()
    : _list(), _dq(), _hasLast(false), _elapsedTimeList(-1),
      _elapsedTimeDeque(-1) {}
PmergeMe::PmergeMe(int argc, char **argv)
    : _list(), _dq(), _hasLast(false), _elapsedTimeList(-1),
      _elapsedTimeDeque(-1) {
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
  sortContainers();
  displayValues("After");
  displayTimeToProceed();
}

pairDq PmergeMe::getSubPairDq(pairDq::iterator start, pairDq::iterator end) {
  pairDq list;
  for (pairDq::iterator it = start; it != end; it++) {
    list.push_back(*it);
  }
  return list;
}

template <typename ContainerPair, typename Container>
ContainerPair PmergeMe::getPair(Container container) {
  ContainerPair list;
  int i = 0;
  typedef typename Container::const_iterator iterator;
  for (iterator it = container.begin(); it != container.end(); it++) {
    if (i % 2 == 0 && size_t(i) != container.size() - 1) {
      unsigned int f = *it++;
      unsigned int s = *it;
      unsigned int first = std::min(f, s);
      unsigned int second = std::max(f, s);
      --it;
      list.push_back(std::make_pair(first, second));
    } else if (i % 2 == 0 && size_t(i) == container.size() - 1) {
      _hasLast = true;
      _last = *it;
    }
    i++;
  }
  return list;
}

pairList PmergeMe::getSubPairList(pairList::iterator start,
                                  pairList::iterator end) {
  pairList list;
  for (pairList::iterator it = start; it != end; it++) {
    list.push_back(*it);
  }
  return list;
}

void PmergeMe::sortList(pairList &list) {
  if (list.size() <= 1)
    return;

  pairList::iterator mid = list.begin();
  std::advance(mid, list.size() / 2);
  pairList start = getSubPairList(list.begin(), mid);
  pairList end = getSubPairList(mid, list.end());

  sortList(start);
  sortList(end);

  list.clear();
  while (start.size() && end.size()) {
    if (start.front().second < end.front().second) {
      list.push_back(start.front());
      start.pop_front();
    } else {
      list.push_back(end.front());
      end.pop_front();
    }
  }

  while (start.size()) {
    list.push_back(start.front());
    start.pop_front();
  }

  while (end.size()) {
    list.push_back(end.front());
    end.pop_front();
  }
}

void PmergeMe::sortDq(pairDq &list) {
  if (list.size() <= 1)
    return;

  pairDq::iterator mid = list.end() - list.size() / 2;
  pairDq start = getSubPairDq(list.begin(), mid);
  pairDq end = getSubPairDq(mid, list.end());

  sortDq(start);
  sortDq(end);

  size_t i_start = 0;
  size_t i_end = 0;
  size_t i = 0;
  while (i_start < start.size() && i_end < end.size()) {
    if (start[i_start].second < end[i_end].second) {
      list[i] = start[i_start++];
    } else {
      list[i] = end[i_end++];
    }
    i++;
  }

  while (i_start < start.size()) {
    list[i++] = start[i_start++];
  }

  while (i_end < end.size()) {
    list[i++] = end[i_end++];
  }
}

std::deque<unsigned int> getSequences(unsigned int max) {
    std::deque<unsigned int> groupSizes(2, 2);
    unsigned int acc = 4; // Somme des éléments actuels (2 + 2)
      unsigned int index = 1; // Index du dernier élément ajouté

      while (acc < max) {
          unsigned int next = groupSizes[index] + 2 * groupSizes[index - 1];
          groupSizes.push_back(next);
          acc += next;
          index++;
      }

      return groupSizes;
}

void PmergeMe::partitionRemainingElements(std::deque<unsigned int> &remainingElements) {
  std::deque<unsigned int> orderedElements;
  std::deque<unsigned int> subArrSize = getSequences(remainingElements.size());
  size_t index = 0;

  for (size_t s = 0; s < subArrSize.size(); s++) {
    if (index >= remainingElements.size())
      break;
    int size = subArrSize[s];

    std::cout << "groupe size: " << size << std::endl;
    size_t endIndex = std::min(index + size, remainingElements.size());
    std::deque<unsigned int> group(remainingElements.begin() + index,
                    remainingElements.begin() + endIndex);
    std::reverse(group.begin(), group.end()); // Trier par index décroissant
    orderedElements.insert(orderedElements.end(), group.begin(), group.end());
    index = endIndex;
  }
  std::deque<unsigned int>::iterator it;
  remainingElements = orderedElements;
}

template <typename ContainerPair, typename Container>
void PmergeMe::insert(ContainerPair list, Container &container) {
  container.clear();
// POURQUOI DES ELEMENTS DISPARAISSENT
  std::deque<unsigned int> remainingElements;
  if (_hasLast)
    remainingElements.push_back(_last);
  typedef typename ContainerPair::iterator iteratorPair;
  typedef typename Container::iterator iterator;
  for (iteratorPair it = list.begin(); it != list.end(); it++) {
    remainingElements.push_back(it->first);
    container.push_back(it->second);
  }

  partitionRemainingElements(remainingElements);
  std::deque<unsigned int>::iterator it;
  for (it = remainingElements.begin(); it != remainingElements.end(); it++)
  {
    iterator pos =
        std::lower_bound(container.begin(), container.end(), *it);
        container.insert(pos, *it);
  }
}

template <typename ContainerPair> void printContent(ContainerPair container) {
  typedef typename ContainerPair::iterator iteratorPair;
  std::cout << "DULIRE\n";
  for (iteratorPair it = container.begin(); it != container.end(); it++) {
    std::cout << it->first << " -> " << it->second << std::endl;
  }
}

void PmergeMe::sortContainers() {
  clock_t start = clock();
  pairDq dq = getPair<pairDq>(_dq);
  // printContent(dq);
  sortDq(dq);
  // printContent(dq);
  insert(dq, _dq);
  clock_t end = clock();
  _elapsedTimeDeque = static_cast<double>(end - start) / CLOCKS_PER_SEC;

  start = clock();
  pairList list = getPair<pairList>(_list);
  // printContent(dq);
  sortList(list);
  insert(list, _list);
  end = clock();
  _elapsedTimeList = static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

void PmergeMe::displayTimeToProceed() const {
  std::cout << "Time to process a range of " << _list.size()
            << " elements with std::list : " << std::fixed
            << std::setprecision(6) << _elapsedTimeList << " us" << std::endl;
  std::cout << "Time to process a range of " << _dq.size()
            << " elements with std::deque : " << std::fixed
            << std::setprecision(6) << _elapsedTimeDeque << " us" << std::endl;
}

int PmergeMe::convertValue(const char *val) {
  long ret = atoi(val);
  if (ret < 0 || (ret == 0 && (strlen(val) != 1 || val[0] != '0')))
    throw InvalidImput();
  return ret;
}

void PmergeMe::displayValues(const std::string label) const {
  std::cout << label << ":\t";
  if (_dq.size()) {
    std::deque<unsigned int>::const_iterator it;
    for (it = _dq.begin(); it != _dq.end(); it++)
      std::cout << " " << *it;
  }
  std::cout << std::endl;
}
