/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pair.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:13:48 by dclark            #+#    #+#             */
/*   Updated: 2022/06/02 13:56:55 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft {
	template <class T1, class T2>
	struct pair {
		using	first_type	=	T1;
		using	second_type	=	T2;

		/*-------- Constructor --------*/

		/* Default */
		pair(void)
		:first(), second() {}

		/* Copy */
		template< class U1, class U2 >
		pair( const pair<U1, U2>& p ) {
			this->first = p.first;
			this->second = p.second;
		}

		/* Initialization */
		pair( const first_type& a, const second_type& b)
		:first(a), second(b) {}

		/*-------- Operators --------*/

		pair& operator=(const pair &p) {
			if (this != &p) {
				this->first = p.first;
				this->second = p.second;
			}
			return (*this);
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
		return ((p1.first != p2.first) && (p1.second != p2.second));
	}

	template <class T1, class T2>
	bool operator<(const pair<T1, T2> &p1, const pair<T1, T2> &p2) {
		return ((p1.first < p2.first) && (p1.second < p2.second));
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1, T2> &p1, const pair<T1, T2> &p2) {
		return ((p1.first <= p2.first) && (p1.second <= p2.second));
	}

	template <class T1, class T2>
	bool operator>(const pair<T1, T2> &p1, const pair<T1, T2> &p2) {
		return ((p1.first > p2.first) && (p1.second > p2.second));
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1, T2> &p1, const pair<T1, T2> &p2) {
		return ((p1.first >= p2.first) && (p1.second >= p2.second));
	}

	/*-------- MAKE_PAIR --------*/

	template <class T1, class T2>
	ft::pair<T1, T2> make_pair(T1 a, T2 b) {
		return (ft::pair<T1, T2>(a, b));
	}
};
