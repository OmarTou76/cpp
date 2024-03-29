#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl
              << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl
              << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl
              << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl
              << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl
              << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl
              << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl
              << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
void Harl::complain(std::string level)
{
    bool isValidLevel = false;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; ++i)
    {
        if (level.compare(levels[i]) == 0)
        {
            isValidLevel = true;
            break;
        }
    }
    if (!isValidLevel)
    {
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
        return;
    }
    switch (level[0])
    {
    case 'D':
        this->debug();
    case 'I':
        this->info();
    case 'W':
        this->warning();
    case 'E':
        this->error();
    default:
        break;
    }
}

Harl::Harl() {}

Harl::~Harl() {}
