/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_equal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:40:29 by dclark            #+#    #+#             */
/*   Updated: 2022/06/02 11:51:24 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EQUAL_H
#define FT_EQUAL_H

namespace ft {
	template <class It1, It2>
	bool equal(It1 first1; It1 last1; It2 first2) {
		while (first1 != last1) {
			if (!(*first1 == *first2))
				return false;
			first1++;
			first2++;
		}
		return true;
	}
};

#endif
