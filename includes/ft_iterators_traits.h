/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterators_traits.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:20:36 by dclark            #+#    #+#             */
/*   Updated: 2022/06/01 11:25:30 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATORS_TRAITS
#define FT_ITERATORS_TRAITS

#include <iterator>
#include <cstddef>

namespace ft {

	template	<class Iterator>
	struct		iterator_traits {
		typedef typename	Iterator::iterator_category	iterator_category;
		typedef	typename	Iterator::value_type		value_type;
		typedef	typename	Iterator::difference_type	difference_type;
		typedef	typename	Iterator::pointer			pointer;
		typedef	typename	Iterator::reference			reference;
	};

	template	<class T>
	struct		iterator_traits<T*> {
		typedef	random_access_iterator_tag	iterator_category;
		typedef	T							value_type;
		typedef	ptrdiff_t					difference_type;
		typedef	T*							pointer;
		typedef	T&							reference;
	};

	template	<class T>
	struct		iterator_traits<const T*> {
		typedef	random_access_iterator_tag	iterator_category;
		typedef	T							value_type;
		typedef	ptrdiff_t					difference_type;
		typedef	const	T*					pointer;
		typedef	const	T&					reference;
	};

};

#endif
