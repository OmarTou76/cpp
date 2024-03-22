#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}
Ice::Ice(const Ice &copy) : AMateria("Ice") { *this = copy; }
Ice &Ice::operator=(const Ice &rhs)
{
    if (this != &rhs)
        this->_type = rhs.getType();
    return *this;
}
Ice::~Ice() {}

AMateria *Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
