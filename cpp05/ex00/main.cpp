#include "Bureaucrat.hpp"

int main(void) {

  try {
    Bureaucrat t("Over", 151);
    std::cout << t << std::endl;
  } catch (std::exception &e) {
    std::cerr << "'Over': " << e.what() << std::endl;
  }

  std::cout << std::endl;

  try {
    Bureaucrat n("Less", 0);
    std::cout << n << std::endl;
  } catch (std::exception &e) {
    std::cerr << "'Less': " << e.what() << std::endl;
  }

  std::cout << std::endl;

  try {
    Bureaucrat b("John", 149);
    std::cout << b << std::endl;
    b.decrementGrade();
    std::cout << b << std::endl;
    b.decrementGrade();
    std::cout << b << std::endl;
  } catch (std::exception &e) {
    std::cerr << "'John': " << e.what() << std::endl;
  }

  std::cout << std::endl;

  Bureaucrat *a = new Bureaucrat("Doe", 2);
  try {
    std::cout << *a << std::endl;
    a->incrementGrade();
    std::cout << *a << std::endl;
    a->incrementGrade();
    std::cout << *a << std::endl;
  } catch (std::exception &e) {
    std::cerr << "'Doe': " << e.what() << std::endl;
  }
  delete a;
  return 0;
}
