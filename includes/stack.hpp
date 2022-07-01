/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 10:04:35 by david             #+#    #+#             */
/*   Updated: 2022/06/30 18:52:50 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include <vector.hpp>

namespace ft {
	template <class T, class Container = ft::vector<T> >
	class stack {
		public:
		/*-------- Member types --------*/
			typedef Container							container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef typename Container::reference		reference;
			typedef typename Container::const_reference	const_reference;

			/*-------- Constructor / Destructor --------*/
			explicit stack (const container_type& ctnr = container_type()) : c(ctnr) {}
			
			~stack(void) {}

			/*-------- Member functions --------*/
			bool empty() const {
				return (c.empty());
			}

			size_type size() const {
				return (c.size());
			}

			value_type& top() {
				return (c.back());
			}

			const value_type& top() const {
				return (c.back);
			}

			void push (const value_type& val) {
				c.push_back(val);
			}

			void pop() {
				c.pop_back();
			}

			/*-------- Non-member function overloads --------*/
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
			friend bool operator>  (const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
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
