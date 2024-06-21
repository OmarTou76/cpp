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

  Bureaucrat *a = new Bureaucrat("Doe", 21);
  try {
    Form form("Contract", 20, 10);
    a->signForm(form);
  } catch (std::exception &e) {
    std::cout << "Error: " << e.what() << std::endl;
  }
  delete a;
  return 0;
}
