/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral_test.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:47:27 by dclark            #+#    #+#             */
/*   Updated: 2022/06/02 13:49:09 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_is_integral.h>
#include <iostream>

int main() {
	std::cout << std::boolalpha;
	std::cout << "is_integral:" << std::endl;
	std::cout << "char: " << ft::is_integral<char>::value << std::endl;
	std::cout << "int: " << ft::is_integral<int>::value << std::endl;
	std::cout << "float: " << ft::is_integral<float>::value << std::endl;
	return 0;
}
