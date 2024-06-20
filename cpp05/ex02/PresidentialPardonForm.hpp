#pragma once
#include "AForm.hpp"
#include <iostream>

class AForm;

class PresidentialPardonForm : public AForm
{
private:
    std::string _target;
    PresidentialPardonForm();

public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &);
    ~PresidentialPardonForm();

    std::string getTarget() const;
    void execute(Bureaucrat const &) const;
};