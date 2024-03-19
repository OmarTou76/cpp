#include <iostream>
#include "contact.hpp"
#include "phonebook.hpp"

int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;
    Phonebook phonebook;
    std::string cmd;
    while (1)
    {
        std::cout << "Valid commands: ADD, SEARCH, EXIT" << std::endl
                  << ">  ";
        std::getline(std::cin, cmd);
        if (cmd.compare("EXIT") == 0)
            break;
        else if (cmd.compare("ADD") == 0)
            phonebook.add();
        else if (cmd.compare("SEARCH") == 0)
            phonebook.search();
        std::cout << std::endl;
    }
    return 0;
}
