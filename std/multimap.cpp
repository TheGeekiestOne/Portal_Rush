#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "multimap.hpp"

namespace std
{

multimap::multimap()
{
}

multimap::~multimap()
{
}

multimap::operator=()
{
}

iterator multimap::begin()
{
	return 0;
}

iterator multimap::end()
{
	return 0;
}

iterator multimap::rbegin()
{
	return 0;
}

iterator multimap::rend()
{
	return 0;
}

boolean multimap::empty() const
{
	return 0;
}

int multimap::size() const
{
	return 0;
}

int multimap::max_size() const
{
	return 0;
}

iterator multimap::insert(iterator position, key& x)
{
	return 0;
}

iterator multimap::insert(iterator position, int n, key& x)
{
	return 0;
}

void multimap::erase(iterator position )
{
}

void multimap::erase(iterator first, iterator last)
{
}

void multimap::swap(multimap& vec)
{
}

void multimap::clear()
{
}

template <class key, class T, class Compare=less<key>, class Allocator=allocator<pair<key,T>>>
 Compare multimap<key, T, Compare, Allocator>::key_comp()
{
	return 0;
}

template <class key, class T, class Compare=less<key>, class Allocator=allocator<pair<key,T>>>
 Compare multimap<key, T, Compare, Allocator>::value_comp()
{
	return 0;
}

iterator multimap::find()
{
	return 0;
}

int multimap::count()
{
	return 0;
}

iterator multimap::lower_bound()
{
	return 0;
}

iterator multimap::upper_bound()
{
	return 0;
}

pair<iterator,iterator> multimap::equal_range()
{
	return 0;
}

allocator multimap::get_allocator()
{
	return 0;
}
}  // namespace std
