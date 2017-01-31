#ifndef SQUARE_H
#define SQUARE_H
#include "Shape.h"
#include <iostream>
#include <string>
using namespace std;

class Square : public Shape
{
public:
	Square(string shapeName, double lengthOfSides) : Shape(0, 0, shapeName)
	{
		length = lengthOfSides;
	}
	virtual double area() const
	{
		return length * length;
	}
	virtual void draw() const
	{
		for(int i = 0; i < length; i++)
		{
			for(int j = 0; j < length; j++)
			{
				cout << "* ";
			}
			cout << endl;
		}
		cout << endl;
	}
	~Square(){};
private:
	double length;

};
#endif
