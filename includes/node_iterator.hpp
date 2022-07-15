/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 10:16:28 by david             #+#    #+#             */
/*   Updated: 2022/07/15 01:47:18 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_ITERATOR_HPP
#define NODE_ITERATOR_HPP

#include <iterator>
#include <node.hpp>
#include <iterator_traits.hpp>

namespace ft {

	template <class T, class Node>
		class node_iterator : public iterator<std::bidirectional_iterator_tag, T>
	{

		public:
			typedef T                                                 value_type;
			typedef Node                                              node_type;
			typedef Node*                                             node_pointer;

			typedef iterator<std::bidirectional_iterator_tag, value_type>  iterator_type;
			typedef typename iterator_type::iterator_category         iterator_category;
			typedef typename iterator_type::difference_type           difference_type;
			typedef typename iterator_type::pointer                   pointer;
			typedef typename iterator_type::reference                 reference;


		public:
			node_iterator(void) : _begin(nullptr), _end(nullptr), _cur(nullptr) {}

			node_iterator(node_pointer const& begin, node_pointer const& end, node_pointer const& current) :
				_begin(begin),
				_end(end),
				_cur(current)
		{}

			node_iterator(node_iterator const& u)
			{
				*this = u;
			}

			node_iterator&		operator=(const node_iterator& u)
			{
				if (this == &u)
					return *this;

				_begin = u._begin;
				_end = u._end;
				_cur = u._cur;
				return *this;
			}

			~node_iterator() {}

			node_pointer		get_current(void) const
			{
				return _cur;
			}

			reference			operator*() const
			{
				return _cur->data;
			}

			pointer				operator->() const
			{
				return &(operator*());
			}

			node_iterator&		operator++()
			{
				if (_cur == max(_begin))
				{
					_cur = _end;
					return *this;
				}
				else if (_cur == _end)
				{
					_cur = nullptr;
					return *this;
				}
				_cur = successor(_cur);
				return *this;
			}

			node_iterator		operator++(int)
			{
				node_iterator	tmp(*this);
				operator++();
				return tmp;
			}

			node_iterator&		operator--()
			{
				if (_cur == _end)
				{
					_cur = max(_begin);
					return *this;
				}
				_cur = predecessor(_cur);
				return *this;
			}

			node_iterator		operator--(int)
			{
				node_iterator	tmp(*this);
				operator--();
				return tmp;
			}

			// needed for conversion to a const_iterator
			operator			node_iterator<const T, Node> (void)
			{
				return node_iterator<const T, Node>(_begin, _end, _cur);
			}


		private:
			node_pointer	min(node_pointer s)
			{
				for ( ; s->left != _end; s = s->left);
				return s;
			}

			node_pointer	max(node_pointer s)
			{
				for ( ; s->right != _end; s = s->right);
				return s;
			}

			node_pointer	successor(node_pointer s)
			{
				if (s->right != _end)
					return min(s->right);

				node_pointer	tmp = s->parent;
				while (tmp != _end && s == tmp->right)
				{
					s = tmp;
					tmp = tmp->parent;
				}
				return tmp;
			}

			node_pointer	predecessor(node_pointer s)
			{
				if (s->left != _end)
					return max(s->left);

				node_pointer	tmp = s->parent;
				while (tmp != _end && s == tmp->left)
				{
					s = tmp;
					tmp = tmp->parent;
				}
				return tmp;
			}


		private:
			node_pointer	_begin;
			node_pointer	_end;
			node_pointer	_cur;

	}; /* node_iterator */

	template <class IteratorL, class IteratorR, class _Node>
		bool	operator==(node_iterator<IteratorL, _Node> const& x,
				node_iterator<IteratorR, _Node> const& y)
		{ return x.get_current() == y.get_current(); }

	template <class IteratorL, class IteratorR, class _Node>
		bool	operator!=(node_iterator<IteratorL, _Node> const& x,
				node_iterator<IteratorR, _Node> const& y)
		{ return x.get_current() != y.get_current(); }



};

#endif
