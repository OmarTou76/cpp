#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <iostream>

class Zombie
{

private:
  std::string _name;

public:
  Zombie(void);
  Zombie(std::string);
  ~Zombie(void);
  void annonce(void);
  void setZombieName(std::string);
};

Zombie*    zombieHorde( int N, std::string name );
#endif
