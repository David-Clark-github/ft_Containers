/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:20:36 by dclark            #+#    #+#             */
/*   Updated: 2022/06/28 11:45:19 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATOR_TRAITS_HPP
#define FT_ITERATOR_TRAITS_HPP

#include <iterator>
#include <stddef.h>

namespace ft {

	template	<class Iterator>
	struct		iterator_traits {
		typedef	typename	Iterator::difference_type	difference_type;
		typedef	typename	Iterator::value_type		value_type;
		typedef	typename	Iterator::pointer			pointer;
		typedef	typename	Iterator::reference			reference;
		typedef typename	Iterator::iterator_category	iterator_category;
	};

	template	<class T>
	struct		iterator_traits<T*> {
		typedef	ptrdiff_t						difference_type;
		typedef	T								value_type;
		typedef	T*								pointer;
		typedef	T&								reference;
		typedef	std::random_access_iterator_tag	iterator_category;
	};

	template	<class T>
	struct		iterator_traits<const T*> {
		typedef			ptrdiff_t						difference_type;
		typedef			T								value_type;
		typedef	const	T*								pointer;
		typedef	const	T&								reference;
		typedef			std::random_access_iterator_tag	iterator_category;
	};

};

#endif
