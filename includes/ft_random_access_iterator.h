/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random_access_iterator.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:39:42 by david             #+#    #+#             */
/*   Updated: 2022/06/05 21:42:19 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RANDOM_ACCESS_ITERATOR_H
#define FT_RANDOM_ACCESS_ITERATOR_H

#include <ft_iterator.h>

namespace ft {

	struct input_iterator_tag  {};
	struct output_iterator_tag {};
	struct forward_iterator_tag       : public input_iterator_tag         {};
	struct bidirectional_iterator_tag : public forward_iterator_tag       {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template<class I>
	class random_access_iterator : iterator<random_access_iterator_tag, I> {
		public :
			typedef typename ft::iterator<random_access_iterator_tag, I>::value_type		value_type;
			typedef typename ft::iterator<random_access_iterator_tag, I>::difference_type	difference_type;
			typedef typename ft::iterator<random_access_iterator_tag, I>::pointer			pointer;
			typedef typename ft::iterator<random_access_iterator_tag, I>::reference			reference;
			typedef typename ft::iterator<random_access_iterator_tag, I>::iterator_category	iterator_category;
		private:
			pointer	_ptr;
			
	};

};

#endif
