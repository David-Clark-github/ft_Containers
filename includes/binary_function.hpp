/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_function.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:50:03 by david             #+#    #+#             */
/*   Updated: 2022/06/28 11:38:36 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BINARY_FUNCTION_HPP
#define FT_BINARY_FUNCTION_HPP

namespace ft {

	/*-------- Binary_function --------*/
	template <class Arg1, class Arg2, class Result> 
	struct binary_function {
		typedef	Arg1	first_argument_type;
		typedef	Arg2	second_argument_type;
		typedef	Result	result_type;
	};

	/*-------- equal_to --------*/
	template <class T>
	struct equal_to : ft::binary_function <T, T, bool> {
		bool operator() (const T& x, const T& y) const {return (x == y);}
	};


	/*-------- not_equal_to --------*/
	template <class T>
	struct not_equal_to : ft::binary_function <T, T, bool> {
		bool operator() (const T& x, const T& y) const {return (x != y);}
	};

	/*-------- less --------*/
	template <class T>
	struct less : ft::binary_function <T, T, bool> {
		bool operator() (const T& x, const T& y) const {return (x < y);}
	};

	/*-------- less_equal --------*/
	template <class T>
	struct less_equal : ft::binary_function <T, T, bool> {
		bool operator() (const T& x, const T& y) const {return (x <= y);}
	};

	/*-------- greater --------*/
	template <class T>
	struct greater : ft::binary_function <T, T, bool> {
		bool operator() (const T& x, const T& y) const {return (x > y);}
	};

	/*-------- greater_equal --------*/
	template <class T>
	struct greater_equal : ft::binary_function <T, T, bool> {
		bool operator() (const T& x, const T& y) const {return (x >= y);}
	};

};

#endif
