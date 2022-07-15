/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:51:52 by david             #+#    #+#             */
/*   Updated: 2022/07/15 23:52:31 by david            ###   ########.fr       */
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
#include <RBT.hpp>

#define UNUSED __attribute__((unused)) 

namespace ft {

	template < class Key,
		class T,
		class Compare = ft::less<Key>,
		class Allocator = std::allocator<ft::pair<const Key,T> > >
	class map {
		public:
			/*-------- [MEMBER_TYPES] --------*/
			typedef			 	Key															key_type;
			typedef 			T															mapped_type;
			typedef 			ft::pair<const key_type, mapped_type>						value_type;
			typedef 			Compare														key_compare;
			typedef 			Allocator													allocator_type;
			typedef	typename	allocator_type::reference									reference;
			typedef	typename	allocator_type::const_reference								const_reference;
			typedef	typename	allocator_type::pointer										pointer;
			typedef	typename	allocator_type::const_pointer								const_pointer;
			typedef	typename	allocator_type::size_type									size_type;
			typedef	typename	allocator_type::difference_type								difference_type;
			typedef				ft::node_iterator<value_type, ft::node<value_type> >			iterator;
			typedef				ft::node_iterator<const value_type, ft::node<value_type> >	const_iterator;
			typedef				ft::reverse_iterator<iterator>								reverse_iterator;
			typedef				ft::reverse_iterator<const_iterator>						const_reverse_iterator;

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
			explicit map(const key_compare &comp = key_compare(), UNUSED const allocator_type &alloc = allocator_type())
			: _rbt(value_compare(comp)) {}

			// range
			template<class InputIterator>
			map (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first,
			InputIterator last, const key_compare& comp = key_compare(),
			UNUSED const allocator_type& alloc = allocator_type())
			: _rbt(value_compare(comp)) {
				insert(first, last);
			}

			// copy
			map (const map &m) : _rbt(value_compare(key_compare())) {
				insert(m.begin(), m.end());
			}

			// Destructor
			~map(void) {
				clear();
				_rbt.destroy_end();
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
				return (iterator(_rbt.get_root(), _rbt.get_end(), _rbt.min()));
			}

			const_iterator	begin() const {
				return (const_iterator(_rbt.get_root(), _rbt.get_end(), _rbt.min()));
			}

			// end
			iterator	end() {
				return (iterator(_rbt.get_root(), _rbt.get_end(), _rbt.get_end()));
			}

			const_iterator end() const {
				return (const_iterator(_rbt.get_root(), _rbt.get_end(), _rbt.get_end()));
			}

			// rbegin
			reverse_iterator	rbegin() {
				return (reverse_iterator(end()));
			}

			const_reverse_iterator	rbegin() const {
				return (const_reverse_iterator(end()));
			}

			// rend
			reverse_iterator	rend() {
				return (reverse_iterator(begin()));
			}

			const_reverse_iterator	rend() const {
				return (const_reverse_iterator(begin()));
			}

			/*-------- Capacity --------*/

			// empty
			bool empty() const {
				if (size())
					return (false);
				return (true);
			}

			// size
			size_type size() const {
				return (_rbt.size());
			}

			// max_size
			size_type max_size() const {
				return (_rbt.max_size());
			}

			/*-------- Element access --------*/

			// operator[]
			mapped_type& operator[](const key_type &k) {
				insert(ft::make_pair(k, mapped_type()));
				return (find(k)->second);
			}
			
			/*-------- Modifiers --------*/

			/* insert */

			// single element
			ft::pair<iterator,bool>	insert(const value_type &val) {
				const bool r = _rbt.insert(val);
				return (ft::make_pair(find(val.first), r));
			}

			// with hint
			iterator	insert(UNUSED iterator position, const value_type &val) {
				insert(val);
				return find(val.first);
			}

			// range
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last) {
				for (; first != last; ++first)
					insert(*first);
			}

			/* erase */

			// earse
			void	erase(iterator position) {
				erase(position->first);
			}

			size_type	erase(const key_type &k) {
				return (_rbt.delete_node(ft::make_pair(k, mapped_type())));
			}

			void	erase(iterator first, iterator last) {
				while (first != last) {
					first = find(first->first);
					erase(first++);
				}
			}

			// swap
			void	swap(map &m) {
				_rbt.swap(m._rbt);
			}

			// clear
			void	clear(void) {
				return (_rbt.destroy());
			}
			
			/*-------- Observers --------*/

			// key_comp
			key_compare	key_comp() const {
				return (key_compare());
			}
			
			// value_comp
			value_compare value_comp() const {
				return (value_compare(key_comp()));
			}

			/*-------- Opearations --------*/

			// find
			iterator		find(const key_type& k) {
				return (iterator(_rbt.get_root(), _rbt.get_end(),
					_rbt.search(ft::make_pair(k, mapped_type()))));
			}

			const_iterator	find(const key_type& k) const {
				return (const_iterator(_rbt.get_root(), _rbt.get_end(),
					_rbt.search(ft::make_pair(k, mapped_type()))));
			}

			// count
			size_type count (const key_type &k) const {
				return (find(k) != end());
			}

			// lower_bound
			iterator lower_bound (const key_type &k) {
				return (iterator(_rbt.get_root(), _rbt.get_end(),
				_rbt.lower_bound(ft::make_pair(k, mapped_type()))));
			}

			const_iterator lower_bound (const key_type& k) const {
				return (const_iterator(_rbt.get_root(), _rbt.get_end(),
				_rbt.lower_bound(ft::make_pair(k, mapped_type()))));
			}

			// upper_bound
			iterator upper_bound (const key_type &k) {
				return (iterator(_rbt.get_root(), _rbt.get_end(),
				_rbt.upper_bound(ft::make_pair(k, mapped_type()))));
			}

			const_iterator upper_bound (const key_type& k) const {
				return (const_iterator(_rbt.get_root(), _rbt.get_last(),
				_rbt.upper_bound(ft::make_pair(k, mapped_type()))));
			}

			// equal_range
			pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}

			pair<iterator,iterator>             equal_range (const key_type& k) {
				return (ft::make_pair(lower_bound(k), upper_bound(k)));
			}

			/*-------- Allocator --------*/

			// get_allocator
			allocator_type get_allocator() const {
				return (allocator_type());
			}

		private:
			ft::RBT<value_type, value_compare>	_rbt;
	};

};

#endif
