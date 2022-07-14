/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:51:52 by david             #+#    #+#             */
/*   Updated: 2022/07/11 16:06:44 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <pair.hpp>
#include <binary_function.hpp>
#include <node_iterator.hpp>
#include <node.hpp>
#include <iterator_traits.hpp>
#include <reverse_iterator.hpp>
#include <enable_if.hpp>
#include <is_integral.hpp>

namespace ft {

	template < class Key,
		class T,
		class Compare = ft::less<Key>,
		class Allocator = std::allocator<ft::pair<const Key,T>> >
	class map {
		public:
			/*-------- [MEMBER_TYPES] --------*/
			typedef			 	Key														key_type;
			typedef 			T														mapped_type;
			typedef 			ft::pair<const key_type, mapped_type>					value_type;
			typedef 			Compare													key_compare;
			typedef 			Allocator												allocator_type;
			typedef	typename	allocator_type::reference								reference;
			typedef	typename	allocator_type::const_reference							const_reference;
			typedef	typename	allocator_type::pointer									pointer;
			typedef	typename	allocator_type::const_pointer							const_pointer;
			typedef				ft::RBT<value_type, ft::Node<value_type>>		iterator;
			typedef				ft::node_iterator<const value_type, ft::Node<value_type>>	const_iterator;
			typedef				ft::reverse_iterator<iterator>							reverse_iterator;
			typedef				ft::reverse_iterator<const_iterator>					const_reverse_iterator;
			typedef	typename	ft::iterator_traits<iterator>::difference_type			difference_type;
			typedef				size_t													size_type;

			/*-------- [MEMBER CLASSES] --------*/
			// Value Compare
			class value_compare : ft::binary_function<value_type, value_type, bool>
			{
				friend class map;

				protected:
					key_compare	comp;
					value_compare(key_compare c) : comp(c) {}

				public:
					bool operator()(const value_type& lhs, const value_type& rhs) const {
						return (comp(lhs.first, rhs.first));
					}
			};

			/*-------- [MEMBER FUNCTIONS] --------*/

			/* -------- Constructor / Destructor -------- */

			// empty
			explicit map(const key_compare &comp = key_compare(),
						const allocator_type &alloc = allocator_type()) 
			: _alloc(alloc), _begin(NULL), _end(NULL), _size(0) {}

			// range
			template<class InputIterator>
			map (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
			InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) {
				difference_type	n = std::distance(first, last);
				_begin = _alloc.allocate(n);
				_end = _begin;
				insert(first, last);
			}

			// copy
			map (const map &m) {
				// FILL HERE
			}

			// operator=
			map	&operator=(const map &m) {
				if (&m != this) {
					clear();
					insert(m.begin(), m.end());
				}
				return (*this);
			}

			/*-------- Iterators --------*/

			// begin
			iterator	begin() {
				return (_begin);
			}

			const_iterator	begin()const {
				return (_begin);
			}

			// end
			iterator	end() {
				return (_end);
			}

			const_iterator end()const {
				return (_end);
			}

			// rbegin
			reverse_iterator	rbegin() {
				return (_end);
			}

			const_reverse_iterator	rbegin()const {
				return (_end);
			}

			// rend
			reverse_iterator	rend() {
				return (_begin);
			}

			const_reverse_iterator	rend()const {
				return (_begin);
			}

			/*-------- Capacity --------*/

			// empty
			bool empty()const {
				if (size())
					return (false);
				return (true);
			}

			// size
			size_type size()const {
				return (_size);
			}

			// max_size
			size_type max_size()const {
				return (_alloc.max_size())
			}

			/*-------- Element access --------*/

			// operator[]
			mapped_type& operator[](const key_type& k) {
				insert(ft::make_pair(k, mapped_type()));
				return (find(k).second)
			}
			
			/*-------- Modifiers --------*/

			/* insert */

			// single element
			ft::pair<iterator,bool>	insert(const value_type& val) {
				// FILL WITH TREE AVL
			}

			// with hint
			iterator	insert(iterator position, const value_type& val) {
				// FILL WITH TREE AVL
			}

			// range
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last) {
				// FILL WITH TREE AVL
			}



		private:
			allocator_type	_alloc;
			pointer			_root;
			pointer			_begin;
			pointer			_end;
			size_type		_size;
	};

};

#endif
