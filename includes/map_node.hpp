/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_node.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:37:58 by dclark            #+#    #+#             */
/*   Updated: 2022/07/02 23:11:45 by david            ###   ########.fr       */
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
		value_type	value;
	};

	/*-------- Destructor / Constructor --------*/
	Node(T t, Node* l, Node* r, int h, value_type val)
	: left(l), right(r), height(h), value_type(val) {}

	~Node() {}

};

#endif
