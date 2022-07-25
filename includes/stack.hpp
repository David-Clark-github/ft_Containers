/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 10:04:35 by david             #+#    #+#             */
/*   Updated: 2022/07/25 16:41:06 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include <vector.hpp>

namespace ft {
	template <class T, class Container = ft::vector<T> >
	class stack {
		public:
			/*-------- [MEMBER TYPES] --------*/
			typedef Container							container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef typename Container::reference		reference;
			typedef typename Container::const_reference	const_reference;

			/*-------- Constructor / Destructor --------*/
			explicit stack (const container_type& ctnr = container_type())
			: c(ctnr) {}
			
			~stack(void) {}

			stack	&operator=(const stack &s) {
				if (s != &s)
					c = s.c;
				return (*this);
			}

			/*-------- [MEMBER FUNCTIONS] --------*/

			// empty
			bool empty() const {
				return (c.empty());
			}

			// size
			size_type size() const {
				return (c.size());
			}

			// top
			reference top() {
				return (c.back());
			}

			const_reference top() const {
				return (c.back());
			}

			// push
			void push (const value_type& val) {
				c.push_back(val);
			}

			// pop
			void pop() {
				c.pop_back();
			}

			/*-------- [NON-MEMBER FUNCTION OVERLOADS] --------*/

			// ==
			friend bool operator== (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
				return lhs.c == rhs.c;
			}

			// !=
			friend bool operator!= (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
				return lhs.c != rhs.c;
			}

			// <
			friend bool operator<  (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
				return lhs.c < rhs.c;
			}

			// <=
			friend bool operator<= (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
				return lhs.c <= rhs.c;
			}

			// >
			friend bool operator> (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
				return lhs.c > rhs.c;
			}

			// >=
			friend bool operator>= (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
				return lhs.c >= rhs.c;
			}

		protected:
			container_type c;
	};
};

#endif
