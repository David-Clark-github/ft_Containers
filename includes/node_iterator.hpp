/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:16:28 by david             #+#    #+#             */
/*   Updated: 2022/07/13 18:32:10 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_ITERATOR_HPP
#define NODE_ITERATOR_HPP

#include <iterator>
#include <node.hpp>
#include <iterator.hpp>

namespace ft {

	template<typename T, typename Node>
	class node_iterator : public ft::iterator<std::bidirectional_iterator_tag, T> {
		public:
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::value_type			value_type;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::difference_type		difference_type;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::pointer				pointer;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::reference			reference;
			typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
			typedef Node																			node_type;
			typedef Node*																			node_pointer;
			typedef Node&																			node_reference;

		/*-------- Constructor / Destructor --------*/

			node_iterator(void)
			: _current(), _root(), _end() {}

			node_iterator(const node_pointer &p, const node_pointer &root, const node_pointer &end)
			: _current((p == nullptr) ? end : p), _root(root), _end(end) {} 
			
			node_iterator(const node_iterator &m)
			: _current(m._current), _root(m._root), _end(m._end) {}

			virtual ~node_iterator() {}

			operator node_iterator<T, Node> (void) {
				return (node_iterator<const T, Node>(_current, _root, _end));
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
				return (_current->data);
			}

			// ->
			node_pointer	operator->() {
				return (&operator*());
			}

			// node_i++
			node_iterator operator++(int) {
				node_iterator tmp = *this;
				/*
				if (_current == _end)
					_current = min(_root);
				else
					_current = increase();
					*/
				++this;
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
				/*
				if (_current == _end)
					_current = max(_root);
				else
					_current = decrease();
					*/
				++this;
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
			friend	bool operator==(const node_iterator<value_type, node_type> &l, const node_iterator<value_type, node_type> &r) {
				return (l._current == r._current);
			}

			// !=
			friend	bool operator!=(const node_iterator<value_type, node_type> &l, const node_iterator<value_type, node_type> &r) {
				return (l._current != r._current);
			}

		private:
 
			node_pointer	_increase() {
				if (_current->right != _end)
					return (min(_current->right));
				node_pointer tmp = _current->parent;
				for(;(tmp != _end && _current == tmp->right); _current = tmp, tmp = tmp->parent);
				return (tmp);

			}

			node_pointer	_decrease() {
				if (_current->left != _end)
					return (max(_current->left));
				node_pointer tmp = _current->parent;
				for(;(tmp != _end && _current == tmp->left); _current = tmp, tmp = tmp->parent);
				return (tmp);
			}

			node_pointer	_max(node_pointer node) {
				if (!node || node == _end)
					return (_end);
				else {
					for (; node->right != _end; node = node->right);
					return (node);
				}
			}

			node_pointer	_min(node_pointer node) {
				if (!node || node == _end)
					return (_end);
				else {
					for (; node->left != _end; node = node->left);
					return (node);
				}

			}

			node_pointer	_current;
			node_pointer	_root;
			node_pointer	_end;
	};

};

#endif
