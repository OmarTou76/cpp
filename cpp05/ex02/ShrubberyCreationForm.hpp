#pragma once
#include "AForm.hpp"
#include <iostream>
#include <fstream>

class AForm;

class ShrubberyCreationForm : public AForm
{
private:
  std::string _target;
  ShrubberyCreationForm();

public:
  ShrubberyCreationForm(std::string target);
  ShrubberyCreationForm(const ShrubberyCreationForm &);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);
  ~ShrubberyCreationForm();

  std::string getTarget() const;
  void writeAsciiTree(std::ostream &file) const;
  virtual void execute(Bureaucrat const &) const;
};