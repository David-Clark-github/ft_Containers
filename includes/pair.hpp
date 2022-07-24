/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:13:48 by dclark            #+#    #+#             */
/*   Updated: 2022/07/24 13:50:43 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft {
	template <class T1, class T2>
	struct pair {
		typedef	T1	first_type;
		typedef	T2	second_type;

		/*-------- Constructor --------*/

		/* Default */
		pair(void)
		:first(), second() {}

		/* Initialization */
		pair( const first_type& a, const second_type& b)
		:first(a), second(b) {}

		/* Copy */
		template<class U, class V>
		pair(const pair<U,V>& pr) : first(pr.first), second(pr.second) {}

		/*-------- Operators --------*/

		pair& operator=(const pair& p) {
			if (this != &p) {
				first = p.first;
				second = p.second;
			}
			return (*this);
		}

		operator	pair<const T1, const T2> (void) const {
			return pair<const T1, const T2>(first, second);
		}

		first_type	first;
		second_type	second;
	};

	template <class T1, class T2>
	bool operator==(const pair<T1, T2> &p1, const pair<T1, T2> &p2) {
		return ((p1.first == p2.first) && (p1.second == p2.second));
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1, T2> &p1, const pair<T1, T2> &p2) {
		return (!(p1 == p2));
	}

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& p1, const pair<T1,T2>& p2)
	{ return p1.first<p2.first || (!(p2.first<p1.first) && p1.second<p2.second); }


	template <class T1, class T2>
	bool operator<=(const pair<T1, T2> &p1, const pair<T1, T2> &p2) {
		return (!(p2 < p1));
	}

	template <class T1, class T2>
	bool operator>(const pair<T1, T2> &p1, const pair<T1, T2> &p2) {
		return (p2 < p1);
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1, T2> &p1, const pair<T1, T2> &p2) {
		return (!(p2 < p1));
	}

	/*-------- MAKE_PAIR --------*/

	template <class T1, class T2>
	ft::pair<T1, T2> make_pair(T1 a, T2 b) {
		return (ft::pair<T1, T2>(a, b));
	}
};

#endif
