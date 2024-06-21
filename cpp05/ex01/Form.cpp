#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::~Form() {}
Form::Form()
    : _name("<No-Name>"), _isSigned(false), _gradeRequiredToSign(1),
      _gradeRequiredToExecute(1) {}

Form::Form(std::string name, int gradeRequiredToSign,
           int gradeRequiredToExecute)
    : _name(name), _isSigned(false), _gradeRequiredToSign(gradeRequiredToSign),
      _gradeRequiredToExecute(gradeRequiredToExecute) {
  this->gradeChecker(gradeRequiredToSign);
  this->gradeChecker(gradeRequiredToExecute);
}

Form::Form(const Form &copy)
    : _name(copy._name), _isSigned(copy.isSigned()),
      _gradeRequiredToSign(copy._gradeRequiredToSign),
      _gradeRequiredToExecute(copy._gradeRequiredToExecute) {}

Form &Form::operator=(const Form &rhs) {
  if (&rhs != this) {
    this->_isSigned = rhs.isSigned();
  }
  return *this;
}

const char *Form::GradeTooHighException::what() const throw() {
  return "Grade is too high !";
}
const char *Form::GradeTooLowException::what() const throw() {
  return "Grade is too low !";
}

void Form::gradeChecker(int grade) const {
  if (grade < 1) {
    throw GradeTooLowException();
  } else if (grade > 150) {
    throw GradeTooHighException();
  }
}

std::string Form::getName() const { return this->_name; }
bool Form::isSigned() const { return this->_isSigned; }

int Form::getGradeRequiredToSign() const { return this->_gradeRequiredToSign; }

int Form::getGradeRequiredToExecute() const {
  return this->_gradeRequiredToExecute;
}

void Form::beSigned(Bureaucrat &person) {
  if (person.getGrade() > this->getGradeRequiredToSign())
    throw GradeTooLowException();
  this->_isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const Form &rhs) {
  out << rhs.getName();
  return out;
}
