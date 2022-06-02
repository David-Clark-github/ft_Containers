/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterators_test.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:04:31 by dclark            #+#    #+#             */
/*   Updated: 2022/05/25 12:36:19 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATORS_TEST_H
#define FT_ITERATORS_TEST_H

#include <iterator> // For std::forward_iterator_tag
#include <cstddef>  // For std::ptrdiff_t
#include <iostream>

class Integers {
	public:
		struct	Iterator {
			using iterator_category = std::forward_iterator_tag;
			using difference_type   = std::ptrdiff_t;
			using value_type        = int;
			using pointer           = int*;  // or also value_type*
			using reference         = int&;  // or also value_type&

			//Constructeur de Iterator
			Iterator(pointer ptr) : m_ptr(ptr) {}

			reference	operator*()const {return *m_ptr;}
			pointer		operator->()const {return m_ptr;}

			//prefix
			Iterator	&operator++() {m_ptr++; return *this;}
			//postfix
			Iterator	operator++(int) {Iterator tmp = *this; ++(*this); return tmp;}

			friend bool	operator==(const Iterator& a, const Iterator& b) {return (a.m_ptr == b.m_ptr);}
			friend bool	operator!=(const Iterator& a, const Iterator& b) {return (a.m_ptr != b.m_ptr);}

			private:
				pointer	m_ptr;
		};

		Iterator begin() {return Iterator(&m_data[0]);}
		Iterator end() {return Iterator(&m_data[200]);}

	private:
		int	m_data[200];
};

#endif
