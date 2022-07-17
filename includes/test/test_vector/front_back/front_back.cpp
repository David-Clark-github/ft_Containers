#include <iostream>
#include <vector.hpp>

int main ()
{
	std::cout << "back" << std::endl;
	{
		ft::vector<int> myvector;

		myvector.push_back(10);

		while (myvector.back() != 0)
		{
			myvector.push_back ( myvector.back() -1 ); // <-
		}

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size() ; i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}

	std::cout << std::endl << "front" << std::endl;
	{
		ft::vector<int> myvector;

		myvector.push_back(78);
		myvector.push_back(16);

		// now front equals 78, and back 16

		myvector.front() -= myvector.back(); // <-

		std::cout << "myvector.front() is now " << myvector.front() << '\n';

	}

	return 0;
}
