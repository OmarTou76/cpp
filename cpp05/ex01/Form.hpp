#pragma once
#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
private:
  const std::string _name;
  bool _isSigned;
  const int _gradeRequiredToSign;
  const int _gradeRequiredToExecute;
  Form();
  Form &operator=(const Form &);
  void gradeChecker(int grade) const;

public:
  Form(std::string, int gradeRequiredToSign, int gradeRequiredToExecute);
  Form(const Form &);
  ~Form();
  std::string getName() const;
  bool isSigned() const;
  int getGradeRequiredToSign() const;
  int getGradeRequiredToExecute() const;
  void beSigned(Bureaucrat &);

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &out, const Form &);
