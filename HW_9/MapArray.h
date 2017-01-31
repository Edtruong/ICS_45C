#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


class MapArray
{
private:
	int len;
	int count;
	pair<string, int> * buf;

public:
	struct iterator
	{
		typedef std::forward_iterator_tag iterator_category;
		typedef iterator self_type;
		typedef pair<string, int> value_type;
		typedef pair<string, int>& reference;
		typedef pair<string, int>* pointer;
		typedef ptrdiff_t difference_type;
	private:
		pointer buf;
	public:
		iterator(pointer ptr) : buf(ptr) { }
		self_type operator++() { ++buf; return *this; }
		self_type operator++(int postfix) { self_type cpy = *this; buf++; return cpy; }
		reference operator*() { return *buf; }
		pointer operator->() { return buf; }
		bool operator==(const self_type& rhs) const { return buf == rhs.buf; }
		bool operator!=(const self_type& rhs) const { return buf != rhs.buf; }
	};
//////////////////////////	
	struct const_iterator
	{
	public:
		typedef std::forward_iterator_tag iterator_category;
		typedef const_iterator self_type;
		typedef pair<string, int> value_type;
		typedef pair<string, int>& reference;
		typedef pair<string, int>* pointer;
		typedef ptrdiff_t difference_type;
	private:
		pointer buf;
	public:
		const_iterator(pointer ptr) : buf(ptr) { }
		self_type operator++() { ++buf; return *this; }
		self_type operator++(int postfix) { self_type cpy = *this; buf++; return cpy; }
		const reference operator*() { return *buf; }
		const pointer operator->() { return buf; }
		bool operator==(const self_type& rhs) const { return buf == rhs.buf; }
		bool operator!=(const self_type& rhs) const { return buf != rhs.buf; }
	};
///////////////////// MapArray memeber functions
	MapArray(int size)
	{
		len = size;
		count = 0;
		buf = new pair<string, int>[size];
	}
	int size() const
	{
		return count;
	}
	int find(string & s)
	{
		for(int i = 0; i < count; i++)
		{
			if(buf[i].first == s)
				return i;
		}
		return -1;
	}
	int & operator [](string s)
	{
		int i = find(s);
		if(i != -1)
		{
			return buf[i].second;
		}
		buf[count] = make_pair(s, 0);
		int temp = count;
		++count;
		return buf[temp].second;
	}
	iterator begin()
	{
		return iterator(buf);
	}
	iterator end()
	{
		return iterator(buf + count);
	}
	const_iterator begin() const
	{
		return const_iterator(buf);
	}
	const_iterator end() const
	{
		return const_iterator(buf + count);
	}
	pair<string, int> & operator [] (int index)
	{
		return buf[index];
	}
	const pair<string, int> & operator [] (int index) const
	{
		return buf[index];
	}
	~MapArray()
	{
		delete[] buf;
	}
};
