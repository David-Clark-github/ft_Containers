#include <type_traits>
#include <stdio.h>

/* ---- Substitution Failure Is Not An Error ---- */

template <typename T>
void	print(typename std::enable_if<std::is_floating_point<T>::value, T>::type n) {
	printf("%lf\n", (double)n);
}

template <typename T>
void	print(typename std::enable_if<std::is_integral<T>::value, T>::type n) {
	printf("%ld\n", (long int)n);
}

int main() {
	print<int>(42);
	print<float>(42);
	print<char>('*');
	print<double>(42);
}
