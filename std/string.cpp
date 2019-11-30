#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "string.hpp"

namespace std
{

int string::size()
{
	return 0;
}

int string::length()
{
	return 0;
}

int string::max_size()
{
	return 0;
}

void string::resize(int n, char c)
{
}

void string::resize(int n)
{
}

int string::capacity()
{
	return 0;
}

void string::reserve(int param2)
{
}

void string::clear()
{
}

bool string::empty()
{
	return false;
}

string& string::append(string& str)
{
	return *this;
}

void string::append(string str, int pos, int n)
{
}

void string::append(char* s, int n)
{
}

void string::append(char* s)
{
}

void string::append(int n, char c)
{
}

void string::push_back(char c)
{
}

void string::assign(string& str)
{
}

void string::assign(string& str, int pos, int n)
{
}

void string::insert(int pos1, string& str)
{
}

void string::erase(int pos, int n)
{
}

string& string::replace(int pos1, int n1, string& str)
{
	return *this;
}

int string::copy(char* s, int n, int pos)
{
	return 0;
}

void string::swap(string& str)
{
}
}  // namespace std
