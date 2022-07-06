/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_node.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:37:58 by dclark            #+#    #+#             */
/*   Updated: 2022/07/06 15:16:21 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_NODE_HPP
#define MAP_NODE_HPP

#include <pair.hpp>
#include <map.hpp>

namespace ft {

	template <typename T>
	struct Node {
		Node		*left;
		Node		*right;
		Node		*parent;
		int			height;
		T			pair;

	/*-------- Destructor / Constructor --------*/
	Node(T t, Node* l, Node* r, Node *p, int h)
	: pair(t), left(l), right(r), parent(p), height(h) {}

	~Node() {}

	template<typename T>
	Node	*insert()
	};

};

#endif
