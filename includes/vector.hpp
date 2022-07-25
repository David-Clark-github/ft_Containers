/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:49:13 by dclark            #+#    #+#             */
/*   Updated: 2022/07/26 01:46:51 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <vector_iterator.hpp>
#include <reverse_iterator.hpp>
#include <enable_if.hpp>
#include <is_integral.hpp>
#include <equal_lexico_comp.hpp>
#include <iterator>
#include <iterator_traits.hpp>
#include <exception>

#define UNUSED __attribute__((unused))
#include <iostream>

namespace ft {
	template<class T, class Alloc = std::allocator<T> >
	class vector {

		public:

			/*-------- [MEMBER_TYPES] --------*/

			typedef	T											value_type;
			typedef	Alloc										allocator_type;
			typedef	typename allocator_type::difference_type	difference_type;
			typedef	typename allocator_type::size_type			size_type;
			typedef	typename allocator_type::reference			reference;
			typedef	typename allocator_type::const_reference	const_reference;
			typedef	typename allocator_type::pointer			pointer;
			typedef	typename allocator_type::const_pointer		const_pointer;
			typedef	ft::vector_iterator<value_type>				iterator;
			typedef	ft::vector_iterator<const value_type>		const_iterator;
			typedef	ft::reverse_iterator<iterator>				reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>		const_reverse_iterator;

			/*-------- [MEMBER FUNCTIONS] --------*/

			/*-------- Constructor / Destructor --------*/

			// Constructor
			explicit vector (const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _capacity(NULL), _begin(NULL), _end(NULL)  {}

			explicit vector (size_type n,
				const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _capacity(NULL), _begin(NULL), _end(NULL) {
				try {
					_begin = _alloc.allocate(n);
				} catch (std::length_error &l) {
					throw std::length_error("vector");
				}

				_end = _begin;
				_capacity = _begin + n;
				for (; n != 0; n--) {
					_alloc.construct(_end++, val);
				}
			}

			template <class InputIterator>
			vector(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, 
			InputIterator last, UNUSED const allocator_type &alloc = allocator_type()) {
				size_type n = static_cast<size_type>(ft::distance(first, last));
				_begin = _alloc.allocate(n);
				_capacity = _begin + n;
				_end = _begin;
				for (; n != 0; n--) {
					_alloc.construct(_end++, *first++);
				}
			}

			vector (const vector &x)
			: _alloc(x._alloc), _capacity(NULL), _begin(NULL), _end(NULL) {
				insert(begin(), x.begin(), x.end());
			}

			// Destructor
			~vector () {
				clear();
				_alloc.deallocate(_begin, capacity());
			}

			// operator=
			vector& operator= (const vector& x) {
				if (this != &x) {
					clear();
					reserve(x.size());
					insert(end(), x.begin(), x.end());
				}
				return (*this);
			}

			/*-------- Iterators --------*/

			// begin
			iterator begin() {
				return (iterator(_begin));
			}

			const_iterator begin () const {
				return (const_iterator(_begin));
			}

			// end
			iterator end() {
				return (iterator(_end));
			}

			const_iterator end() const {
				return (const_iterator(_end));
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
				return static_cast<size_type>(_end - _begin);
			}

			// max_size
			size_type	max_size() const {
				return (_alloc.max_size());
			}

			// resize
			void	resize(size_type n, value_type val = value_type()) {
				size_type oldS = size();
				size_type oldC = capacity();
				if (n > max_size())
					throw std::length_error("vector::resize");
				else if (n < oldS) {
					while (size() > n) {
						_alloc.destroy(--_end);
					}
				} else {
					if (n > oldC) {
						if ((oldC * 2) >= n) {
							reserve(oldC * 2);
						}
						else {
							reserve(n);
						}
					}				
					for (; oldS < n; ++oldS, ++_end) {
						_alloc.construct(_end, val);
					}

				}
			}

			// capacity
			size_type	capacity() const {
				return static_cast<size_type>(_capacity - _begin);
			}

			// empty
			bool empty() const {
				if (size()) // if isn't 0, it return false
					return (false);
				return (true);
			}

			// reserve
			void reserve(size_type n) {
				pointer		oldB1 = _begin; //Ancienne valeur a copier dans le nouveau
				pointer		oldB2 = _begin; //Ancienn pointeur a copier pour suppression
				pointer		oldE = _end;	 // Ancien pointeur (_end) pour s'arreter
				size_type	oldC = capacity(); // anciens capacity pour supprimer la quantité de memoire
				
				if (n > max_size())
					throw std::length_error("vector::reserve");
				
				if (n > capacity()) {
					_begin = _alloc.allocate(n);
					_end = _begin;
					for (; oldB2 != oldE;) {
						_alloc.construct(_end, *oldB2);
						_alloc.destroy(oldB2);
						++_end;
						++oldB2;
					}
					_alloc.deallocate(oldB1, oldC); 
					_capacity = _begin + n;
					//std::cout << ":)\n";
				}
			}

			/*-------- Element_access --------*/

			// Operator []
			reference	operator[](size_type n) {
				return *(_begin + n);
			}

			const_reference	operator[](size_type n) const {
				return *(begin() + n);
			}

			// at
			reference at(size_type n) {
				if (!(n < size()))
					throw std::out_of_range("vector::range_check");
				return *(begin() + n);
			}

			const_reference at(size_type n) const {
				if (!(n < size()))
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
  			void assign(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
			InputIterator last ) {
				clear();
				reserve(static_cast<size_type>(ft::distance(first, last)));
				for (; first != last; first++, _end++) {
					_alloc.construct(_end, *first);
				}
			}

			// assign (fill)
			void assign(size_type n, const value_type& val) {
				clear();
				reserve(n);
				for (; n != 0; n--, _end++) {
					_alloc.construct(_end, val);
				}
			}

			// push_back
			void push_back(const value_type& val) {
				if (size() == capacity()) {
					reserve(size() > 0 ? size() * 2 : 1);
				}
				_alloc.construct(_end, val);
				_end++;
			}

			// pop_back
			void pop_back() {
				_alloc.destroy(_end - 1);
				_end--;
			}

			// insert (single element)
			iterator insert(iterator position, const value_type& val) {
				difference_type d = ft::distance(begin(), position);
				insert(position, 1, val);
				return iterator(iterator(begin() + d));
			}

			// insert (fill)
			void insert (iterator position, size_type n, const value_type& val) {
				difference_type bg_pos = ft::distance(begin(), position);
				difference_type	pos_end = ft::distance(position, end());
				difference_type	bg_end = ft::distance(begin(), end());

				if (n == 0)
					return;
				if (n + size() <= capacity()) {
					;
				} else if (n + size() >= capacity() + 2) {
					reserve(n + size());
				} else {
					reserve(size() * 2);
				}
				for (difference_type i = 1; i <= pos_end; i++) {
					_alloc.construct(((_begin + bg_end + n) - i), *(_begin + bg_end - i));
					_alloc.destroy(_begin + bg_end - i);
				}
				for (size_type i = 0; i < n; i++) {
					_alloc.construct((_begin + bg_pos + (i) ), val);
				}
				_end = _begin + size() + n;
				position++;
			}

			// insert (range)
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) {

				size_type pos = static_cast<size_type>(ft::distance(begin(), position));
				size_type n = static_cast<size_type>(ft::distance(first, last));

				resize(size() + n);
				position = begin() + pos;

				size_type toMoveRight = static_cast<size_type>(ft::distance(position, end() - n));
				pointer oldEnd = _end - n - 1;
				for (size_type i = 0; i < toMoveRight; i++) {
					*(_end - i - 1) = *oldEnd--;
				}
				for (size_type i = 0; i < n && first != last; i++, first++) {
					*(position + i) = *first;
				}
			}

			// erase
			iterator erase(iterator position) {
				iterator tmp = position;
				for (; position + 1 != end(); position++) {
					_alloc.destroy(&(*position));
					_alloc.construct(&(*position), *(position + 1));
				}
				_alloc.destroy(&(*position));
				_end--;
				return (tmp);
			}

			iterator erase (iterator first, iterator last) {
				iterator tmp = first;
				for (; first != last; --last)
					erase(first);
				return (tmp);
			}

			// swap
			void swap(vector &x) {
				allocator_type tmpA = _alloc;
				pointer tmpB = _begin;
				pointer tmpE = _end;
				pointer tmpC = _capacity;

				_alloc = x._alloc;
				_begin = x._begin;
				_end = x._end;
				_capacity = x._capacity;

				x._alloc = tmpA;
				x._begin = tmpB;
				x._end = tmpE;
				x._capacity = tmpC;
			}

			// clear
			void clear() {
				size_type len = size();
				for (size_type i = 0; i < len; i++) {
					_alloc.destroy(--_end);
				}
			}

			/*-------- Allocator --------*/

			// get_allocator
			allocator_type get_allocator() const {
				return (this->_alloc);
			}


			
		private:
			allocator_type	_alloc;
			pointer			_capacity;
			pointer			_begin;
			pointer			_end;

	};			
	
	/*-------- Non-member function overlords --------*/

	// ==
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		return (std::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	// !=
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(lhs == rhs);
	}

	// <
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	// <=
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(rhs < lhs);
	}

 	// >
	template <class T, class Alloc>
	bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (rhs < lhs);
	}

	// >=
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(lhs < rhs);
	}

	// swap			
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
		x.swap(y);
	}

};

#endif
