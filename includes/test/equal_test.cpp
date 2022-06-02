#include <ft_equal_lexico_comp.h>
#include <iostream>     // std::cout
#include <vector>       // std::vector

bool mypredicate (int i, int j) {
	return (i==j);
}

int main () {
	int myints[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100
	std::vector<int>myvector (myints,myints+5);     // myvector: 20 40 60 80 100

	std::cout <<  "Using default comparison:" << std::endl;
	if ( ft::equal (myvector.begin(), myvector.end(), myints) )
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";


	std::cout << "Using predicate comparison:" << std::endl;
	if ( ft::equal (myvector.begin(), myvector.end(), myints, mypredicate) )
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";

	myvector[3]=81;   std::cout << std::endl << "myvector: 20 40 60 81 100" << std::endl << std::endl;

	std::cout <<  "Using default comparison:" << std::endl;
	if ( ft::equal (myvector.begin(), myvector.end(), myints) )
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";


	std::cout << "using predicate comparison:" << std::endl;
	if ( ft::equal (myvector.begin(), myvector.end(), myints, mypredicate) )
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";

	return 0;
}
