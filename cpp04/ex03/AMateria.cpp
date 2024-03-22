#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const &type) : _type(type) {}
AMateria::AMateria(const AMateria &copy)
{
    *this = copy;
}
AMateria::~AMateria() {}
AMateria &AMateria::operator=(const AMateria &rhs)
{
    if (this != &rhs)
        this->_type = rhs.getType();
    return *this;
}
std::string const &AMateria::getType() const
{
    return this->_type;
}
void AMateria::use(ICharacter &target)
{
    std::cout << "* " << this->_type << " use " << target.getName() << " *" << std::endl;
}