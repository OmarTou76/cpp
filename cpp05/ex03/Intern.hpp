#pragma once
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
    int indexOf(std::string) const;
    void StrToLower(std::string &) const;

public:
    Intern();
    Intern(const Intern &);
    Intern &operator=(const Intern &);
    ~Intern();

    AForm *makeForm(std::string, std::string) const;

    class FormInvalid : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};