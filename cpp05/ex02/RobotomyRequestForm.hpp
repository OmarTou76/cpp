#pragma once
#include "AForm.hpp"
#include <iostream>
#include <fstream>

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
    virtual void execute(Bureaucrat const &) const;
};