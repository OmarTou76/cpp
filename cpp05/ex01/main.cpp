#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
  try {
    Bureaucrat b("John", 14);
    Form form("Contract", 20, 10);
    b.signForm(form);
  } catch (std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  std::cout << std::endl;

  try {
    Bureaucrat *a = new Bureaucrat("Doe", 20);
    Form form("Contract", 10, 20);
    a->signForm(form);
    delete a;
  } catch (std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }

  return 0;
}
