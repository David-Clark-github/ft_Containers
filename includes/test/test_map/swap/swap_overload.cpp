#include <map.hpp>
#include <iostream>
#include <algorithm>

int main()
{
	ft::map<char, int> foo, bar;
	foo['x'] = 100;
	foo['y'] = 200;

	bar['a'] = 11;
	bar['b'] = 22;
	bar['c'] = 33;

	ft::map<char, int>::iterator itf = foo.begin();
	ft::map<char, int>::iterator itb = bar.begin();

	std::cout << "foo\n";
	for (;itf != foo.end(); itf++)
		std::cout << itf->first << " => " << itf->second << std::endl;
	std::cout << std::endl;
	std::cout << "bar\n";
	for (;itb != bar.end(); itb++)
		std::cout << itb->first << " => " << itb->second << std::endl;

	ft::swap(foo, bar);

	itf = foo.begin();
	itb = bar.begin();

	std::cout << std::endl;
	std::cout << "foo\n";
	for (;itf != foo.end(); itf++)
		std::cout << itf->first << " => " << itf->second << std::endl;
	std::cout << std::endl;
	std::cout << "bar\n";
	for (;itb != bar.end(); itb++)
		std::cout << itb->first << " => " << itb->second << std::endl;
	return 0;
}
