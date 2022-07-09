/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:37:58 by dclark            #+#    #+#             */
/*   Updated: 2022/07/09 20:10:09 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP

#include <pair.hpp>
#include <cstddef>

#define BLACK_N	0
#define RED_N	1

namespace ft {

	template <typename T>
	struct Node {
		T			data;
		Node		*left;
		Node		*right;
		Node		*parent;
		size_t		color;


		/*-------- Destructor / Constructor --------*/

		Node(void)
		: data(), left(nullptr), right(nullptr), parent(nullptr), color(BLACK_N) {}

		Node(const Node &n)
		: data(n.data), left(n.left), right(n.right), parent(n.parent), color(n.color) {}

		Node(const T& d, const size_t c = BLACK_N, Node *p = nullptr, Node *l = nullptr, Node *r = nullptr)
		: data(d), left(l), right(r), parent(p), color(c) {}

		~Node() {}

		Node	&operator=(const Node &n) {
			if (this != n) {
				data = n.data;
				left = n.left;
				right = n.right;
				parent = n.parent;
				color = n.color;
			}
			return (*this);
		}

		bool operator==(const Node &n) {
			if (data == n.data)
				return (true);
			return (false);
		}

	};

};

#endif
