/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:51:52 by david             #+#    #+#             */
/*   Updated: 2022/07/03 22:19:04 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <pair.hpp>
#include <binary_function.hpp>
#include <map_iterator.hpp>
#include <map_node.hpp>

namespace ft {

	template < class Key,
		class T,
		class Compare = ft::less<Key>,
		class Alloc = allocator<ft::pair<const Key,T>> >
	class map {
		public:
			/*-------- [MEMBER_TYPES] --------*/
			typedef typename 	Key												key_type;
			typedef typename 	T												mapped_type;
			typedef 			ft::pair<const key_type, mapped_type>			value_type;
			typedef typename	Compare											key_compare;
			typedef typename	Alloc											allocator_type;
			typedef				allocator_type::reference						reference;
			typedef				allocator_type::const_reference					const_reference;
			typedef				allocator_type::pointer							pointer;
			typedef				allocator_type::const_pointer					const_pointer;
			typedef				map_iterator<value_type, ft::Node<value_type>>	iterator;
			typedef				map_iterator<const value_type, ft::Node<value_type>>	const_iterator;
			typedef				ft::reverse_iterator<iterator>					reverse_iterator;
			typedef				ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef				ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef				size_t											size_type;

			/*-------- [MEMBER CLASSES] --------*/
			// Value Compare
			class value_compare : ft::binary_function<value_type, value_type, bool>
			{
				friend class map;

				protected:
					key_compare	comp;
					value_compare(key_compare c) : comp(c) {}

				public:
					bool operator()(const value_type& lhs, const value_type& rhs) const {
						return (comp(lhs.first, rhs.first));
					}
			}

			/*-------- [MEMBER FUNCTIONS] --------*/

			// Constructor / Destructor
			explicit map(const key_compare &comp = key_compare(),
						const allocator_type &alloc = allocator_type()) {}
		private:
	};

};

#endif
