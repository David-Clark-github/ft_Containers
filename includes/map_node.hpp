/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_node.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:37:58 by dclark            #+#    #+#             */
/*   Updated: 2022/07/01 11:53:45 by dclark           ###   ########.fr       */
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
		int			height;
		value_type	value;
	};

};

#endif
