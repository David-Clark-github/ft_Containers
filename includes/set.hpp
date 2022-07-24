/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <dclark@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 23:12:04 by david             #+#    #+#             */
/*   Updated: 2022/07/24 15:27:56 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include <node.hpp>
#include <node_iterator.hpp>
#include <RBT.hpp>
#include <binary_function.hpp>
#include <enable_if.hpp>
#include <equal_lexico_comp.hpp>
#include <is_integral.hpp>
#include <iterator_traits.hpp>
#include <reverse_iterator.hpp>

#define UNUSED __attribute__((unused)) 

namespace ft {
	
	template < class T, class Compare = ft::less<T>, class Alloc = std::allocator<T> >
	class set {
		public:

			/*-------- [MEMBER TYPES] --------*/

			typedef			 	T															key_type;
			typedef 			T															value_type;
			typedef 			Compare														key_compare;
			typedef 			Compare														value_compare;
			typedef 			Alloc														allocator_type;
			typedef	typename	allocator_type::reference									reference;
			typedef	typename	allocator_type::const_reference								const_reference;
			typedef	typename	allocator_type::pointer										pointer;
			typedef	typename	allocator_type::const_pointer								const_pointer;
			typedef	typename	allocator_type::size_type									size_type;
			typedef	typename	allocator_type::difference_type								difference_type;
			typedef				ft::node_iterator<const value_type, ft::node<value_type> >		iterator;
			typedef				ft::node_iterator<const value_type, ft::node<value_type> >	const_iterator;
			typedef				ft::reverse_iterator<iterator>								reverse_iterator;
			typedef				ft::reverse_iterator<const_iterator>						const_reverse_iterator;

			/*-------- [MEMBER FUNCTIONS] --------*/

			/*-------- Constructor / Destructor --------*/
			
			// Constructor
			explicit set (const key_compare& comp = key_compare(), UNUSED const allocator_type& alloc = allocator_type())
			: _rbt(value_compare(comp)) {}

			template <class InputIterator>
			set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
			UNUSED const allocator_type& alloc = allocator_type())
			: _rbt(value_compare(comp)) {
				insert(first, last);
			}

			set (const set& x) : _rbt(value_compare(key_compare())) {
				insert(x.begin(), x.end());
			}

			// Destructor
			~set() {
				clear();
				_rbt.destroy_end();
			}

			// operator=
			set& operator= (const set& x) {
				if (&x != this) {
					clear();
					insert(x.begin(), x.end());
				}
				return (*this);
			}

			/*-------- Iterators --------*/

			// begin
			iterator		begin() {
				return (iterator(_rbt.get_root(), _rbt.get_end(), _rbt.min()));
			}

			const_iterator	begin() const {
				return (const_iterator(_rbt.get_root(), _rbt.get_end(), _rbt.min()));
			}

			// end
			iterator		end() {
				return (iterator(_rbt.get_root(), _rbt.get_end(), _rbt.get_end()));
			}

			const_iterator	end() const {
				return (const_iterator(_rbt.get_root(), _rbt.get_end(), _rbt.get_end()));
			}

			// rbegin
			reverse_iterator		rbegin() {
				return (reverse_iterator(end()));
			}

			const_reverse_iterator	rbegin() const {
				return (const_reverse_iterator(end()));
			}

			// rend
			reverse_iterator		rend() {
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

			/*-------- Modifiers --------*/

			// insert
			ft::pair<iterator,bool>	insert(const value_type &val) {
				const bool b = _rbt.insert(val);
				return (ft::make_pair(find(val), b));
			}

			iterator	insert(UNUSED iterator position, const value_type &val) {
				insert(val);
				return find(val);
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last) {
				for (; first != last; ++first)
					insert(*first);
			}

			// erase
			void erase (iterator position) {
				erase(*position);				
			}

			size_type erase (const value_type& val) {
				return (_rbt.delete_node(val));
			}

			void erase (iterator first, iterator last) {
				while (first != last) {
					first = find(*first);
					erase(first++);
				}
			}

			// swap
			void swap (set& x) {
				_rbt.swap(x._rbt);
			}

			// clear
			void clear() {
				return (_rbt.destroy());
			}

			/*-------- Observers --------*/

			// key_comp
			key_compare key_comp() const {
				return (key_compare());
			}

			// value_comp
			value_compare value_comp() const {
				return (value_compare());
			}

			/*-------- Opearations --------*/

			// find
			iterator find (const value_type& val) const {
				return (iterator(_rbt.get_root(), _rbt.get_end(), _rbt.search(val)));
			}

			// count
			size_type count (const value_type& val) const {
				return (find(val) != end());
			}

			// lower_bound
			iterator lower_bound (const value_type& val) {
				return (iterator(_rbt.get_root(), _rbt.get_end(), _rbt.lower_bound(val)));
			}

			const_iterator lower_bound (const value_type& val) const {
				return (const_iterator(_rbt.get_root(), _rbt.get_end(), _rbt.lower_bound(val)));
			}

			// upper_bound
			iterator upper_bound (const value_type& val) {
				return (iterator(_rbt.get_root(), _rbt.get_end(), _rbt.upper_bound(val)));
			}

			const_iterator upper_bound (const value_type& val) const {
				return (const_iterator(_rbt.get_root(), _rbt.get_end(), _rbt.upper_bound(val)));
			}

			//equal_range
			ft::pair<iterator,iterator> equal_range (const value_type& val) {
				return (ft::make_pair(lower_bound(val), upper_bound(val)));
			}

			ft::pair<const_iterator,const_iterator> equal_range (const value_type& val) const {
				return (ft::make_pair(lower_bound(val), upper_bound(val)));
			}

			// get_allocator
			allocator_type get_allocator() const {
				return (allocator_type());
			}



		private:
			ft::RBT<value_type, value_compare>	_rbt;

	};

	template< class Key, class Compare, class Alloc >
	void swap( ft::set<Key,Compare,Alloc>& lhs, ft::set<Key,Compare,Alloc>& rhs ) {
		lhs.swap(rhs);
	}

	template< class Key, class Compare, class Alloc >
	bool operator==( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs ) {
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template< class Key, class Compare, class Alloc >
	bool operator!=( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs ) {
		return !(lhs == rhs);
	}

	template< class Key, class Compare, class Alloc >
	bool operator<( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs ) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template< class Key, class Compare, class Alloc >
	bool operator<=( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs ) {
		return !(rhs < lhs);
	}

	template< class Key, class Compare, class Alloc >
	bool operator>( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs ) {
		return (rhs < lhs);
	}

	template< class Key, class Compare, class Alloc >
	bool operator>=( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs ) {
		return !(lhs < rhs);
	}

};

#endif
