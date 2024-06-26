#include <iostream>
#include "iter.h"

void printFirstCharToUpper(std::string &str)
{
    char c = std::toupper(str[0]);
    std::cout << c << std::endl;
}

int main(void)
{
    float arr[] = { 1.5f, 2.1f, 3.2f, 4.9f, 5.1f, 6.6f, 7.8f };
    std::string strs[] = {
        "A -> Hello",
        "b -> World",
        "c -> Hello",
        "d -> Hello",
    };
    iter(arr, 7, printElement);
    std::cout << std::endl;
    iter(strs, 4, printElement);
    std::cout << std::endl;
    iter(strs, 4, printFirstCharToUpper);

    return 0;
}
