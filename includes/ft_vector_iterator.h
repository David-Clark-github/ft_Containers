/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_iterator.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:39:02 by david             #+#    #+#             */
/*   Updated: 2022/06/06 23:24:47 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_ITERATOR_H
#define FT_VECTOR_ITERATOR_H

#include <iterator>

namespace ft {

	template <typename T>
	class vector_iterator {
		public:

			/*-------- Member types --------*/
			typedef	T								value_type;
			typedef	std::random_access_iterator_tag	iterator_category;
			typedef	std::ptrdiff_t					difference_type;
			typedef	value_type*						pointer;
			typedef	value_type&						reference;

			/*-------- Constructor / Destructor --------*/
			vector_iterator() : _p(NULL) {}
			vector_iterator(pointer ptr) : _p(ptr) {}
			vector_iterator(vector_iterator const &v) : _p(v._p) {}
			virtual ~vector_iterator() {}

			vector_iterator	&operator=(const vector_iterator &v) {
				if (this != &v) {
					this->_p = v._p;
				}
				return (*this);
			}

			/*-------- Getter --------*/
			pointer	get_p(void) const {
				return (this->_p);
			}

			pointer	base(void) const {
				return (this->_p);
			}

			/*-------- Operator --------*/
			//++p
			vector_iterator	&operator++() {
				*this->_p++;
				return (*this)
			}

			//p++
			vector_iterator &operator++(int) {
				vector_iterator tmp = *this;
				++(*this);
				return (tmp);
			}

			//--p
			vector_iterator	&operator++() {
				*this->_p--;
				return (*this)
			}

			//p--
			vector_iterator &operator++(int) {
				vector_iterator tmp = *this;
				--(*this);
				return (tmp);
			}

			//[]
			vector_iterator &operator[](int index) {
				return *(this->_p + index);
			}

			//*
			vector_iterator &operator*() {
				return (this->_p);
			}

			//*
			value_type &operator*() {
				return (*this->_p);
			}

			/*-------- Bool Operator --------*/
			//==
			bool &operator==(const vector_iterator &v) const {
				return (this->_p == v._p);
			}

			//!=
			bool &operator!=(const vector_iterator &v) const {
				return (this->_p != v._p);
			}

			//<
			bool &operator<(const vector_iterator &v) const {
				return (this->_p < v._p);
			}

			//<=
			bool &operator<=(const vector_iterator &v) const {
				return (this->_p <= v._p);
			}

			//>
			bool &operator>(const vector_iterator &v) const {
				return (this->_p > v._p);
			}

			//>=
			bool &operator>=(const vector_iterator &v) const {
				return (this->_p >= v._p);
			}
			
			//+
			vector_iterator operator+(difference_type d) const
			{
				vector_iterator v = this->_p + d;
				return (v);
			}

			//+
			difference_type operator+(const vector_iterator &v) const
			{
				difference_type d = this->_p + v._p;
				return (d);
			}

			//-
			vector_iterator operator-(difference_type d) const
			{
				vector_iterator v = this->_p - d;
				return (v);
			}

			//-
			difference_type operator-(const vector_iterator &v) const
			{
				difference_type d = this->_p - v._p;
				return (d);
			}

			//+=
			vector_iterator<T> &operator+=(difference_type d)
			{
				this->_p += d;
				return (*this);
			}

			//-=
			vector_iterator<T> &operator-=(difference_type d)
			{
				this->_p -= d;
				return (*this);
			}

		protected:
			pointer	_p;
	};

};

#endif
