/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:39:02 by david             #+#    #+#             */
/*   Updated: 2022/07/25 15:36:55 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include <iterator_traits.hpp>
#include <iostream>
#define IT_RAND ft::iterator<random_access_iterator_tag, T> 

namespace ft {

	template <typename T>
	class vector_iterator : public IT_RAND {
		public:

			/*-------- Member types --------*/
			typedef typename IT_RAND::value_type		value_type;
			typedef typename IT_RAND::pointer			pointer;
			typedef typename IT_RAND::reference			reference;
			typedef typename IT_RAND::difference_type	difference_type;
			typedef typename IT_RAND::iterator_category	iterator_category;

			/*-------- Constructor / Destructor --------*/

			// Constructor
			vector_iterator() : _p(NULL) {}
			vector_iterator(pointer ptr) : _p(ptr) {}
			vector_iterator(vector_iterator const &v) : _p(v._p) {}

			// Destructor
			~vector_iterator(void) {}

			// operator=
			vector_iterator	&operator=(const vector_iterator &v) {
				if (this != &v) {
					_p = v._p;
				}
				return (*this);
			}

			// base
			pointer	base(void) const {
				return (_p);
			}

			/*-------- Operator --------*/

			// *
			reference operator*() const {
				return (*_p);
			}

			// ->
			pointer	operator->(void) const {
				return &(operator*());
			}

			// +
			vector_iterator operator+(difference_type d) const {
				vector_iterator tmp(*this);
				tmp._p += d;
				return (tmp);
			}

			// -
			vector_iterator operator-(difference_type d) const {
				vector_iterator tmp(*this);
				tmp._p -= d;
				return (tmp);
			}

			// ++p
			vector_iterator	&operator++(void) {
				++_p;
				return (*this);
			}

			// p++
			vector_iterator operator++(int) {
				vector_iterator tmp(*this);
				operator++();
				return (tmp);
			}

			// --p
			vector_iterator	&operator--() {
				_p--;
				return (*this);
			}

			// p--
			vector_iterator operator--(int) {
				vector_iterator tmp = *this;
				operator--();
				return (tmp);
			}

			// []
			reference operator[](difference_type index) const {
				return *(_p + index);
			}
	
			// +=
			vector_iterator &operator+=(difference_type d)
			{
				_p += d;
				return (*this);
			}

			// -=
			vector_iterator &operator-=(difference_type d)
			{
				_p -= d;
				return (*this);
			}

			operator	vector_iterator<const T>(void) {
				return (vector_iterator<const T>(_p));
			}

			/*-------- Bool Operator --------*/

			// ==
			friend bool operator==(const vector_iterator<T>& lhs, const vector_iterator<T>& rhs) {
				return (lhs.base() == rhs.base());
			}

			template<class U>
			friend bool operator==(const vector_iterator<T>& lhs, const vector_iterator<U>& rhs) {
				return (lhs.base() == rhs.base());
			}

			// !=
			friend bool operator!=(const vector_iterator<T>& lhs, const vector_iterator<T>& rhs) {
				return (lhs.base() != rhs.base());
			}

			template<class U>
			friend bool operator!=(const vector_iterator<T>& lhs, const vector_iterator<U>& rhs) {
				return (lhs.base() != rhs.base());
			}

			// <
			friend bool operator<(const vector_iterator<T>& lhs, const vector_iterator<T>& rhs) {
				return (lhs.base() < rhs.base());
			}

			template<class U>
			friend bool operator<(const vector_iterator<T>& lhs, const vector_iterator<U>& rhs) {
				return (lhs.base() < rhs.base());
			}

			// <=
			friend bool operator<=(const vector_iterator<T>& lhs, const vector_iterator<T>& rhs) {
				return (lhs.base() <= rhs.base());
			}

			template<class U>
			friend bool operator<=(const vector_iterator<T>& lhs, const vector_iterator<U>& rhs) {
				return (lhs.base() <= rhs.base());
			}

			// >
			friend bool operator>(const vector_iterator<T>& lhs, const vector_iterator<T>& rhs) {
				return (lhs.base() > rhs.base());
			}

			template<class U>
			friend bool operator>(const vector_iterator<T>& lhs, const vector_iterator<U>& rhs) {
				return (lhs.base() > rhs.base());
			}

			// >=
			friend bool operator>=(const vector_iterator<T>& lhs, const vector_iterator<T>& rhs) {
				return (lhs.base() >= rhs.base());
			}

			template<class U>
			friend bool operator>=(const vector_iterator<T>& lhs, const vector_iterator<U>& rhs) {
				return (lhs.base() >= rhs.base());
			}

			friend vector_iterator<T> operator+(difference_type d, const vector_iterator<T>& v) {
				return (v + d);
			}

			friend difference_type operator-(const vector_iterator<T> lhs, const vector_iterator<T> rhs) {
				return (lhs.base() - rhs.base());
			}

			template<class U>
			friend difference_type operator-(const vector_iterator<T> lhs, const vector_iterator<U> rhs) {
				return (lhs.base() - rhs.base());
			}

		private:
			pointer	_p;
	};
	// distance
	template<class InputIt>
	typename ft::iterator_traits<InputIt>::difference_type
	distance(InputIt first, InputIt last) {
		typename ft::iterator_traits<InputIt>::difference_type size = 0;
		if (first == last)
			return (0);
		for (; first != last; ++first, ++size);
		return (size);
	}

};

#endif
