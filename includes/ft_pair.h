/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pair.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:13:48 by dclark            #+#    #+#             */
/*   Updated: 2022/05/25 14:29:33 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft {
	template <class T1, class T2>
	struct pair {
		using	first_type	=	T1;
		using	second_type	=	T2;

		/*-------- Constructor --------*/

		/*Default*/
		pair(void);

		/*Copy / Move*/
		template< class U1, class U2 >
		pair( const pair<U1, U2>& p ) {
			*this = p;
		}

		/*Initialization*/
		pair( const first_type& a, const second_type& b)
		:_first(a), _second(b) {}

		pair( const pair& p) = default;

		/*-------- Operators --------*/

		pair& operator=(const pair &p) {
			if (this != &p) {
				this->_first = p._first;
				this->_second = p._second;
			}
			return (*this);
		}

		bool operator==(const pair& p1, const pair& p2) {
			return ((p1._first == p2._first) && (p1._second == p2._second));
		}

		bool operator!=(const pair& p1, const pair& p2) {
			return ((p1._first != p2._first) && (p1._second != p2._second));
		}

		bool operator<(const pair& p1, const pair& p2) {
			return ((p1._first < p2._first) && (p1._second < p2._second));
		}

		bool operator<=(const pair& p1, const pair& p2) {
			return ((p1._first <= p2._first) && (p1._second <= p2._second));
		}

		bool operator>(const pair& p1, const pair& p2) {
			return ((p1._first > p2._first) && (p1._second > p2._second));
		}

		bool operator>=(const pair& p1, const pair& p2) {
			return ((p1._first >= p2._first) && (p1._second >= p2._second));
		}

		friend pair<first_type, second_type> make_pair(first_type a, second_type b);

		/*-------- Member Objects --------*/
		first_type	_first;
		second_type	_second;
	};

	pair<first_type, second_type> make_pair(first_type a, second_type b) {
		return (pair<first_type, second_type>(a, b));
	}
};
