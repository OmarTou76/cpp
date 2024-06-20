#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
    try
    {
        Intern intern;
        AForm *rrf;

        Bureaucrat c("Doe", 37);

        rrf = intern.makeForm("Shrubbery creation", "Bender");
        c.signForm(*rrf);
        c.executeForm(*rrf);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

/* int main(void)
{
    try
    {
        Bureaucrat b("John", 137);
        ShrubberyCreationForm a("Contract");
        b.signForm(a);
        b.executeForm(a);

        std::cout << std::endl
                  << "-------------" << std::endl
                  << std::endl;

        Bureaucrat c("Doe", 37);
        RobotomyRequestForm d("Contract");
        c.signForm(d);
        c.executeForm(d);

        std::cout << std::endl
                  << "-------------" << std::endl
                  << std::endl;

        Bureaucrat e("Kevin", 5);
        PresidentialPardonForm f("Contract");
        e.signForm(f);
        e.executeForm(f);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
} */