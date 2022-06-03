#include <ft_equal_lexico_comp.h>
#include <iostream>     // std::cout
#include <vector>       // std::vector

bool mypredicate (int i, int j) {
	return (i==j);
}

int main () {
	int myints[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100
	std::vector<int>myvector (myints,myints+5);     // myvector: 20 40 60 80 100

	std::cout <<  "Using default comparison:\n";
	if ( ft::equal (myvector.begin(), myvector.end(), myints) )
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";


	std::cout << "Using predicate comparison:\n";
	if ( ft::equal (myvector.begin(), myvector.end(), myints, mypredicate) )
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n\n";

	myvector[3]=81;   std::cout << "\nmyvector: 20 40 60 81 100\n\n";

	std::cout <<  "Using default comparison:\n";
	if ( ft::equal (myvector.begin(), myvector.end(), myints) )
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";


	std::cout << "using predicate comparison:\n";
	if ( ft::equal (myvector.begin(), myvector.end(), myints, mypredicate) )
		std::cout << "The contents of both sequences are equal.\n";
	else
		std::cout << "The contents of both sequences differ.\n";

	return 0;
}
