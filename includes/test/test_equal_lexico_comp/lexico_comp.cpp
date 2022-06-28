#include <iostream>     // std::cout, std::boolalpha
#include <algorithm>    // std::lexicographical_compare
#include <cctype>       // std::tolower
#include <equal_lexico_comp.hpp>

// a case-insensitive comparison function:
bool mycomp (char c1, char c2) {
	return ( std::tolower(c1) < std::tolower(c2) );
}

int main () {
	char foo[]="Apple";
	char bar[]="apartment";

	std::cout << std::boolalpha;

	std::cout << "\n-------- FT --------\n\n";

	std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

	std::cout << "Using default comparison (operator<): ";
	std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9);
	std::cout << '\n';

	std::cout << "Using mycomp as comparison object: ";
	std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
	std::cout << '\n';

	std::cout << "\n-------- STD --------\n\n";
	std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

	std::cout << "Using default comparison (operator<): ";
	std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9);
	std::cout << '\n';

	std::cout << "Using mycomp as comparison object: ";
	std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
	std::cout << '\n';

return 0;
}
