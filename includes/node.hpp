/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:47:36 by david             #+#    #+#             */
/*   Updated: 2022/07/13 18:20:55 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

#define B_N	0
#define R_N	1

namespace ft {

	template<typename T>
	struct	node {
		typedef	T		value_type;
		typedef	node*	node_pointer;
		typedef	node&	node_reference;
		typedef	size_t	color_type;

		node_pointer	parent;
		node_pointer	left;
		node_pointer	right;
		color_type		color;
		value_type		data;

		node() : parent(nullptr), left(nullptr), right(nullptr), color(B_N), data() {}

		node(node_pointer p = nullptr,
			node_pointer l = nullptr,
			node_pointer r = nullptr,
			color_type c = B_N,
			const value_type d)
		: parent(p), left(l), right(r), color(c), data(d) {}

		node(const &node n)
		: parent(n.parent), left(n.left), right(n.right), color(n.color), data(n.data) {}

		~node() {}

		node_reference	operator=(const node &n) {
			if (this != &n) {
				parent	= n.parent;
				left	= n.left;
				right	= n.right;
				color	= n.color;
				data	= n.data;
			}
			return (*this);
		}

		bool	operator==(const node &n) {
			return (data == n.data);
		}
	};

};

#endif
