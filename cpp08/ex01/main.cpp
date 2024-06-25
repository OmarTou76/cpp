#include "Span.h"
#include <iostream>

int main()
{
  Span sp = Span(5);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
  sp.status();

  std::cout << std::endl
            << "---------------" << std::endl;

  std::list<int> l;
  for (int i = 0; i < 103; i++)
    l.push_back(i);

  std::list<int>::const_iterator start = l.begin();
  std::list<int>::const_iterator end = l.end();
  Span possible = Span(200);
  Span impossible = Span(20);
  try
  {
    possible.addRange(start, end);
    impossible.addRange(start, end);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }

  possible.status();
  impossible.status();

  return 0;
}
