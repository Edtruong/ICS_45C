#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <assert.h>
#include <iomanip>
#include "IndexOutOfBounds.h"
using namespace std;

template<typename Element>
class Array
{
private:
	int len;
	Element * buf;
public:
	Array(int newLen)
		: len(newLen), buf(new Element[newLen])
	{
	}
	Array(const Array & l)
		: len(l.len), buf(new Element[l.len])
	{
		for(int i = 0; i < l.len; i++)
			buf[i] = l.buf[i];
	}
	int length()
	{
		return len;
	}
	Element & operator [] (int i)
	{
		if(i > len-1 || i < 0)
		{
			IndexOutOfBounds e;
			throw e;
		}
		else
			return buf[i];
	}
	void print(ostream & out)
	{
		for(int i = 0; i < len; i++)
			out << setw(6) << setprecision(2) << fixed <<  buf[i];
	}
	friend ostream & operator << (ostream & out, Array & a)
	{
		a.print(out);
		return out;
	}
	friend ostream & operator << (ostream & out, Array * ap)
	{
		ap->print(out);
		return out;
	}
};

#endif
