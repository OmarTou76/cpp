#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}
Cure::Cure(const Cure &copy) : AMateria("cure") { *this = copy; }
Cure &Cure::operator=(const Cure &rhs)
{
    if (this != &rhs)
        this->_type = rhs.getType();
    return *this;
}
Cure::~Cure() {}

AMateria *Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}