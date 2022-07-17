#include <iostream>
#include <vector.hpp>

int main ()
{
  ft::vector<int> first;
  ft::vector<int> second;
  ft::vector<int> third;

  first.assign (7,100);             // 7 ints with a value of 100

  ft::vector<int>::iterator it;
  it=first.begin()+1;

  second.assign (it,first.end()-1); // the 5 central values of first

  int myints[] = {1776,7,4};
  third.assign (myints,myints+3);   // assigning from array.

  std::cout << "Size of first: " <<  (first.size()) << '\n';
  std::cout << "Size of second: " <<  (second.size()) << '\n';
  std::cout << "Size of third: " <<  (third.size()) << '\n';
  return 0;
}
