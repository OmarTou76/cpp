#pragma once
#include <iostream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
protected:
  std::string _name;
  bool _isSigned;
  const int _gradeRequiredToSign;
  const int _gradeRequiredToExecute;
  AForm();
  AForm &operator=(const AForm &);
  void gradeChecker(int grade) const;

public:
  AForm(std::string, int gradeRequiredToSign, int gradeRequiredToExecute);
  AForm(const AForm &);
  virtual ~AForm();
  std::string getName() const;
  bool isSigned() const;
  int getGradeRequiredToSign() const;
  int getGradeRequiredToExecute() const;
  void beSigned(Bureaucrat &);

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class FormNotSignedException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  virtual void execute(Bureaucrat const &) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &);
