#include "Character.hpp"
#include "Cure.hpp"

Character::Character() : _name("No-name") { this->_initItems(); }
Character::Character(std::string name) : _name(name) { this->_initItems(); }
Character::Character(const Character &copy) { *this = copy; }
Character &Character::operator=(const Character &rhs)
{
    if (this != &rhs)
    {
        this->_name = rhs.getName();
        for (int i = 0; i < ITEMS_QUANTITY; i++)
        {
            if (this->_items[i])
                delete this->_items[i];
            this->_items[i] = rhs._items[i]->clone();
        }
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < ITEMS_QUANTITY; i++)
    {
        if (this->_items[i])
            delete this->_items[i];
    }
}

std::string const &Character::getName() const { return this->_name; }

void Character::equip(AMateria *m)
{
    if (!m)
        return;
    for (int i = 0; i < ITEMS_QUANTITY; i++)
    {
        if (this->_items[i] == NULL)
        {
            this->_items[i] = m;
            break;
        }
    }
}
void Character::unequip(int idx)
{
    this->_items[idx] = NULL;
}
void Character::use(int idx, ICharacter &target)
{
    if (idx < ITEMS_QUANTITY && this->_items[idx] != NULL)
        this->_items[idx]->use(target);
}

void Character::_initItems(void)
{
    for (int i = 0; i < ITEMS_QUANTITY; i++)
        this->_items[i] = NULL;
}