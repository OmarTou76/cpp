#ifndef CAT_H
#define CAT_H
#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
public:
    Cat();
    Cat(const Cat &);
    Cat &operator=(const Cat &);
    ~Cat();

    virtual void makeSound(void) const;
};

#endif