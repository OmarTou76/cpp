#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP
#include "IMateriaSource.hpp"
#define MATERIAS_QUANTITY 4

class MateriaSource : public IMateriaSource
{
private:
    AMateria *_materias[MATERIAS_QUANTITY];
    void _initMaterias();

public:
    MateriaSource();
    MateriaSource(const MateriaSource &);
    MateriaSource &operator=(const MateriaSource &);
    ~MateriaSource();

    void learnMateria(AMateria *);
    AMateria *createMateria(std::string const &type);
};

#endif