/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:49:13 by dclark            #+#    #+#             */
/*   Updated: 2022/06/14 17:12:07 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
#define FT_VECTOR_H

#include <ft_vector_iterator.h>
#include <ft_reverse_iterator.h>
#include <ft_enable_if.h>
#include <ft_is_integral.h>

namespace ft {
	template<class T, class Alloc = std::allocator<T>>
	class vector {

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
			: _alloc(alloc), _begin(NULL), _end(NULL), _capacity(0) {}

			// Fill
			explicit vector (size_type n,
				const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _begin(NULL), _end(NULL), _capacity(0) {
				try {
					_begin = _alloc.construct(n);
				} catch (std::length_error &l) {
					throw std::length_error("vector error");
				}

				_end = begin();
				_capacity = begin() + n;

				for (; n != 0; n--) {
					_alloc.construct(_end++, val);
				}
			}

			// Range
			template <class InputIterator>
			vector (ft::enable_if<!ft::is_integral<InputIterator>::value> first,
				InputIterator last,
				const allocator_type& alloc = allocator_type()) {
				difference_type	n = std::distance(first, last);

				_begin = _alloc.allocate(n):
				_end = begin();
				_capacity = begin() + n;

				for (; n != 0; n--) {
					_alloc.construct(_end++, *first++);
				}
			}

			// Copy
			vector (const vector &x) {
				_begin = alloc.allocate(x.size());
				_end = begin();
				_capacity = begin() + x.size();

				for (pointer tmp = x.begin(); tmp != x.end(); tmp++; _end++) {
					_alloc.construct(_end, *tmp);
				}
			}

			// Destructor
			~vector () {
				clear();
				_alloc.deallocate(begin(), capacity());
			}

			// Operator Copy
			// reste a faire insert
			vector& operator= (const vector& x) {
				if (this != &x) {
					clear();
					reserve(x.size());
//	-->		//		insert(begin(), x.begin(), x.end());
				}
				return (*this);
			}

			/*-------- Iterators --------*/
			// begin
			iterator begin() {
				return (iterator(this->_begin));
			}

			const_iterator begin () const {
				return (const_iterator(this->_begin));
			}

			// end
			iterator end() {
				return (iterator(this->_end));
			}

			const_iterator end() const {
				return (const_iterator(this->_end));
			}

			// rbegin
			reverse_iterator rbegin() {
				return (reverse_iterator(end()));
			}

			const_reverse_iterator rbegin() const {
				return (const_reverse_iterator(end()));
			}

			// rend
			reverse_iterator rend() {
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator rend() const {
				return (const_reverse_iterator(begin()));
			}

			/*-------- Capacity --------*/
			// size
			size_type	size() const {
				return (end() - begin());
			}

			// max_size
			size_type	max_size() const {
				return (allocator_type().max_size());
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
					else
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
					pointer		oldB1 = begin(); //Ancienne valeur a copier dans le nouveau
					pointer		oldB2 = begin(); //Ancienn pointeur a copier pour suppression
					pointer		oldE = end();	 // Ancien pointeur (_end) pour s'arreter
					size_type	oldC = capacity(); // anciens capacity pour la capacité a supprimer

					_begin = _alloc.allocate(n);
					_end = begin();
					_capacity = n;
					while (oldB1 != oldE) {
						_alloc.construct(_end++, *oldB1++); // Alloue les anciennes valeurs de oldB1 dans le nouveau avec _end (qui avance jusqu'a oldE)
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
			// assign (range)
			template <class InputIterator>
  			void assign (InputIterator first, InputIterator last) {
				if ((last - first) > capacity())
					reserve(last - first);
			}

			// assign (fill)
			void assign (size_type n, const value_type& val) {
				clear();
				reserve(n);

			}

			// push_back
			// pop_back
			// insert (single element)
			iterator insert (iterator position, const value_type& val) {
				insert(position, 1, val);
				return iterator(position);
			}

			// insert (fill)
			void insert (iterator position, size_type n, const value_type& val) {
				
			}
			// insert (range)
			// erase
			iterator erase(iterator_traits position) {
				//prototype d'idée
				/* copier x elements sauf le pointeur dans un autre vector				
				** et detruire l'original
				*/
			}

			iterator erase (iterator first, iterator last) {
				//prototype d'idée
				/*
				**
				*/
			}
			// swap
			void swap(vector &x) {
				pointer swap = begin();
				set_current(x.begin());
				x.set_current(swap);
			}

			// clear
			void clear() {
				pointer bg = begin();
				while (bg != end()) {
					_alloc.destroy(bg++);
				}
				_size = 0;
			}

			/*-------- Allocator --------*/
			// get_allocator
			allocator_type get_allocator() const {
				return (this->_alloc);
			}


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
			size_type	_capacity;
			pointer		_begin;
			pointer		_end;

	};
};

#endif
