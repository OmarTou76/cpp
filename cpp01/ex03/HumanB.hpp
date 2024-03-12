
#ifndef HUMANB_H
#define HUMANB_H
#include "Weapon.hpp"

class HumanB {
    private:
        Weapon *_weapon;
        std::string _name;

    public:
        HumanB(std::string);
        ~HumanB();
        void attack(void);
        void setWeapon(Weapon&);
};

#endif
