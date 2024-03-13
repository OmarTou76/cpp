#include "Harl.hpp"
#include <iostream>

void displayMenu(void)
{
    std::cout << "Choose a level of complaint:" << std::endl;
    std::cout << "DEBUG | INFO | WARNING | ERROR" << std::endl;
    std::cout << "(Press enter to exit)" << std::endl;
}

int main(void)
{
    std::string query;
    displayMenu();
    Harl harl = Harl();
    while (1)
    {
        std::cout << "> ";
        std::getline(std::cin, query);
        if (query.empty())
            break;
        harl.complain(query);
    }
    return 0;
}
