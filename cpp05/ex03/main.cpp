#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  Intern intern;
  AForm *rrf;

  Bureaucrat c("Doe", 37);

  rrf = intern.makeForm("robotomy request", "Bender");
  if (rrf) {
    c.signForm(*rrf);
    c.executeForm(*rrf);
    delete rrf;
  }


  Intern Error;

  rrf = intern.makeForm("Error form", "Bender");
  if (rrf) {
    c.signForm(*rrf);
    c.executeForm(*rrf);
    delete rrf;
  }
  return 0;
}
