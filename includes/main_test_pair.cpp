#include <ft_pair.h>
#include <iostream>

int main(void) {
  ft::pair <int,int> foo;

  //ft::pair <double,char> bar1;
  ft::pair <int,int> bar1;
  std::pair <int,int> bar2;

  ft::pair<int, int> toto(654, 456);
  ft::pair <int, int> cp = toto;

  foo = ft::make_pair (10,20);
  bar1 = ft::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>
  bar2 = std::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

  //std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
  std::cout << "bar1: " << bar1.first << ", " << bar1.second << '\n';
  std::cout << "bar2: " << bar2.first << ", " << bar2.second << '\n';
  //std::cout << "toto: " << toto.first << ", " << toto.second << '\n';
  //std::cout << "cp: " << cp.first << ", " << cp.second << '\n';

       return 0;
}

