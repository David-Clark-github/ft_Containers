/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 18:42:05 by dclark            #+#    #+#             */
/*   Updated: 2022/06/30 10:53:06 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

namespace ft {

	template <class T, T v>
	struct	integral_constant {
		typedef 		T							value_type;
		typedef			ft::integral_constant<T, v>	type;
		static const	T							value = v;
		operator const value_type() {return value;}
	};

	typedef	ft::integral_constant<bool, true>	true_type;
	typedef	ft::integral_constant<bool, false>	false_type;
	
	template <class T>
	struct is_integral							: public false_type {};

	template <>
	struct is_integral<bool>					: public true_type {};

	template <>
	struct is_integral<char>					: public true_type {};

	template <>
	struct is_integral<char16_t>				: public true_type {};

	template <>
	struct is_integral<char32_t>				: public true_type {};

	template <>
	struct is_integral<wchar_t>					: public true_type {};

	template <>
	struct is_integral<signed char>				: public true_type {};

	template <>
	struct is_integral<short int>				: public true_type {};

	template <>
	struct is_integral<int>						: public true_type {};

	template <>
	struct is_integral<long int>				: public true_type {};

	template <>
	struct is_integral<long long int>			: public true_type {};

	template <>
	struct is_integral<unsigned char>			: public true_type {};

	template <>
	struct is_integral<unsigned short int>		: public true_type {};

	template <>
	struct is_integral<unsigned int>			: public true_type {};

	template <>
	struct is_integral<unsigned long int>		: public true_type {};

	template <>
	struct is_integral<unsigned long long int>	: public true_type {};

};

#endif
