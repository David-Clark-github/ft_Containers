/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 10:04:35 by david             #+#    #+#             */
/*   Updated: 2022/06/18 10:11:14 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
#define FT_STACK_H

#include <ft_vector.h>

namespace ft {
	template <class T, class Container = ft::vector<T> >
	class stack {
		/*-------- Member types --------*/
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

		/*-------- Constructor --------*/
		explicit stack (const container_type& ctnr = container_type()) {
			
		}
	}
}

#endif
