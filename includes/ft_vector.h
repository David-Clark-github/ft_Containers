/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:49:13 by dclark            #+#    #+#             */
/*   Updated: 2022/05/17 15:33:09 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <>

namespace ft {
	template<class T, std::allocator<T>>
	class Vector {
		public:
		//Constructor (Surcharge de constructor ?)
				//Destructor (Surcharge de destructor ?)
			//Operator (=)

			/*-------- Iterators --------*/
			// begin
			// end
			// rbegin
			// rend

			/*-------- Capacity --------*/
			// size
			// max_size
			// resize
			// capacity
			// reserve

			/*-------- Element_access --------*/
			// operator ([])
			// at
			// front
			// back

			/*-------- Modifiers --------*/
			// assign
			// push_back
			// pop_back
			// insert
			// erase
			// swap
			// clear

			/*-------- Allocator --------*/
			// get_allocator

			/*-------- Non-member function overlords --------*/
			//relational operator
			//swap
	};
}
