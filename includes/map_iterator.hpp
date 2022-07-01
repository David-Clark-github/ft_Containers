/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:16:28 by david             #+#    #+#             */
/*   Updated: 2022/07/01 19:14:20 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include <iterator>
#include <map_node.hpp>

namespace ft {

	template<typename T, typename Node>
	class map_iterator {
		public:
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef std::ptrdiff_t					difference_type;
			typedef std::bidirectional_iterator_tag	iterator_category;

		/*-------- Constructor / Destructor --------*/
			map_iterator() : _p(NULL) {}
			map_iterator(pointer p) : _p(p) {}
			map_iterator(const map_iterator &m) : _p(m._p) {}
			virtual ~map_iterator() {}

			map_iterator	&operator=(const map_iterator &m) {
				if (this != &m) {
					this->_p = m._p;
				}
				return (*this);
			}

			/*-------- Getter --------*/
			pointer	base(void) const {
				return (this->_p);
			}

			/*-------- Operator --------*/
			// *
			reference	operator*() {
				return *(base());
			}

			// ->
			reference	operator->() {
				return (this->_p);
			}

			// +
			map_iterator	operator+(difference_type d) const {
				map_iterator m(*this);
				m._p += d;
				return (m);
			}

		private:
			pointer	_p;
	};

};

#endif
