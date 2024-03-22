#ifndef ICE_H
#define ICE_H
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
private:
public:
    Ice();
    Ice(const Ice &);
    ~Ice();
    Ice &operator=(const Ice &);
    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif