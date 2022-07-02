#include <iostream>       // std::cout
#include <stack.hpp>          // ft::stack
#include <vector.hpp>         // ft::vector
#include <deque>          // std::deque

int main ()
{
  std::deque<int> mydeque (3,100);         // deque with 3 elements
  ft::vector<int> myvector (2,200);        // vector with 2 elements

  ft::stack<int> first;                    // empty stack
  ft::stack<int, std::deque<int>> second (mydeque);         // stack initialized to copy of deque

  ft::stack<int,ft::vector<int> > third;   // empty stack using vector
  ft::stack<int,ft::vector<int> > fourth (myvector);

  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of second: " << second.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';

  return 0;
}