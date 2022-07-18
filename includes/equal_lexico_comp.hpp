/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal_lexico_comp.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:40:29 by dclark            #+#    #+#             */
/*   Updated: 2022/07/18 23:58:01 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_LEXICO_COMP_HPP
#define EQUAL_LEXICO_COMP_HPP

namespace ft {

	/*-------- FT_EQUAL --------*/

	//equality
	template <class It1, class It2>
	bool equal(It1 first1, It1 last1, It2 first2) {
		while (first1 != last1) {
			if (!(*first1 == *first2))
				return (false);
			first1++;
			first2++;
		}
		return (true);
	}

	//predicate
	template <class It1, class It2, class BinarP>
	bool equal(It1 first1, It1 last1, It2 first2, BinarP pred) {
		while (first1 != last1) {
			if (!pred(*first1, *first2))
				return (false);
			first1++;
			first2++;
		}
		return (true);
	}

	/*-------- FT_LEXICOGRAPHICAL_COMPARE --------*/

	//default
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	//custom
	template <class InputIterator1, class InputIterator2, class Compare>
 	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (!comp(*first1, *first2))
				return false;
			first1++;
			first2++;
		}
		return true;
	};

};

#endif
