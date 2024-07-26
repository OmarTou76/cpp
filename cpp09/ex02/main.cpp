#include "PmergeMe.h"
#include <exception>
#include <iostream>

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "Error: no input provided !" << std::endl;
    return 1;
  }
  try {
    PmergeMe pmp(argc, argv);
    pmp.run();
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
