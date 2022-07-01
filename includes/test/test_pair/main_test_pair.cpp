#include <pair.hpp>
#include <iostream>

int main(void) {
  ft::pair <int,int> foo;

  ft::pair <int,int> bar1;
  std::pair <int,int> bar2;

  ft::pair<int, int> toto(654, 456);
  ft::pair <int, int> cp = toto;

  foo = ft::make_pair (10,20);
  bar1 = ft::make_pair (10.5,'A'); 
  bar2 = std::make_pair (10.5,'A');

  std::cout << "bar1: " << bar1.first << ", " << bar1.second << '\n';
  std::cout << "bar2: " << bar2.first << ", " << bar2.second << '\n';

       return 0;
}

