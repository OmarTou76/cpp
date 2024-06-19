#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
    try
    {

        Bureaucrat b("Johm", 137);
        ShrubberyCreationForm a("Contract");
        b.signForm(a);
        a.execute(b);

        std::cout << std::endl
                  << "-------------" << std::endl
                  << std::endl;

        Bureaucrat c("Doe", 37);
        RobotomyRequestForm d("Contract");
        c.signForm(d);
        d.execute(c);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}