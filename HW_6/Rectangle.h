#include "Square.h"
#include <iostream>
using namespace std;

class Rectangle : public Square
{
public:
	Rectangle(string shapeName, double l, double w) : Square(shapeName, l)
	{
		length = l;
		width = w;
	}
	virtual double area() const
	{
		return length * width;
	}
	virtual void draw() const
	{
		for(int i = 0; i < length; i++)
		{
			for(int j = 0; j < width; j++)
			{
				cout << "* ";
			}
			cout << endl;
		}
		cout << endl;
	}
	~Rectangle() {};
private:
	int length, width;
};
