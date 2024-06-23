#include <iostream>
#include "iter.h"

void printFirstCharToUpper(std::string &str)
{
    char c = std::toupper(str[0]);
    std::cout << c << std::endl;
}

int main(void)
{
    int arr[] = {4, 5, 6, 7, 1, 2, 3};
    std::string strs[] = {
        "A -> Hello",
        "b -> World",
        "c -> Hello",
        "d -> Hello",
    };
    iter(arr, 7, printElement<int>);
    std::cout << std::endl;
    iter(strs, 4, printElement<std::string>);
    std::cout << std::endl;
    iter(strs, 4, printFirstCharToUpper);

    return 0;
}