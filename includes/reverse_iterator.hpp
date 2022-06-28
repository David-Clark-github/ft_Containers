/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:29:52 by david             #+#    #+#             */
/*   Updated: 2022/06/28 11:48:38 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REVERSE_ITERATOR_HPP
#define FT_REVERSE_ITERATOR_HPP

#include <iterator_traits.hpp>

namespace ft {

	template <class Iterator>
	class reverse_iterator {


		public:
		/*-------- Member Types --------*/
		typedef	Iterator												iterator_type;
		typedef	typename iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef	typename iterator_traits<Iterator>::value_type			value_type;
		typedef	typename iterator_traits<Iterator>::difference_type		difference_type;
		typedef	typename iterator_traits<Iterator>::pointer				pointer;
		typedef	typename iterator_traits<Iterator>::reference			reference;

		/*-------- Constructor / Destructor --------*/

		// Default
		reverse_iterator() {}

		// Initialization
		reverse_iterator(iterator_type it) : _current(it) {}

		// Copy
		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter> &rev_it) : _current(rev_it.base()) {}

		// Destructor
		virtual	~reverse_iterator() {}

		/*-------- Member function --------*/
		iterator_type	base() const {
			return (this->_current);
		}
		
		// =
		template< class U >
		reverse_iterator &operator=( const ft::reverse_iterator<U>& other ) {
			if (this != &other) {
				_current = other.base();
			}
			return *this;
		}

		//*
		value_type	&operator*() const {
			iterator_type tmp = _current;
			return *(--tmp);
		}

		//+
		reverse_iterator	operator+(difference_type d) const {
			return (reverse_iterator(this->_current - d));
		}

		//++_current
		reverse_iterator	&operator++() {
			--this->_current;
			return (*this);
		}

		//_current++
		reverse_iterator	operator++(int) {
			reverse_iterator tmp(*this);
			this->_current--;
			return (tmp);
		}

		//+=
		reverse_iterator	&operator+=(difference_type d) {
			this->_current -= d;
			return (*this);
		}

		//-
		reverse_iterator	operator-(difference_type d) const {
			return (reverse_iterator(this->_current + d));
		}

		//--_current
		reverse_iterator	&operator--() {
			++this->_current;
			return (*this);
		}

		//_current--
		reverse_iterator	operator--(int) {
			reverse_iterator tmp(*this);
			this->_current++;
			return (tmp);
		}

		//-=
		reverse_iterator	&operator-=(difference_type d) {
			this->_current += d;
			return (*this);
		}

		//->
		pointer	operator->() const {
			return &(operator*());
		}

		//[]
		reference	operator[](difference_type d) const {
			return (*(this->_current - d - 1));
		}

		/* https://en.cppreference.com/w/cpp/iterator/reverse_iterator*/
		/* current (protected) 	the underlying iterator of which base() returns a copy */
		protected:
			iterator_type	_current;
	};

	/*-------- Relational Operators --------*/

	// ==
	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() == rhs.base());
	}

	// !=
	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() != rhs.base());
	}

	// <
	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() > rhs.base());
	}

	// <=
	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() >= rhs.base());
	}

	// >
	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() < rhs.base());
	}

	// >=
	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() <= rhs.base());
	}

	// +
	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator>& rev_it) {
		return (reverse_iterator<Iterator>(rev_it.base() - n));
	}

	// -
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(
		const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs) {
		return (rhs.base() - lhs.base());
	}

};

#endif
