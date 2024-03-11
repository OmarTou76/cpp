#include "Zombie.hpp"

int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;

    Zombie *z = zombieHorde(10, "Zombie-test");
    int i = 0;

    while (i < 10)
    {
        std::cout << i << ": ";
        z[i].annonce();
        std::cout << std::endl;
        i++;
    }
    delete[] z;
    return 0;
}
