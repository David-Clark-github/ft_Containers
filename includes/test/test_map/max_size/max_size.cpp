#include <iostream>
#include <map.hpp>

int main ()
{
  int i;
  ft::map<int,int> mymap;

  if (mymap.max_size()>1000)
  {
    for (i=0; i<1000; i++) mymap[i]=0;
    std::cout << "The map contains 1000 elements.\n";
	std::cout << "mymap.maxsize() = " << mymap.max_size() << std::endl;
  }
  else std::cout << "The map could not hold 1000 elements.\n";

  return 0;
}
