#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstddef>

Intern::Intern() {}
Intern::Intern(const Intern &copy) { *this = copy; }
Intern &Intern::operator=(const Intern &rhs) {
  (void)rhs;
  return *this;
};
Intern::~Intern() {}

void Intern::StrToLower(std::string &str) const {
  for (size_t i = 0; i < str.length(); i++)
    str[i] = std::tolower(str[i]);
}

AForm *Intern::RC(std::string &targetName) {
  return new RobotomyRequestForm(targetName);
}
AForm *Intern::SC(std::string &targetName) {
  return new ShrubberyCreationForm(targetName);
}
AForm *Intern::PP(std::string &targetName) {
  return new PresidentialPardonForm(targetName);
}

AForm *Intern::makeForm(std::string formName, std::string targetName) {
  AForm *form;
  this->StrToLower(targetName);
  const std::string forms[] = {
      "shrubbery creation",
      "robotomy request",
      "presidential pardon",
  };
  AForm *(Intern::*formsFunc[])(std::string &) = {&Intern::RC, &Intern::SC,
                                                  &Intern::PP};
  for (size_t i = 0; i < 3; i++) {
    if (!forms[i].compare(formName)) {
      form = (this->*formsFunc[i])(targetName);
      std::cout << "Intern creates " << formName << std::endl;
      return form;
    }
  }
  std::cout << formName << " is unknown type of form." << std::endl;
  return NULL;
}
