#ifndef STD_STRING_H
#define STD_STRING_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

namespace std
{
template <char T>
class string
{
public:
	int size();

	int length();

	int max_size();

	void resize(int n, char c);

	void resize(int n);

	int capacity();

	void reserve(int param2);

	void clear();

	bool empty();

	string& append(string& str);

	void append(string str, int pos, int n);

	void append(char* s, int n);

	void append(char* s);

	void append(int n, char c);

	void push_back(char c);

	void assign(string& str);

	void assign(string& str, int pos, int n);

	void insert(int pos1, string& str);

	void erase(int pos, int n);

	string& replace(int pos1, int n1, string& str);

	int copy(char* s, int n, int pos);

	void swap(string& str);

};

}  // namespace std
#endif
