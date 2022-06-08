/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:49:13 by dclark            #+#    #+#             */
/*   Updated: 2022/06/08 14:25:06 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
#define FT_VECTOR_H

#include <ft_vector_iterator.h>
#include <ft_reverse_iterator.h>

namespace ft {
	template<class T, class Alloc = std::allocator<T>>
	class vector {
		private:
			allocator	_alloc;
			pointer		_ptr;
			size_type	_capacity;
			size_type	_size;


		public:
			/*-------- [MEMBER_TYPES] --------*/
			typedef	T														value_type;
			typedef	Alloc													allocator_type;
			typedef	typename allocator_type::size_type						size_type;
			typedef	typename ft::iterator_traits<iterator>::difference_type	difference_type;			
			typedef	typename allocator_type::reference						reference
			typedef	typename allocator_type::const_reference				const_reference;
			typedef	typename allocator_type::pointer						pointer;
			typedef	typename allocator_type::const_pointer					const_pointer;
			typedef	ft::vector_iterator<value_type>							iterator;
			typedef	ft::vector_iterator<const value_type>					const_iterator;
			typedef	ft::reverse_iterator<iterator>							reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>					const_reverse_iterator;

			/*-------- [MEMBER FUNCTIONS] --------*/

			/*-------- Constructor / Destructor --------*/

			/* Mettre a jour les elements lorsqu'on y arrivera */
			
			// Default
			explicit vector (const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _ptr(NULL), _capacity(0), _size(0) {}

			// Fill
			explicit vector (size_type n, const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _ptr(), _capacity(), _size(n)

			// Range
			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type());

			// Copy
			vector (const vector &x) {
				//do something
			}

			// Destructor
			~vector ();

			// Operator Copy
			vector& operator= (const vector& x) {
				if (this != &x) {
					//do something
				}
				return (*this);
			}

			/*-------- Iterators --------*/
			// begin
			iterator begin() {
				//do something
			}

			const_iterator begin () {
				//do something
			}
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
