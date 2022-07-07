/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:37:58 by dclark            #+#    #+#             */
/*   Updated: 2022/07/07 18:18:35 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

#include <pair.hpp>
#include <map.hpp>

namespace ft {

	template <typename T>
	struct Node {
		T			data;
		Node		*left;
		Node		*right;
		Node		*parent;
		int			color;

	/*-------- Destructor / Constructor --------*/
		Node(T d, Node* l, Node* r, Node *p, int c)
			: data(d), left(l), right(r), parent(p), color(c) {}

		~Node() {}

		template<typename T>
		Node	*insert()
	};

	template <typename T,
			class Compare,
			class Node = ft::Node<T>,
			class Allocator = std::alocator<Node>>
	class RB_tree {
		public:
			typedef	T		value_type;
			typedef Compare	value_compare;

	};


};

#endif
