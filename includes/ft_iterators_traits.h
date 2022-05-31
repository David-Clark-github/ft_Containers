/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterators_traits.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:20:36 by dclark            #+#    #+#             */
/*   Updated: 2022/05/31 11:56:15 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATORS_TRAITS
#define FT_ITERATORS_TRAITS

#include <iterator>
#include <cstddef>

namespace ft {

	template	<class Iterator>
	struct		iterator_traits {
		using	difference_type		=	std::ptrdiff_t;
		using	value_type			=	Iterator;
		using	pointer				=	Iterator*;
		using	reference			=	Iterator&;
		using	iterator_category	=	std::random_access_iterator_tag;
	};

	template	<class T>
	struct		iterator_traits<T*> {

	};

	template	<class T>
	struct		iterator_traits<const T*> {

	};
};

#endif
