#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("No name"), _grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) { *this = copy; }

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
  this->canUpdateGrade(grade);
  this->_grade = grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
  if (this != &rhs) {
    this->_grade = rhs.getGrade();
  }
  return *this;
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::canUpdateGrade(int newGrade) const {
  if (newGrade < 1) {
    throw GradeTooHighException();
  } else if (newGrade > 150) {
    throw GradeTooLowException();
  }
}

std::string Bureaucrat::getName() const { return this->_name; }
int Bureaucrat::getGrade() const { return this->_grade; }
void Bureaucrat::incrementGrade() {
  this->canUpdateGrade(this->getGrade() - 1);
  this->_grade--;
}
void Bureaucrat::decrementGrade() {
  this->canUpdateGrade(this->getGrade() + 1);
  this->_grade++;
}

void Bureaucrat::signForm(Form &form) {
  try {
    form.beSigned(*this);
    std::cout << this->getName() << " signed " << form << std::endl;
  }  catch (Form::GradeTooLowException &e) {
    std::cerr << this->getName() << " couldn't sign " << form << " because "
              << e.what() << std::endl;
  }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high !";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low !";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs) {
  out << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
  return out;
}
