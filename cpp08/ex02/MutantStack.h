#pragma once
#include <iostream>
#include <algorithm>
#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack<T>() {}
    ~MutantStack<T>() {}
    MutantStack<T>(MutantStack const &cp) { *this = cp; }
    MutantStack<T> &operator=(MutantStack const &rhs)
    {
        if (this != &rhs)
            std::stack<T>::operator=(rhs);
        return *this;
    }
    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
};