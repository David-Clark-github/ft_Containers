#include <iostream>
#include <map.hpp>

int main ()
{
  ft::map<char,int> mymap;

  mymap['x'] = 100;
  mymap['y'] = 200;
  mymap['z'] = 300;

  // show content:
  std::cout << "const_reverse_iterator\n";
  ft::map<char,int>::const_reverse_iterator rbit1 = mymap.rbegin();
  ft::map<char,int>::const_reverse_iterator reit1 = mymap.rend();
  for (; rbit1 != reit1; ++rbit1)
    std::cout << rbit1->first << " => " << rbit1->second << '\n';

  std::cout << "\nreverse_iterator\n";
  ft::map<char,int>::reverse_iterator rbit2 = mymap.rbegin();
  ft::map<char,int>::reverse_iterator reit2 = mymap.rend();
  for (; rbit2 != reit2; ++rbit2)
    std::cout << rbit2->first << " => " << rbit2->second << '\n';

  return 0;
}
