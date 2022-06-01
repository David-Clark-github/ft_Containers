/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_integral.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:42:05 by dclark            #+#    #+#             */
/*   Updated: 2022/06/01 18:55:20 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IS_INTEGRAL_H
#define FT_IS_INTEGRAL_H

namespace ft {

	template <class T, T v>
	struct	integral_constant {
		ft::integral_constant<bool, true>	true_type;
		ft::integral_constant<bool, false>	false_type;
		T									value_type;
		ft::integral_constant<T, v>			type;
		value;

	};

	template <class T>
	struct is_integral : integral_constant {
		bool								value_type;
											value;
		ft::integral_constant<bool, value> type;
	};

};

#endif
