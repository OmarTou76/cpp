#include <iostream>
#include "RPN.h"

int main(int argc, char **argv)
{
  if (argc == 2)
  {
    try
    {
      std::string str = argv[1];
      RPN rpn(str);
      std::cout << rpn.getResult() << std::endl;
    }
    catch (const std::exception &e)
    {
      std::cerr << "Error: " << e.what() << std::endl;
    }
  }
  return 0;
}