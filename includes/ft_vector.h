/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:49:13 by dclark            #+#    #+#             */
/*   Updated: 2022/05/18 16:33:40 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <>

namespace ft {
	template<class T, class Alloc std::allocator<T>>
	class vector {
		public:
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

			/*-------- Member_type --------*/
			T										value_type				
			std::allocator::value_type				allocator_type			
			std::allocator::reference				reference
			std::allocator::const_reference			const_reference
			std::allocator::pointer					pointer
			std::allocator::const_pointer			const_pointer
			//iterator
			//cosnt_iterator
			signed int								difference_type
			std::reverse_iterator<iterator>			reverse_iterator
			std::reverse_iterator<const_iterator>	const_reverse_iterator
			signed int							difference_type
			unsigned int							size_type
	};
}
