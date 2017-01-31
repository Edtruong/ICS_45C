#ifndef INDEXOUTOFBOUNDS_H
#define INDEXOUTOFBOUNDS_H

#include <iostream>
#include <exception>
using namespace std;

class IndexOutOfBounds: public exception
{
public:
	virtual const char * what() const throw()
	{
		return "Index is out of bounds: ";
	}
};

#endif
