/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:51:52 by david             #+#    #+#             */
/*   Updated: 2022/06/19 17:18:17 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
#define FT_MAP_H

#include <ft_pair.h>

namespace ft {

	template < class Key,
		class T,
		class Compare = less<Key>,
		class Alloc = allocator<pair<const Key,T>> >
	class map {
		public:
			/*-------- Member types --------*/
			typedef typename 	Key									key_type;
			typedef typename 	T									mapped_type;
			typedef 			pair<const key_type, mapped_type>	value_type;
			typedef typename	Compare								key_compare;
			typedef				/*Something*/						value_compare;
			typedef typename	Alloc								allocator_type;
			typedef				allocator_type::reference			reference;
			typedef				allocator_type::const_reference		const_reference;
			typedef				allocator_type::pointer				pointer;
			typedef				allocator_type::const_pointer		const_pointer;
			typedef

		private:
	};

};

#endif
