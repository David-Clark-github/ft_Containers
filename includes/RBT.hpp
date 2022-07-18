/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:46:18 by david             #+#    #+#             */
/*   Updated: 2022/07/18 15:32:23 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
#define RBT_HPP

#include <node.hpp>
#include <node_iterator.hpp>
#include <binary_function.hpp>
#include <pair.hpp>
#include <is_integral.hpp>
#include <limits>
#include <iostream>
#include <typeinfo>

namespace ft {

	template <typename T, class Compare,
			class Node = ft::node<T>, class Allocator = std::allocator<Node> >
	class RBT {

	public:
		typedef T                                           value_type;
		typedef Compare                                     value_compare;
		typedef Allocator                                   allocator_type;
		typedef Node                                        node_type;
		typedef typename allocator_type::reference          reference;
		typedef typename allocator_type::const_reference    const_reference;
		typedef typename allocator_type::pointer            pointer;
		typedef typename allocator_type::const_pointer      const_pointer;
		typedef typename allocator_type::difference_type    difference_type;
		typedef typename allocator_type::size_type          size_type;


	public:
		RBT(value_compare const& cmp = value_compare()) :
			_cmp(cmp)
		{
			_end = allocator_type().allocate(1);
			allocator_type().construct(_end, node_type());
			_root = _end;
		}

		~RBT() {}

		pointer		min(pointer s) const
		{
			if (s == NULL || s == _end)
				return _end;
			for ( ; s->left != _end; s = s->left);
			return s;
		}

		pointer		min() const { return min(_root); }

		pointer		max(pointer s) const
		{
			if (s == NULL || s == _end)
				return _end;
			for ( ; s->right != _end; s = s->right);
			return s;
		}

		pointer		max() const { return max(_root); }

		size_type	size(pointer s) const
		{
			if (s == _end)
				return 0;
			return size(s->right) + size(s->left) + 1;
		}

		size_type	size()                        const { return size(_root); }
		size_type	max_size()                    const { return allocator_type().max_size(); }
		pointer		search(const value_type& key) const { return __search_wrapper(_root, key); }

		pointer		successor(pointer s) const
		{
			if (s->right != _end)
				return min(s->right);
			if (s->parent == NULL || s == max())
				return _end;

			pointer	tmp = s->parent;
			while (tmp != _end && s == tmp->right)
			{
				s = tmp;
				tmp = tmp->parent;
			}
			return tmp;
		}

		pointer		predecessor(pointer s) const
		{
			if (s->left != _end)
				return max(s->left);
			if (s->parent == NULL || s == min())
				return _end;

			pointer	tmp = s->parent;
			while (tmp != _end && s == tmp->left)
			{
				s = tmp;
				tmp = tmp->parent;
			}
			return tmp;
		}

		bool	insert(const value_type& key)
		{
			pointer	y = NULL;
			pointer	x = _root;

			pointer	s = allocator_type().allocate(1);
			allocator_type().construct(s, node_type(key, R_N, NULL, _end, _end));

			while (x != _end)
			{
				y = x;
				if (_cmp(s->data, x->data))
					x = x->left;
				else if (_cmp(x->data, s->data))
					x = x->right;
				else
				{
					allocator_type().destroy(s);
					allocator_type().deallocate(s, 1);
					return false;
				}
			}

			s->parent = y;
			if (y == NULL)
				_root = s;
			else if (_cmp(s->data, y->data))
				y->left = s;
			else
				y->right = s;

			if (s->parent == NULL)
			{
				s->color = B_N;
				return true;
			}

			if (s->parent->parent == NULL)
				return true;

			_fix_insertion(s);
			return true;
		}

		pointer		get_root() const { return _root; }
		pointer		get_end() const { return _end; }

		bool	delete_node(const value_type& key)
		{ return __delete_node_wrapper(_root, key); }

		void		destroy()
		{
			_destroy(_root);
			_root = _end;
		}

		void		destroy_end()
		{
			allocator_type().destroy(_end);
			allocator_type().deallocate(_end, 1);
		}

		pointer		lower_bound(const value_type& v) const
		{
			pointer	p = min();

			for ( ; p != _end; p = successor(p))
			{
				if (!_cmp(p->data, v))
					break ;
			}
			return p;
		}

		pointer		upper_bound(const value_type& v) const
		{
			pointer	p = min();

			for ( ; p != _end; p = successor(p))
			{
				if (_cmp(v, p->data))
					break ;
			}
			return p;
		}

		void		swap(RBT& ref)
		{
			pointer			tmp_root = _root;
			pointer			tmp_end = _end;


			_root = ref.get_root();
			_end = ref.get_end();
			ref._root = tmp_root;
			ref._end = tmp_end;
		}


	private:
		pointer		__search_wrapper(pointer node, const value_type& key) const
		{
			if (node == _end)
				return node;
			else if (_cmp(key, node->data))
				return __search_wrapper(node->left, key);
			else if (_cmp(node->data, key))
				return __search_wrapper(node->right, key);
			else
				return node;
		}

		void		_left_rotate(pointer s)
		{
			pointer	tmp = s->right;

			s->right = tmp->left;
			if (tmp->left != _end)
				tmp->left->parent = s;
			tmp->parent = s->parent;
			if (s->parent == NULL)
				_root = tmp;
			else if (s == s->parent->left)
				s->parent->left = tmp;
			else
				s->parent->right = tmp;
			tmp->left = s;
			s->parent = tmp;
		}

		void		_right_rotate(pointer x)
		{
			pointer	y = x->left;

			x->left = y->right;
			if (y->right != _end)
				y->right->parent = x;
			y->parent = x->parent;
			if (x->parent == NULL)
				_root = y;
			else if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;
			y->right = x;
			x->parent = y;
		}

		void		_fix_insertion(pointer k)
		{
			pointer	u;

			while (k->parent->color == R_N)
			{
				if (k->parent == k->parent->parent->right)
				{
					u = k->parent->parent->left;
					if (u->color == R_N)
					{
						u->color = B_N;
						k->parent->color = B_N;
						k->parent->parent->color = R_N;
						k = k->parent->parent;
					}
					else
					{
						if (k == k->parent->left)
						{
							k = k->parent;
							_right_rotate(k);
						}
						k->parent->color = B_N;
						k->parent->parent->color = R_N;
						_left_rotate(k->parent->parent);
					}
				}
				else
				{
					u = k->parent->parent->right;
					if (u->color == R_N)
					{
						u->color = B_N;
						k->parent->color = B_N;
						k->parent->parent->color = R_N;
						k = k->parent->parent;
					}
					else
					{
						if (k == k->parent->right)
						{
							k = k->parent;
							_left_rotate(k);
						}
						k->parent->color = B_N;
						k->parent->parent->color = R_N;
						_right_rotate(k->parent->parent);
					}
				}
				if (k == _root)
					break ;
			}
			_root->color = B_N;
		}

		void		_fix_delete(pointer x)
		{
			pointer	s;

			while (x != _root && x->color == B_N)
			{
				if (x == x->parent->left)
				{
					s = x->parent->right;
					if (s->color == R_N)
					{
						s->color = B_N;
						x->parent->color = R_N;
						_left_rotate(x->parent);
						s = x->parent->right;
					}

					if (s->left->color == B_N && s->right->color == B_N)
					{
						s->color = R_N;
						x = x->parent;
					}
					else
					{
						if (s->right->color == B_N)
						{
							s->left->color = B_N;
							s->color = R_N;
							_right_rotate(s);
							s = x->parent->right;
						}
						s->color = x->parent->color;
						x->parent->color = B_N;
						s->right->color = B_N;
						_left_rotate(x->parent);
						x = _root;
					}
				}
				else
				{
					s = x->parent->left;
					if (s->color == R_N)
					{
						s->color = B_N;
						x->parent->color = R_N;
						_right_rotate(x->parent);
						s = x->parent->left;
					}

					if (s->left->color == B_N && s->right->color == B_N)
					{
						s->color = R_N;
						x = x->parent;
					}
					else
					{
						if (s->left->color == B_N)
						{
							s->right->color = B_N;
							s->color = R_N;
							_left_rotate(s);
							s = x->parent->left;
						}
						s->color = x->parent->color;
						x->parent->color = B_N;
						s->left->color = B_N;
						_right_rotate(x->parent);
						x = _root;
					}
				}
			}
			x->color = B_N;
		}

		void		_rb_transplant(pointer u, pointer v)
		{
			if (u->parent == NULL)
				_root = v;
			else if (u == u->parent->left)
				u->parent->left = v;
			else
				u->parent->right = v;
			v->parent = u->parent;
		}

		bool	__delete_node_wrapper(pointer node, const value_type& key)
		{
			pointer	z = _end;
			pointer	x;
			pointer	y;

			while (node != _end)
			{
				if (_cmp(node->data, key))
					node = node->right;
				else if (_cmp(key, node->data))
					node = node->left;
				else
				{
					z = node;
					node = node->right;
				}
			}

			if (z == _end) // if the key doesn't exist
				return false;

			y = z;
			int	y_original_color = y->color;
			if (z->left == _end)
			{
				x = z->right;
				_rb_transplant(z, z->right);
			}
			else if (z->right == _end)
			{
				x = z->left;
				_rb_transplant(z, z->left);
			}
			else
			{
				y = min(z->right);
				y_original_color = y->color;
				x = y->right;

				if (y->parent == z)
					x->parent = y;
				else
				{
					_rb_transplant(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}
				_rb_transplant(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->color = z->color;
			}

			allocator_type().destroy(z);
			allocator_type().deallocate(z, 1);

			if (y_original_color == B_N)
				_fix_delete(x);
			return true;
		}

		void		_destroy(pointer root)
		{
			if (root == _end)
				return ;
			_destroy(root->left);
			_destroy(root->right);
			allocator_type().destroy(root);
			allocator_type().deallocate(root, 1);
		}


	private:
		value_compare	_cmp;
		pointer			_root;
		pointer			_end;
	};

};

#endif
