#include <set.hpp>
#include <iostream>

int main()
{
	int a[] = {1, 2, 3};
    ft::set<int> alice;//{1, 2, 3};
	alice.insert(a, a+3);
	int b[] = {7, 8, 9, 10};	
    ft::set<int> bob;//{7, 8, 9, 10};
	bob.insert(b, b+4);
	int	e[] = {1, 2, 3};
    ft::set<int> eve;//{1, 2, 3};
	eve.insert(e, e+3);
 
    std::cout << std::boolalpha;
 
    // Compare non equal containers
    std::cout << "alice == bob returns " << (alice == bob) << '\n';
    std::cout << "alice != bob returns " << (alice != bob) << '\n';
    std::cout << "alice <  bob returns " << (alice < bob) << '\n';
    std::cout << "alice <= bob returns " << (alice <= bob) << '\n';
    std::cout << "alice >  bob returns " << (alice > bob) << '\n';
    std::cout << "alice >= bob returns " << (alice >= bob) << '\n';
 
    std::cout << '\n';
 
    // Compare equal containers
    std::cout << "alice == eve returns " << (alice == eve) << '\n';
    std::cout << "alice != eve returns " << (alice != eve) << '\n';
    std::cout << "alice <  eve returns " << (alice < eve) << '\n';
    std::cout << "alice <= eve returns " << (alice <= eve) << '\n';
    std::cout << "alice >  eve returns " << (alice > eve) << '\n';
    std::cout << "alice >= eve returns " << (alice >= eve) << '\n';
}
