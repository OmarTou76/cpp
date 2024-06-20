#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Robotomy", 25, 5), _target("No-Name") {}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Robotomy", 25, 5), _target(target) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) { *this = copy; }
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    if (this != &rhs)
        this->_target = rhs.getTarget();
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm() {}

std::string PresidentialPardonForm::getTarget() const { return this->_target; }

void PresidentialPardonForm::execute(Bureaucrat const &b) const
{
    if (!this->isSigned())
        throw FormNotSignedException();
    else if (b.getGrade() > this->getGradeRequiredToExecute())
        throw GradeTooLowException();

    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox !" << std::endl;
}
