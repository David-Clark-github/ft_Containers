/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterators_traits.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:20:36 by dclark            #+#    #+#             */
/*   Updated: 2022/05/23 15:27:10 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATORS_TRAITS
#define FT_ITERATORS_TRAITS

namespace ft {

	template	<class Iter>
	struct		iterator_traits {

	};

	template	<class T>
	struct		iterator_traits<T*>

};

#endif
