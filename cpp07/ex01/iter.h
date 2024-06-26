#pragma once
#include <iostream>

template <typename T>
void iter(T tab[], int N, void (func)(T&))
{
    for (int i = 0; i < N; i++)
        func(tab[i]);
}

template <typename T>
void printElement(T &element)
{
    std::cout << element << std::endl;
}
