/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:59:18 by dclark            #+#    #+#             */
/*   Updated: 2022/05/25 11:01:03 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_iterators_test.h>

int main(void) {
	Integers integers;


/*
	std::fill(integers.begin(), integers.end(), 5);
	for (auto i : integers) {
		std::cout << i << std::endl;
	}
*/
	auto it = integers.begin();
	auto end = integers.end();
	int	i	=	0;
	for (; it != end; it++, i++) {
		*it = i;
	}
	for (auto i : integers) {
		std::cout << i << std::endl;
	}
}
