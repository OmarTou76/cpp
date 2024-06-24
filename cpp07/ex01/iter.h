#pragma once
#include <iostream>

template <typename T, typename N, typename Fn>
void iter(T tab[], N size, Fn func)
{
    for (int i = 0; i < size; i++)
        func(tab[i]);
}

template <typename T>
void printElement(const T &element)
{
    std::cout << element << std::endl;
}
