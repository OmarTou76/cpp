#include "Zombie.hpp"

int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;
    Zombie *z = newZombie("First");
    randomChump("Second");
    randomChump("Third");
    z->annonce();
    delete z;
    return 0;
}
