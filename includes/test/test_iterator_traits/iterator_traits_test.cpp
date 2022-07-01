#include <iostream>					// std::cout
#include <iterator_traits.hpp>		// std::iterator_traits
#include <typeinfo>					// typeid
#include <iterator>
#include <vector>
#include <list>
#include <array>
#include <string>

template<class BidirIt>
void my_reverse(BidirIt first, BidirIt last)
{
	typename ft::iterator_traits<BidirIt>::difference_type n = std::distance(first, last);
	for (--n; n > 0; n -= 2) {
		typename ft::iterator_traits<BidirIt>::value_type tmp = *first;
		*first++ = *--last;
		*last = tmp;
	}
}


int main()
{
	std::cout << "cplusplus.com exemple\n";
	{
		typedef ft::iterator_traits<int*> traits;
		if (typeid(traits::iterator_category)==typeid(std::random_access_iterator_tag))
			std::cout << "int* is a random-access iterator";
	}
	std::cout << "\n\ncppreference.com exemple\n";
	{

		std::vector<int> v{1, 2, 3, 4, 5};
		my_reverse(v.begin(), v.end());
		for (int n : v) {
			std::cout << n << ' ';
		}
		std::cout << '\n';

		std::list<int> l{1, 2, 3, 4, 5};
		my_reverse(l.begin(), l.end());
		for (int n : l) {
			std::cout << n << ' ';
		}
		std::cout << '\n';

		int a[] = {1, 2, 3, 4, 5};
		my_reverse(a, a + 5);
		for (int n : a) {
			std::cout << n << ' ';
		}
		std::cout << '\n';

	}
	return 0;
}
