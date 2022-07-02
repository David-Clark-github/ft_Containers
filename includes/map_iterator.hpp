/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:16:28 by david             #+#    #+#             */
/*   Updated: 2022/07/02 23:21:31 by david            ###   ########.fr       */
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
			typedef Node							node_type;
			typedef Node*							node_pointer;
			typedef Node&							node_reference;
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
				return *(this->_p);
			}

			// ->
			reference	operator->() {
				return (this->_p);
			}

			// map_i++
			map_iterator operator++(int) {
				map_iterator	tmp(*this);
				++(*this);
				return (tmp);
			}

			// ++map_i
			map_iterator &operator--() {
				*this->_p++;
				return (*this);
			}

			// map_i--
			map_iterator operator--(int) {
				map_iterator	tmp(*this);
				--(*this);
				return (tmp);
			}

			// --map_i
			map_iterator &operator--() {
				*this->_p--;
				return (*this);
			}

			// ==
			friend	bool operator==(const map_iterator &m1, const map_iterator &m2) {
				return (m1.base() == m2.base());
			}

			// !=
			friend	bool operator!=(const map_iterator &m1, const map_iterator &m2) {
				return (m1.base() != m2.base());
			}

			void	increase() {
				if (_ptr->right) {
					_ptr = ptr_right;
					while (_ptr->right)
						_ptr = _ptr->right;
				} else {
					//_ptr = _ptr->parent; A cogiter ...
				}
			}

		private:
			node_pointer	_p;
	};

};

#endif
