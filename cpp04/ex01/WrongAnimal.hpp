#ifndef WRONG_ANIMAL_H
#define WRONG_ANIMAL_H
#include <iostream>

class WrongAnimal
{
protected:
    std::string _type;

public:
    WrongAnimal();
    WrongAnimal(std::string);
    WrongAnimal(const WrongAnimal &);
    WrongAnimal &operator=(const WrongAnimal &);
    ~WrongAnimal();

    std::string getType(void) const;

    void makeSound(void) const;
};

#endif