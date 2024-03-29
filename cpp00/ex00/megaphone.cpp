#include <iostream>

void print_upper(char ch)
{
    char upper = std::toupper(ch);
    std::cout << upper;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
        std::cout
            << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; i < argc; i++)
        {
            for (int j = 0; argv[i][j]; j++)
                print_upper(argv[i][j]);
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
