#pragma once
#include <iostream>

template <typename T>
class Array
{
private:
    T *content;
    unsigned int N;

public:
    Array()
    {
        this->N = 0;
        this->content = new T[this->N];
    }

    Array(unsigned int size)
    {
        this->N = size;
        this->content = new T[this->N];
    }

    Array(const Array &c)
    {
        this->N = c.size();
        this->content = new T[this->N];
        for (size_t i = 0; i < this->N; i++)
            this->content[i] = c.content[i];
        *this = c;
    }

    const Array &operator=(const Array &rhs)
    {
        if (this != &rhs)
        {
            delete[] this->content;
            this->N = rhs.size();
            this->content = new T[this->N];
            for (size_t i = 0; i < this->N; i++)
                this->content[i] = rhs.content[i];
        }
        return *this;
    }

    T &operator[](int index)
    {
        if (index < 0 || index > static_cast<int>(this->N))
            throw IndexOutOfBounds();
        return this->content[index];
    }

    ~Array()
    {
        delete[] this->content;
    }

    unsigned int size() const { return this->N; }

    class IndexOutOfBounds : public std::exception
    {
    public:
        virtual const char *what() const throw()
        {
            return "Index out of bounds !";
        }
    };
};
