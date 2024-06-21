#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45), _target("No-Name") {}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 72, 45), _target(target) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) { *this = copy; }
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    if (this != &rhs)
        this->_target = rhs.getTarget();
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm() {}

std::string RobotomyRequestForm::getTarget() const { return this->_target; }

void RobotomyRequestForm::execute(Bureaucrat const &b) const
{
    if (!this->isSigned())
        throw FormNotSignedException();
    else if (b.getGrade() > this->getGradeRequiredToExecute())
        throw GradeTooLowException();

    std::cout << "- BZZZZZT -" << std::endl;
    srand(time(0));
    int randomNumber = rand() % 2;
    if (randomNumber)
        std::cout << this->getTarget() << " has been robotomized successfully !" << std::endl;
    else
        std::cout << this->getTarget() << " has been failed robotomy  !" << std::endl;
}
