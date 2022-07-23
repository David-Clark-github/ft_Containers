/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:20:36 by dclark            #+#    #+#             */
/*   Updated: 2022/07/23 01:42:00 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <stddef.h>

namespace ft {

	/*Iterator tag*/

	struct	input_iterator_tag	{};
	struct	output_iterator_tag	{};
	struct	forward_iterator_tag		:	public input_iterator_tag			{};
	struct	bidirectional_iterator_tag	:	public forward_iterator_tag			{};
	struct	random_access_iterator_tag	:	public bidirectional_iterator_tag	{};

	/*Iterator*/

	template<class Category, class T, class Distance = ptrdiff_t,
	class Pointer = T*, class Reference = T&>
	struct		iterator {
		typedef Category	iterator_category;
		typedef	T			value_type;
		typedef	Distance	difference_type;
		typedef	Pointer		pointer;
		typedef	Reference	reference;
	};

	/*Iterator_traits*/

	template	<class Iterator>
	struct		iterator_traits {
		typedef	typename	Iterator::difference_type	difference_type;
		typedef	typename	Iterator::value_type		value_type;
		typedef	typename	Iterator::pointer			pointer;
		typedef	typename	Iterator::reference			reference;
		typedef typename	Iterator::iterator_category	iterator_category;
	};

	template	<class T>
	struct		iterator_traits<T*> {
		typedef	ptrdiff_t						difference_type;
		typedef	T								value_type;
		typedef	T*								pointer;
		typedef	T&								reference;
		typedef	random_access_iterator_tag	iterator_category;
	};

	template	<class T>
	struct		iterator_traits<const T*> {
		typedef	ptrdiff_t						difference_type;
		typedef	T								value_type;
		typedef	T*								pointer;
		typedef	T&								reference;
		typedef	random_access_iterator_tag	iterator_category;
	};

	template<class Ite>
	class reverse_iterator {
		public:
			typedef	Ite	iterator_type;
			typedef typename iterator_traits<Ite>::iterator_category	iterator_category;
			typedef typename iterator_traits<Ite>::value_type			value_type;
			typedef typename iterator_traits<Ite>::difference_type		difference_type;
			typedef typename iterator_traits<Ite>::pointer				pointer;
			typedef typename iterator_traits<Ite>::reference			reference;

			reverse_iterator(void) : _it() {}
			
			explicit	reverse_iterator(iterator_type it) : _it(it) {}

			template<class T>
			reverse_iterator(const reverse_iterator<T> &r) : _it(r.base()) {}

			virtual ~reverse_iterator(void) {}

			iterator_type	base(void) const {
				return (_it);
			}

			reference	operator*(void) const {
				iterator_type tmp = _it;
				return *(--tmp);
			}

			reverse_iterator operator+(difference_type d) const {
				return reverse_iterator(_it - d);
			}

			reverse_iterator& operator++(void) {
				--_it;
				return (*this);
			}

			reverse_iterator& operator++(int) {
				reverse_iterator tmp(*this);
				operator++();
				return (tmp);
			}

			reverse_iterator& operator+=(difference_type d) {
				_it -= d;
				return (*this);
			}

			reverse_iterator operator-(difference_type d) const {
				return reverse_iterator(_it + d);
			}

			reverse_iterator& operator--(void) {
				++_it;
				return (*this);
			}

			reverse_iterator operator--(int) {
				reverse_iterator tmp(*this);
				operator--();
				return (tmp);
			}

			reverse_iterator& operator-=(difference_type d) {
				_it += d;
				return (*this);
			}

			pointer	operator->(void) const {
				return (&(operator*()));
			}

			reference operator[](difference_type d) const {
				return (_it[-d - 1]);
			}

			friend bool operator==(const reverse_iterator<Ite>& lhs, const reverse_iterator<Ite>& rhs) {
				return (lhs.base() == rhs.base());
			}

			template<class IteR>
			friend bool operator==(const reverse_iterator<Ite>& lhs, const reverse_iterator<IteR>& rhs) {
				return (lhs.base() == rhs.base());
			}


			friend bool operator!=(const reverse_iterator<Ite>& lhs, const reverse_iterator<Ite>& rhs) {
				return (lhs.base() != rhs.base());
			}

			template<class IteR>
			friend bool operator!=(const reverse_iterator<Ite>& lhs, const reverse_iterator<IteR>& rhs) {
				return (lhs.base() != rhs.base());
			}

			friend bool operator<(const reverse_iterator<Ite>& lhs, const reverse_iterator<Ite>& rhs) {
				return (lhs.base() > rhs.base());
			}

			template<class IteR>
			friend bool operator<(const reverse_iterator<Ite>& lhs, const reverse_iterator<IteR>& rhs) {
				return (lhs.base() > rhs.base());
			}

			friend bool operator<=(const reverse_iterator<Ite>& lhs, const reverse_iterator<Ite>& rhs) {
				return (lhs.base() >= rhs.base());
			}

			template<class IteR>
			friend bool operator<=(const reverse_iterator<Ite>& lhs, const reverse_iterator<IteR>& rhs) {
				return (lhs.base() >= rhs.base());
			}

			friend bool operator>(const reverse_iterator<Ite>& lhs, const reverse_iterator<Ite>& rhs) {
				return (lhs.base() < rhs.base());
			}

			template<class IteR>
			friend bool operator>(const reverse_iterator<Ite>& lhs, const reverse_iterator<IteR>& rhs) {
				return (lhs.base() < rhs.base());
			}

			friend bool operator>=(const reverse_iterator<Ite>& lhs, const reverse_iterator<Ite>& rhs) {
				return (lhs.base() <= rhs.base());
			}

			template<class IteR>
			friend bool operator>=(const reverse_iterator<Ite>& lhs, const reverse_iterator<IteR>& rhs) {
				return (lhs.base() <= rhs.base());
			}

			friend reverse_iterator<Ite> operator+(difference_type d, const reverse_iterator<Ite>& r) {
				return (r + d);
			}

			friend difference_type operator-(const reverse_iterator<Ite>& lhs, const reverse_iterator<Ite>& rhs) {
				return (rhs.base() - lhs.base());
			}

			template<class IteR>
			friend difference_type operator-(const reverse_iterator<Ite>& lhs, const reverse_iterator<IteR>& rhs) {
				return (rhs.base() - lhs.base());
			}

		private:
			iterator_type	_it;

	};
};

#endif
