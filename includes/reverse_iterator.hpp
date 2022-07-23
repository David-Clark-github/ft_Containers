/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:29:52 by david             #+#    #+#             */
/*   Updated: 2022/07/23 01:43:29 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include <iterator_traits.hpp>
namespace ft {
/*
	template<class T>
	class reverse_iterator : public ft::iterator<typename ft::iterator_traits<T>::iterator_category,
					typename ft::iterator_traits<T>::value_type,
					typename ft::iterator_traits<T>::difference_type,
					typename ft::iterator_traits<T>::pointer,
					typename ft::iterator_traits<T>::reference>
	{
		public:
			typedef T													iterator_type;
			//typedef typename ft::iterator_traits<T>::value_type			value_type;
			//typedef typename ft::iterator_traits<T>::iterator_category	iterator_category:
			typedef typename ft::iterator_traits<T>::difference_type	difference_type;
			typedef typename ft::iterator_traits<T>::reference			reference;
			typedef typename ft::iterator_traits<T>::pointer			pointer;

			-------- Constructor --------

			reverse_iterator() : _cur() {}
			explicit reverse_iterator(T t) : _cur(t) {}
			template<class U>
			reverse_iterator(const reverse_iterator<U> &r) : _cur(r.base()) {}
			
			template<class U>
			reverse_iterator	&operator=(const reverse_iterator<U> &r) {
				if (this != r) {
					_cur = r.base();
				}
				return (*this);
			}

			T	base() const {
				return (_cur);
			}

			reference	operator*() const {
				iterator_type	tmp = _cur;
				return (*--tmp);
			}

			pointer	operator->() const {
				return (&operator*());
			}

			reverse_iterator	&operator++() {
				--_cur;
				return (*this);
			}

			reverse_iterator	&operator--() {
				++_cur;
				return (*this);
			}

			reverse_iterator	operator++(int) {
				reverse_iterator	tmp(*this);
				--_cur;
				return (tmp);
			}

			reverse_iterator	operator--(int) {
				reverse_iterator	tmp(*this);
				++_cur;
				return (tmp);
			}

			reverse_iterator	operator+(difference_type d) const {
				return reverse_iterator(_cur - d);
			}

			reverse_iterator	operator-(difference_type d) const {
				return reverse_iterator(_cur + d);
			}

			reverse_iterator&	operator+=(difference_type d) {
				_cur -= d;
				return *this;
			}

			reverse_iterator&	operator-=(difference_type d) {
				_cur += d;
				return *this;
			}

			reference	operator[](difference_type d) const {
				return (_cur[-d - 1]);
			}

		protected:
			T	_cur;

	};
	*/
};

#endif
