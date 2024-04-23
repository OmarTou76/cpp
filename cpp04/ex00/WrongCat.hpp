#ifndef WRONG_CAT_H
#define WRONG_CAT_H
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    WrongCat(const WrongCat &);
    WrongCat &operator=(const WrongCat &);
    ~WrongCat();

    void makeSound(void) const;
};

#endif