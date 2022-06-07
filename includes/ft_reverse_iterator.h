/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_iterator.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:29:52 by david             #+#    #+#             */
/*   Updated: 2022/06/07 22:02:01 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REVERSE_ITERATOR_H
#define FT_REVERSE_ITERATOR_H

#include <ft_iterator_traits.h>

namespace ft {

	template <class Iterator>
	class reverse_iterator {

		public:
		/*-------- Member Types --------*/
		typedef	Iterator										iterator_type;
		typedef	iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef	iterator_traits<Iterator>::value_type			value_type;
		typedef	iterator_traits<Iterator>::difference_type		difference_type;
		typedef	iterator_traits<Iterator>::pointer				pointer;
		typedef	iterator_traits<Iterator>::reference			reference;

		/*-------- Constructor / Destructor --------*/
		reverse_iterator() : _ptr(NULL) {}
		reverse_iterator(iterator_type it) : _ptr(it) {}
		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter> &rev_it) : _ptr(rev_it.base()) {}

		virtual	~reverse_iterator() {}

		/*-------- Member function --------*/
		iterator_type	base() const {
			return (this->_ptr);
		}
		
		//*
		reference	operator*() const {
			return (*--this->_ptr);
		}

		//+
		reverse_iterator	operator+(difference_type d) const {
			return (reverse_iterator(this->_ptr - d));
		}

		//++_ptr
		reverse_iterator	&operator++() {
			--this->_ptr;
			return (*this);
		}

		//_ptr++
		reverse_iterator	operator++(int) {
			reverse_iterator tmp(*this);
			this->_ptr--;
			return (tmp);
		}

		//+=
		reverse_iterator	&operator+=(difference_type d) {
			this->_ptr -= d;
			return (*this);
		}

		//-
		reverse_iterator	operator-(difference_type d) const {
			return (reverse_iterator(this->_ptr + d));
		}

		//--_ptr
		reverse_iterator	&operator--() {
			++this->_ptr;
			return (*this);
		}

		//_ptr--
		reverse_iterator	operator--(int) {
			reverse_iterator tmp(*this);
			this->_ptr++;
			return (tmp);
		}

		//-=
		reverse_iterator	&operator-=(difference_type d) {
			this->_ptr += d;
			return (*this);
		}

		//->
		pointer	operator->() const {
			return &(operator*());
		}

		//[]
		reference	operator[](difference_type d) const {
			return (*(this->_ptr - n - 1));
		}

		protected:
		iterator_type	_ptr;
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
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) {
		return (reverse_iterator<Iter>(it.base() - n));
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
