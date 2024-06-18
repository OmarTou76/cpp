#include "Bureaucrat.hpp"

int main(void) {
  try {
    Bureaucrat b("John", 149);
    std::cout << b << std::endl;
    b.decrementGrade();
    std::cout << b << std::endl;
    b.decrementGrade();
    std::cout << b << std::endl;
  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cout << "Error: " << e.what() << std::endl;
  } catch (const Bureaucrat::GradeTooHighException &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  std::cout << std::endl;

  try {
    Bureaucrat *a = new Bureaucrat("Doe", 2);
    std::cout << *a << std::endl;
    a->incrementGrade();
    std::cout << *a << std::endl;
    a->incrementGrade();
    std::cout << *a << std::endl;
    delete a;
  } catch (const Bureaucrat::GradeTooLowException &e) {
    std::cout << "Error: " << e.what() << std::endl;
  } catch (const Bureaucrat::GradeTooHighException &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  return 0;
}
