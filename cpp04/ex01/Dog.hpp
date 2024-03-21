#ifndef DOG_H
#define DOG_H
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain *_brain;

public:
    Dog();
    Dog(const Dog &);
    Dog &operator=(const Dog &);
    ~Dog();

    virtual void makeSound(void) const;
};

#endif