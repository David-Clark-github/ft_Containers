/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:16:28 by david             #+#    #+#             */
/*   Updated: 2022/07/10 11:51:21 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_ITERATOR_HPP
#define NODE_ITERATOR_HPP

#include <iterator>
#include <node.hpp>

namespace ft {

	template<typename T, typename Node>
	class node_iterator {
		public:
			typedef T								value_type;
			typedef Node							node_type;
			typedef Node*							pointer;
			typedef Node&							reference;
			typedef std::ptrdiff_t					difference_type;
			typedef std::bidirectional_iterator_tag	iterator_category;

		/*-------- Constructor / Destructor --------*/

			node_iterator(void)
			: _current(), _root(), _end() {}

			node_iterator(const pointer &p, const pointer &root, const pointer &end)
			: _current((p == nullptr) ? end : p), _root(root), _end(end) {} 
			
			node_iterator(const node_iterator &m)
			: _current(m._current), _root(m._root), _end(m._end) {}

			virtual ~node_iterator() {}

			operator node_iterator<T, Node> (void) {
				return (node_iterator<T, Node>(_current, _root, _end));
			}


			node_iterator	&operator=(const node_iterator &m) {
				if (this != &m) {
					_current = m._current;
					_root = m._root;
					_end = m._end;
				}
				return (*this);
			}

			/*-------- Operator --------*/
			// *
			reference	operator*() {
				return *(this->_current->data);
			}

			// ->
			pointer	operator->() {
				return (&operator*());
			}

			// node_i++
			node_iterator operator++(int) {
				node_iterator tmp = *this;
				if (_current == _end)
					_current = min(_root);
				else
					_current = increase();
				return (tmp);
			}

			// ++node_i
			node_iterator &operator++() {
				if (_current == _end)
					_current = min(_root);
				else
					_current = increase();
				return (*this);
			}

			// node_i--
			node_iterator operator--(int) {
				node_iterator tmp = *this;
				if (_current == _end)
					_current = max(_root);
				else
					_current = decrease();
				return (tmp);
			}

			// --node_i
			node_iterator &operator--() {
				if (_current == _end)
					_current = max(_root);
				else
					_current = decrease();
				return (*this);

			}

			// ==
			friend	bool operator==(const node_iterator &m1, const node_iterator &m2) {
				return (m1.base() == m2.base());
			}

			// !=
			friend	bool operator!=(const node_iterator &m1, const node_iterator &m2) {
				return (m1.base() != m2.base());
			}

		private:
			pointer	increase() {
				if (_current->right != _end)
					return (min(_current->right));
				pointer tmp = _current->parent;
				for(;(tmp != _end && _current == tmp->right); _current = tmp, tmp = tmp->parent);
				return (tmp);

			}

			pointer	decrease() {
				if (_current->left != _end)
					return (max(_current->left));
				pointer tmp = _current->parent;
				for(;(tmp != _end && _current == tmp->left); _current = tmp, tmp = tmp->parent);
				return (tmp);
			}

			pointer	max(pointer node) {
				if (!node || node == _end)
					return (_end);
				else {
					for (; node->right != _end; node = node->right);
					return (node);
				}
			}

			pointer	min(pointer node) {
				if (!node || node == _end)
					return (_end);
				else {
					for (; node->left != _end; node = node->left);
					return (node);
				}

			}

			pointer	_current;
			pointer	_root;
			pointer	_end;
	};

};

#endif
