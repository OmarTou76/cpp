#include "PmergeMe.h"
#include <iostream>

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "Error: " << std::endl;
    return 1;
  }
  try {
    PmergeMe pmp(argc, argv);
    PmergeMe pm = pmp;
    pmp.displayValues();
  } catch (...) {
  }
  return 0;
}