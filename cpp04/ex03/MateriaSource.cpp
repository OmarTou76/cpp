#include "MateriaSource.hpp"

MateriaSource::MateriaSource() { this->_initMaterias(); }

MateriaSource::MateriaSource(const MateriaSource &copy) { *this = copy; }
MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
    if (this != &rhs)
    {
        for (int i = 0; i < MATERIAS_QUANTITY; i++)
        {
            if (this->_materias[i] != NULL)
                delete this->_materias[i];
            this->_materias[i] = rhs._materias[i]->clone();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < MATERIAS_QUANTITY; i++)
    {
        if (this->_materias[i] != NULL)
            delete this->_materias[i];
    }
}

void MateriaSource::_initMaterias()
{
    for (int i = 0; i < MATERIAS_QUANTITY; i++)
        this->_materias[i] = NULL;
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (!m)
        return;
    for (int i = 0; i < MATERIAS_QUANTITY; i++)
    {
        if (!this->_materias[i])
        {
            this->_materias[i] = m;
            break;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = MATERIAS_QUANTITY - 1; i >= 0; i--)
        if (this->_materias[i] && this->_materias[i]->getType() == type)
            return this->_materias[i]->clone();
    return 0;
}