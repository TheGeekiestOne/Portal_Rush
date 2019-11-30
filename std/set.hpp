#ifndef STD_SET_H
#define STD_SET_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "std/iterator.hpp"
#include "std/pair.hpp"
#include "std/allocator.hpp"

namespace std
{
template <class key, class Compare=less<key>, class Allocator=allocator<key>>
class set
{
public:
	multimap();

	~multimap();

	operator=();

	iterator begin();

	iterator end();

	iterator rbegin();

	iterator rend();

	boolean empty() const;

	int size() const;

	int max_size() const;

	iterator insert(iterator position, key& x);

	iterator insert(iterator position, int n, key& x);

	void erase(iterator position );

	void erase(iterator first, iterator last);

	void swap(set& vec);

	void clear();

	Compare key_comp();

	Compare value_comp();

	iterator find();

	int count();

	iterator lower_bound();

	iterator upper_bound();

	pair<iterator,iterator> equal_range();

	allocator get_allocator();

};

}  // namespace std
#endif
