/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:39:02 by david             #+#    #+#             */
/*   Updated: 2022/07/21 01:25:16 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include <iterator_traits.hpp>
#define IT_RAND ft::iterator<std::random_access_iterator_tag, T> 

namespace ft {

	template <typename T>
	class vector_iterator : public IT_RAND {
		public:

			/*-------- Member types --------*/
			/*
			typedef	T								value_type;
			typedef	T*								pointer;
			typedef	T&								reference;
			typedef	std::ptrdiff_t					difference_type;
			typedef	std::random_access_iterator_tag	iterator_category;
		*/
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
			~vector_iterator() {}

			// operator=
			vector_iterator	&operator=(const vector_iterator &v) {
				if (this != &v) {
					this->_p = v._p;
				}
				return (*this);
			}

			// base
			pointer	base(void) const {
				return (this->_p);
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
				vector_iterator v(*this);
				v._p += d;
				return (v);
			}

			// ++p
			vector_iterator	&operator++(void) {
				this->_p++;
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
				this->_p--;
				return (*this);
			}

			// p--
			vector_iterator operator--(int) {
				vector_iterator tmp = *this;
				operator--();
				return (tmp);
			}

			// []
			reference operator[](difference_type index) {
				return *(_p + index);
			}
	
			// +=
			vector_iterator<T> &operator+=(difference_type d)
			{
				this->_p += d;
				return (*this);
			}

			// -=
			vector_iterator<T> &operator-=(difference_type d)
			{
				this->_p -= d;
				return (*this);
			}

			operator	vector_iterator<const T>() {
				return (vector_iterator<const T>(_p));
			}

			/*-------- Bool Operator --------*/

			// ==
			friend bool operator==(const vector_iterator<T> &v1, const vector_iterator<T> &v2) {
				return (v1.base() == v2.base());
			}

			template<class U>
			friend bool operator==(const vector_iterator<T> &v1, const vector_iterator<U> &v2) {
				return (v1.base() == v2.base());
			}

			// !=
			friend bool operator!=(const vector_iterator<T> &v1, const vector_iterator<T> &v2) {
				return (v1.base() != v2.base());
			}
			
			template<class U>
			friend bool operator!=(const vector_iterator<T> &v1, const vector_iterator<U> &v2) {
				return (v1.base() != v2.base());
			}

			// <
			friend bool operator<(const vector_iterator &v1, const vector_iterator &v2) {
				return (v1.base() < v2.base());
			}

			// <=
			friend bool operator<=(const vector_iterator &v1, const vector_iterator &v2) {
				return (v1.base() <= v2.base());
			}

			// >
			friend bool operator>(const vector_iterator &v1, const vector_iterator &v2) {
				return (v1.base() > v2.base());
			}

			// >=
			friend bool operator>=(const vector_iterator &v1, const vector_iterator &v2) {
				return (v1.base() >= v2.base());
			}

			// +
			friend vector_iterator<T> operator+(difference_type n, const vector_iterator<T> &v) {
				return (v + n);
			}

			// -
			friend difference_type operator-(const vector_iterator<T> lhs, const vector_iterator<T> rhs) {
				return (lhs.base() - rhs.base());
			}

			template<class U>	
			friend difference_type operator-(const vector_iterator<T> lhs, const vector_iterator<U> rhs) {
				return (lhs.base() - rhs.base());
			}

			protected:
			pointer	_p;
	};
	// distance
	template<class InputIt>
	typename ft::iterator_traits<InputIt>::difference_type
	distance(InputIt first, InputIt last) {
		typename ft::iterator_traits<InputIt>::difference_type size = 0;
		for (; first != last; ++first, ++size);
		return (size);
	}


	/*
	// +
	template <typename Iterator>
	vector_iterator<Iterator> operator+(typename vector_iterator<Iterator>::difference_type d, const vector_iterator<Iterator> &it) {
		return (vector_iterator<Iterator>(it.base() + d));
	}

	// -
	template <typename Iterator>
	vector_iterator<Iterator> operator-(typename vector_iterator<Iterator>::difference_type d, const vector_iterator<Iterator> &it) {
		return (vector_iterator<Iterator>(it.base() - d));
	}
	
	// ==
	template <typename it1, typename it2>
	bool operator==(const vector_iterator<it1> &vi1, const vector_iterator<it2> &vi2) {
		return (vi1.base() == vi2.base());
	}
	

	// !=
	template <typename it1, typename it2>
	bool operator!=(const vector_iterator<it1> &vi1, const vector_iterator<it2> &vi2) {
		return (vi1.base() != vi2.base());
	}

	// <
	template <typename it1, typename it2>
	bool operator<(const vector_iterator<it1> &vi1, const vector_iterator<it2> &vi2) {
		return (vi1.base() < vi2.base());
	}

	// <=
	template <typename it1, typename it2>
	bool operator<=(const vector_iterator<it1> &vi1, const vector_iterator<it2> &vi2) {
		return (vi1.base() <= vi2.base());
	}

	// >
	template <typename it1, typename it2>
	bool operator>(const vector_iterator<it1> &vi1, const vector_iterator<it2> &vi2) {
		return (vi1.base() > vi2.base());
	}

	// >=
	template <typename it1, typename it2>
	bool operator>=(const vector_iterator<it1> &vi1, const vector_iterator<it2> &vi2) {
		return (vi1.base() >= vi2.base());
	}

	// <<
	template <typename Iterator>
	std::ostream &operator<<(std::ostream &o, vector_iterator<Iterator> &vi) {
		o << *vi.base();
		return o;
	}

	*/


};

#endif
