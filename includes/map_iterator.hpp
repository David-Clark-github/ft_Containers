/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:16:28 by david             #+#    #+#             */
/*   Updated: 2022/07/06 10:57:48 by dclark           ###   ########.fr       */
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
			typedef Node*							pointer;
			typedef Node&							reference;
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
				increase();
				return (tmp);
			}

			// ++map_i
			map_iterator &operator++() {
				increase();
				return (*this);
			}

			// map_i--
			map_iterator operator--(int) {
				map_iterator	tmp(*this);
				decrease();
				return (tmp);
			}

			// --map_i
			map_iterator &operator--() {
				decrease();
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
				if (_p->right) {
					_p = _p->right;
					while (_p->left)
						_p = _p->left;
				} else {
					pointer tmp = _p;
					_p = _p->parent;
					while (_p->left != tmp) {
						tmp = _p;
						_p = _p->parent;
					}
				}
			}

			void	decrease() {
				if (_p->left) {
					_p = _p->left;
					while (_p->right)
						_p->right;
				} else {
					pointer tmp = _p;
					_p = _p->parent;
					while (_p->right != tmp) {
						tmp = _p;
						_p = _p->parent;
					}
				}
			}

		private:
			pointer	_p;
	};

};

#endif
