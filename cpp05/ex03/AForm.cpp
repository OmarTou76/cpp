#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::~AForm() {}
AForm::AForm()
    : _name("<No-Name>"), _isSigned(false), _gradeRequiredToSign(1),
      _gradeRequiredToExecute(1) {}

AForm::AForm(std::string name, int gradeRequiredToSign,
             int gradeRequiredToExecute)
    : _name(name), _isSigned(false), _gradeRequiredToSign(gradeRequiredToSign),
      _gradeRequiredToExecute(gradeRequiredToExecute)
{
  this->gradeChecker(gradeRequiredToSign);
  this->gradeChecker(gradeRequiredToExecute);
}

AForm::AForm(const AForm &copy)
    : _name(copy._name), _isSigned(copy.isSigned()),
      _gradeRequiredToSign(copy._gradeRequiredToSign),
      _gradeRequiredToExecute(copy._gradeRequiredToExecute) {}

AForm &AForm::operator=(const AForm &rhs)
{
  if (&rhs != this)
  {
    this->_isSigned = rhs.isSigned();
  }
  return *this;
}

const char *AForm::GradeTooHighException::what() const throw()
{
  return "Grade is too high !";
}
const char *AForm::GradeTooLowException::what() const throw()
{
  return "Grade is too low !";
}
const char *AForm::FormNotSignedException::what() const throw()
{
  return "Form is not signed !";
}

void AForm::gradeChecker(int grade) const
{
  if (grade < 1)
    throw GradeTooHighException();
  else if (grade > 150)
    throw GradeTooLowException();
}

std::string AForm::getName() const { return this->_name; }
bool AForm::isSigned() const { return this->_isSigned; }

int AForm::getGradeRequiredToSign() const { return this->_gradeRequiredToSign; }

int AForm::getGradeRequiredToExecute() const
{
  return this->_gradeRequiredToExecute;
}

void AForm::beSigned(Bureaucrat &person)
{
  if (person.getGrade() >= this->getGradeRequiredToSign())
    throw GradeTooLowException();
  this->_isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const AForm &rhs)
{
  out << rhs.getName();
  return out;
}
