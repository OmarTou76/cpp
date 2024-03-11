#ifndef ZOMBIE_H
# define ZOMBIE_H
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
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif