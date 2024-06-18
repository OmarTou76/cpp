#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("No name"), _grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) { *this = copy; }

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name) {
  if (grade < 1) { throw GradeTooLowException(); }
  if (grade > 150) { throw GradeTooHighException(); }
  this->_grade = grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs) {
  if (this != &rhs) {
    this->_name = rhs.getName();
    this->_grade = rhs.getGrade();
  }
  return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const { return this->_name; }
unsigned int Bureaucrat::getGrade() const { return this->_grade; }
void Bureaucrat::incrementGrade() {}
void Bureaucrat::decrementGrade() {}


const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade to high !";
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade to low !";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &rhs) {
	out << rhs.getName() << " has grade " << rhs.getGrade();
	return out;
}
