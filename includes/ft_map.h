/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:51:52 by david             #+#    #+#             */
/*   Updated: 2022/06/28 11:25:48 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
#define FT_MAP_H

#include <ft_pair.h>

namespace ft {

	template < class Key,
		class T,
		class Compare = ft::less<Key>,
		class Alloc = allocator<pair<const Key,T>> >
	class map {
		public:
			/*-------- [MEMBER_TYPES] --------*/
			typedef typename 	Key											key_type;
			typedef typename 	T											mapped_type;
			typedef 			pair<const key_type, mapped_type>			value_type;
			typedef typename	Compare										key_compare;
			typedef typename	Alloc										allocator_type;
			typedef				allocator_type::reference					reference;
			typedef				allocator_type::const_reference				const_reference;
			typedef				allocator_type::pointer						pointer;
			typedef				allocator_type::const_pointer				const_pointer;
			typedef				/*Something*/								iterator;
			typedef				/*Something*/								const_iterator;
			typedef				ft::reverse_iterator<iterator>				reverse_iterator;
			typedef				ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef				ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef				size_t										size_type;

			/*-------- [MEMBER CLASSES] --------*/
			class value_compare {
				
			}

		private:
	};

};

#endif
