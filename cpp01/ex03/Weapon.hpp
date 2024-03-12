#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>

class Weapon
{

private:
    std::string _type;

public:
    Weapon(void);
    Weapon(std::string);
    ~Weapon();
    std::string const &getType(void);
    void setType(std::string);
};
#endif
