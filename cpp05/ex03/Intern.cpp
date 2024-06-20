#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &copy) { *this = copy; }
Intern &Intern::operator=(const Intern &rhs)
{
    (void)rhs;
    return *this;
};
Intern::~Intern() {}

void Intern::StrToLower(std::string &str) const
{
    for (size_t i = 0; i < str.length(); i++)
        str[i] = std::tolower(str[i]);
}

int Intern::indexOf(std::string target) const
{
    const std::string forms[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon",
    };
    this->StrToLower(target);
    for (size_t i = 0; i < forms->length(); i++)
    {
        if (!forms[i].compare(target))
            return (int)i;
    }
    return -1;
}

AForm *Intern::makeForm(std::string formName, std::string targetName) const
{
    AForm *form;
    switch (this->indexOf(formName))
    {
    case 0:
        form = new ShrubberyCreationForm(targetName);
        break;
    case 1:
        form = new RobotomyRequestForm(targetName);
        break;
    case 2:
        form = new PresidentialPardonForm(targetName);
        break;
    default:
        throw FormInvalid();
    }
    std::cout << "Intern creates " << formName << std::endl;
    return form;
}

const char *Intern::FormInvalid::what() const throw()
{
    return "Form does not exist !";
}
