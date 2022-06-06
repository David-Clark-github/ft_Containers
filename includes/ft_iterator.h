/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterator.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:04:55 by david             #+#    #+#             */
/*   Updated: 2022/06/06 10:42:03 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATOR_H
#define FT_ITERATOR_H

#include <cstddef>

typedef	std::ptrdiff_t	ptrdiff_t;

namespace ft {

	template <class Category, class T, class Distance = ptrdiff_t,
				class Pointer = T*, class Reference = T&> 
	class iterator {
		typedef	T			value_type;
		typedef	Distance	difference_type;
		typedef	Pointer		pointer;
		typedef	Reference	reference;
		typedef	Category	iterator_category;
	};
};

#endif
