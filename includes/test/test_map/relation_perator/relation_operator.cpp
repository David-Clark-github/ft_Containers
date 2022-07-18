#include <iostream>
#include <map.hpp>

int main()
{
	{
		ft::map<int, char> alice;
		alice.insert(ft::pair<int, char>(1, 'a'));
		alice.insert(ft::pair<int, char>(2, 'b'));
		alice.insert(ft::pair<int, char>(3, 'c'));
		//{{1, 'a'}, {2, 'b'}, {3, 'c'}};
		ft::map<int, char> bob;
		bob.insert(ft::pair<int, char>(7, 'Z'));
		bob.insert(ft::pair<int, char>(8, 'Y'));
		bob.insert(ft::pair<int, char>(9, 'X'));
		bob.insert(ft::pair<int, char>(10, 'W'));
		//{{7, 'Z'}, {8, 'Y'}, {9, 'X'}, {10, 'W'}};
		ft::map<int, char> eve;
		eve.insert(ft::pair<int, char>(1, 'a'));
		eve.insert(ft::pair<int, char>(2, 'b'));
		eve.insert(ft::pair<int, char>(3, 'c'));
		//{{1, 'a'}, {2, 'b'}, {3, 'c'}};

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
	{
		ft::map<char,int> foo,bar;
		foo['a']=100;
		foo['b']=200;
		bar['a']=10;
		bar['z']=1000;

		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

	}
	return 0;
}
