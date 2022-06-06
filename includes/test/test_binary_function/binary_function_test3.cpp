#include <iostream>
#include <functional>
#include <algorithm>

#include <ft_binary_function.h>
#include <ft_pair.h>

#define NC "\e[0m"
#define RED "\e[0;31m"

int main() {

	/*equal_to*/
	std::cout << RED "EQUAL_TO\n" NC;
	{
		std::pair<int*,int*> ptiter;
		int foo[]={10,20,30,40,50};
		int bar[]={10,20,40,80,160};
		ptiter = std::mismatch (foo, foo+5, bar, ft::equal_to<int>());
		std::cout << "First mismatching pair is: " << *ptiter.first;
		std::cout << " and " << *ptiter.second << '\n';
	}

	/*not_equal_to*/
	std::cout << RED "\nNOT_EQUAL_TO\n" NC;
	{
		int numbers[]={10,10,10,20,20};
		int* pt = std::adjacent_find (numbers, numbers+5, ft::not_equal_to<int>()) +1;
		std::cout << "The first different element is " << *pt << '\n';
	}

	/*less */
	std::cout << RED "\nLESS\n" NC;
	{
		int foo[]={10,20,5,15,25};
		int bar[]={15,10,20};
		std::sort (foo, foo+5, ft::less<int>());  // 5 10 15 20 25
		std::sort (bar, bar+3, ft::less<int>());  //   10 15 20
		if (std::includes (foo, foo+5, bar, bar+3, ft::less<int>()))
			std::cout << "foo includes bar.\n";
	}

	/*less_equal*/
	std::cout << RED "\nLESS_EQUAL\n" NC;
	{
		int numbers[]={25,50,75,100,125};
		int cx = std::count_if (numbers, numbers+5, std::bind2nd(ft::less_equal<int>(),100));
		std::cout << "There are " << cx << " elements lower than or equal to 100.\n";
	}

	/*greater*/
	std::cout << RED "\nGREATER\n" NC;
	{
		int numbers[]={20,40,50,10,30};
		std::sort (numbers, numbers+5, ft::greater<int>());
		for (int i=0; i<5; i++)
			std::cout << numbers[i] << ' ';
		std::cout << '\n';
	}

	/*greater_equal*/
	std::cout << RED "\nGREATER_EQUAL\n" NC;
	{
		int numbers[]={20,-30,10,-40,0};
		int cx = std::count_if (numbers, numbers+5, std::bind2nd(ft::greater_equal<int>(),0));
		std::cout << "There are " << cx << " non-negative elements.\n";
	}

	return 0;

};
