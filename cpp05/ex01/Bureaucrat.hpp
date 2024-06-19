#pragma once
#include <iostream>

#include "Form.hpp"

class Form;

class Bureaucrat {
private:
  std::string _name;
  int _grade;

public:
  Bureaucrat();
  Bureaucrat(const Bureaucrat &);
  Bureaucrat(std::string name, int grade);
  Bureaucrat &operator=(const Bureaucrat &rhs);
  ~Bureaucrat();

  std::string getName() const;
  int getGrade() const;

  void canUpdateGrade(int newGrade) const;

  void incrementGrade();
  void decrementGrade();
  void signForm(Form &form);

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs);
