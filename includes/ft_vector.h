/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:49:13 by dclark            #+#    #+#             */
/*   Updated: 2022/05/23 15:19:55 by dclark           ###   ########.fr       */
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
			typedef	T										_element_type
			typedef	std::allocator::reference				_reference_to_element
			typedef	std::allocator::const_reference			_reference_to_const_reference
			typedef	std::allocator::pointer					_pointer_to_element
			typedef	std::allocator::const_pointer			_pointer_to_const_element
			//iterator
			//cosnt_iterator
			//typedef ft::iterator_traits<A_VOIR>								difference_type
			std::reverse_iterator<iterator>			reverse_iterator
			std::reverse_iterator<const_iterator>	const_reverse_iterator
			signed int							difference_type
			unsigned int							size_type

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
