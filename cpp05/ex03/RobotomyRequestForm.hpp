#pragma once
#include "AForm.hpp"
#include <iostream>

class AForm;

class RobotomyRequestForm : public AForm
{
private:
    std::string _target;
    RobotomyRequestForm();

public:
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &);
    ~RobotomyRequestForm();

    std::string getTarget() const;
    void execute(Bureaucrat const &) const;
};
