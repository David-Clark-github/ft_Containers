/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:49:13 by dclark            #+#    #+#             */
/*   Updated: 2022/06/06 11:40:02 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
#define FT_VECTOR_H

#include <>

namespace ft {
	template<class T, class Alloc = std::allocator<T>>
	class vector {
		public:
			/*-------- Member_type --------*/
			typedef	T											value_type;
			typedef	Alloc										allocator_type;
			typedef	typename allocator_type::reference			reference
			typedef	typename allocator_type::const_reference	const_reference;
			typedef	typename allocator_type::pointer			pointer;
			typedef	typename allocator_type::const_pointer		const_pointer;
			//iterator
			//const_iterator
			//typedef ft::iterator_traits<A_VOIR>				difference_type
			std::reverse_iterator<iterator>			reverse_iterator
			std::reverse_iterator<const_iterator>	const_reverse_iterator
			typedef signed int							difference_type
			typedef unsigned int						size_type

			// Constructor (Surcharge de constructor ?)
			// Destructor (Surcharge de destructor ?)
			// Operator =

			/*-------- Iterators --------*/
			// begin
			// end
			// rbegin
			// rend

			/*-------- Capacity --------*/
			// size
			// max_size
			// resize
			// capacity
			// reserve

			/*-------- Element_access --------*/
			// Operator []
			// at
			// front
			// back

			/*-------- Modifiers --------*/
			// assign
			// push_back
			// pop_back
			// insert
			// erase
			// swap
			// clear

			/*-------- Allocator --------*/
			// get_allocator

			/*-------- Non-member function overlords --------*/
			// Operator ==
			// Operator !=
			// Operator <
			// Operator <=
			// Operator >
			// Operator >=
			// swap			
	};
}

#endif
