#ifndef SCAVTRAP_H
#define SCAVTRAP_H
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
public:
    ScavTrap();
    ScavTrap(std::string);
    ScavTrap(const ScavTrap &);
    ScavTrap &operator=(const ScavTrap &);
    ~ScavTrap();

    void attack(const std::string &target);
    void guardGate(void);
};

#endif