/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:49:13 by dclark            #+#    #+#             */
/*   Updated: 2022/06/10 18:15:37 by dclark           ###   ########.fr       */
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
			typedef	typename ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef	typename allocator_type::size_type						size_type;
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
				// Do something about other thing
			}

			// Destructor
			~vector ();

			// Operator Copy
			vector& operator= (const vector& x) {
				if (this != &x) {
					//Copier chaque élément de x dans vector(this)
				}
				return (*this);
			}

			/*-------- Iterators --------*/
			// begin
			iterator begin() {
				return (iterator(this->_current));
			}

			const_iterator begin () const {
				return (const_iterator(this->_current));
			}

			// end
			iterator end() {
				return (iterator(this->_current + size()));
			}

			const_iterator end() const {
				return (const_iterator(this->_current + size()));
			}

			// rbegin
			reverse_iterator rbegin() {
				return (reverse_iterator(this->_current + size() - 1));
			}

			const_reverse_iterator rbegin() const {
				return (const_reverse_iterator(this->_current + size() - 1));
			}

			// rend
			reverse_iterator rend() {
				return (reverse_iterator(this->_current - 1));
			}

			const_reverse_iterator rend() const {
				return (const_reverse_iterator(this->_current - 1));
			}

			/*-------- Capacity --------*/
			// size
			size_type	size() const {
				return (this->_size);
			}

			// max_size
			size_type	max_size() const {
				return (std::numeric_limits<difference_type>::max());
			}

			// resize
			void	resize(size_type n, value_type val = value_type()) {
				if (n < size()) {
					while (n < size()) {
						_alloc.destroy(--end());
						--_size;
					}
				}
				if (n > capacity()) {
					if ((capacity() * 2) >= n)
						reserve(capacity() * 2);
					reserve(n);
				}
				if (n > size()) {
					while (n > size()) {
						_alloc.construct(end(), val);
						_size++;
					}
				}
			}

			// capacity
			size_type	capacity() const {
				return (this->_capacity);
			}

			// empty
			bool empty() const {
				if (size()) // if isn't 0, it return false
					return (false);
				return (true);
			}

			// reserve
			void reserve (size_type n) {

				if (n > max_size())
					throw std::length_error("vector::reserve");

				if (n > capacity()) {
					pointer		oldB1 = begin();
					pointer		oldB2 = begin();
					pointer		oldE = end();
					size_type	oldC = capacity();

					_ptr = _alloc.allocate(n);
					_capacity = n;
					pointer	tmp = _ptr;
					while (tmp != oldE) {
						_alloc.construct(tmp, *oldB1);
						tmp++;
						oldB1++;
					}
					_alloc.deallocate(oldB2, oldC);
				}
			}

			/*-------- Element_access --------*/
			// Operator []
			reference	operator[](size_type n) {
				return *(begin() + n);
			}

			const_reference	operator[](size_type n) const {
				return *(begin() + n)
			}

			// at
			reference at (size_type n) {
				if !(n < size())
					throw std::out_of_range("vector::range_check");
				return *(begin() + n);
			}

			const_reference at (size_type n) const {
				if !(n < size())
					throw std::out_of_range("vector::range_check");
				return *(begin() + n);
			}

			// front
			reference front() {
				return *(begin());
			}

			const_reference front() const {
				return *(begin());
			}

			// back
			reference back() {
				return *(end() - 1);
			}

			const_reference back() const {
				return *(end() - 1);
			}

			/*-------- Modifiers --------*/
			// assign
			// push_back
			// pop_back
			// insert (single element)
			// insert (fill)
			// insert (range)
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

		private:
			allocator	_alloc;
			pointer		_ptr;
			size_type	_capacity;
			size_type	_size;

	};
};

#endif
