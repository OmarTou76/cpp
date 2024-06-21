#pragma once
#include "AForm.hpp"
#include <iostream>

class AForm;

class ShrubberyCreationForm : public AForm
{
private:
  std::string _target;
  ShrubberyCreationForm();
  void writeAsciiTree(std::ostream &file) const;

public:
  ShrubberyCreationForm(std::string target);
  ShrubberyCreationForm(const ShrubberyCreationForm &);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);
  ~ShrubberyCreationForm();

  std::string getTarget() const;
  void execute(Bureaucrat const &) const;
};
