#include "Harl.hpp"
#include <iostream>


int main(int argc, char const *argv[])
{
    Harl harl = Harl();
    if (argc != 2)
    {
        std::cout << "[USAGE]: " << argv[0] << " [ 'DEBUG' | 'INFO' | 'WARNING' | 'ERROR' ]" << std::endl;
        return 1;
    }
    harl.complain(argv[1]);
    return 0;
}
