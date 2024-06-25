#include <iostream>
#include "MutantStack.h"

/* int main(void)
{
  MutantStack<int> st;

  st.push(39);
  st.push(239);
  st.push(339);
  st.push(349);
  std::cout << *st.begin() << std::endl;
  std::cout << *std::prev(st.end()) << std::endl;
} */

int main()
{
  MutantStack<int> mstack;
  mstack.push(5);
  mstack.push(17);
  std::cout << mstack.top() << std::endl;
  mstack.pop();
  std::cout << mstack.size() << std::endl;
  mstack.push(3);
  mstack.push(5);
  mstack.push(737); //[...] mstack.push(0);
  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();
  ++it;
  --it;
  while (it != ite)
  {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);

  return 0;
}