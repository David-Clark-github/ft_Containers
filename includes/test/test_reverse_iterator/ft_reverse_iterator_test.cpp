// reverse_iterator example
#include <iostream>     // std::cout
#include <iterator>     // std::reverse_iterator
#include <vector>       // std::vector
#include <ft_reverse_iterator.h>

int main ()
{
	std::cout << "Constructor de reverse_iterator\n";
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef std::vector<int>::iterator iter_type;
		// ? 0 1 2 3 4 5 6 7 8 9 ?
		iter_type from (myvector.begin());                     //   ^
		//         ------>
		iter_type until (myvector.end());                      //                       ^
		//
		std::reverse_iterator<iter_type> rev_until (from);     // ^
		//         <------
		std::reverse_iterator<iter_type> rev_from (until);     //                     ^

		std::cout << "myvector:";
		while (rev_from != rev_until)
			std::cout << ' ' << *rev_from++;
		std::cout << '\n';
	}
	std::cout << "\nbase\n";
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef std::vector<int>::iterator iter_type;

		ft::reverse_iterator<iter_type> rev_end (myvector.begin());
		ft::reverse_iterator<iter_type> rev_begin (myvector.end());

		std::cout << "myvector:";
		for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
	std::cout << "\noperator*()\n";
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		typedef std::vector<int>::iterator iter_type;
		// ? 9 8 7 6 5 4 3 2 1 0 ?
		iter_type from (myvector.begin());                     //   ^
		//         ------>
		iter_type until (myvector.end());                      //                       ^
		//
		ft::reverse_iterator<iter_type> rev_until (from);
		//         <------
		ft::reverse_iterator<iter_type> rev_from (until);

		std::cout << "myvector:";
		while (rev_from != rev_until)
			std::cout << ' ' << *rev_from++;
		std::cout << '\n';
	}
	// rev_it ne peut pas recevoir un std::reverse, il attend un ft::reverse
	// attendre que vector soit finis :)
	/*
	std::cout << "\noperator + ()\n";
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

		typedef std::vector<int>::iterator iter_type;

		ft::reverse_iterator<iter_type> rev_it;

		rev_it = myvector.rbegin() + 3;

		std::cout << "The fourth element from the end is: " << *rev_it << '\n';

	}
	*/
	return 0;
}
