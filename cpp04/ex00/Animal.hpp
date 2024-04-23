#ifndef ANIMAL_H
#define ANIMAL_H
#include <iostream>

class Animal
{
protected:
    std::string _type;

public:
    Animal();
    Animal(std::string);
    Animal(const Animal &);
    Animal &operator=(const Animal &);
    virtual ~Animal();

    std::string getType(void) const;

    virtual void makeSound(void) const;
};

#endif