#include <iostream>
using namespace std;
class X {};
struct Y {
	using type = X;
};
template <class T>
void f(T) { // version générale
	cout << "f(T)" << endl;
}
template <class T>
void f(typename T::type) { // version plus « pointue »
	cout << "f(T::type)" << endl;
}
int main() {
	f<X>(X{});
	f<Y>(X{});
}
