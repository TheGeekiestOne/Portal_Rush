#ifndef STD_QUEUE_H
#define STD_QUEUE_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

namespace std
{
template <class T, class Container=deque<T,allocator<T>>>
class queue
{
public:
	boolean empty();

	int size();

	T top();

	void push(T& x);

	void pop();

};

}  // namespace std
#endif
