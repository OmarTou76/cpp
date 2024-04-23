#ifndef DOG_H
#define DOG_H
#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog(const Dog &);
    Dog &operator=(const Dog &);
    ~Dog();

    void makeSound(void) const;
};

#endif