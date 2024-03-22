#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"
#define ITEMS_QUANTITY 4

class Character : public ICharacter
{
private:
    std::string _name;
    AMateria *_items[ITEMS_QUANTITY];
    void _initItems(void);

public:
    Character();
    Character(std::string name);
    Character(const Character &);
    Character &operator=(const Character &);
    ~Character();
    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
};

#endif