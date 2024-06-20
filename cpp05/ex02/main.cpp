#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main(void)
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
}