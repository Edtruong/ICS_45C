#include "Shape.h"
#include <iostream>
#include <string>
using namespace std;

class Triangle : public Shape
{
public:
	Triangle(string name, double b, double h) : Shape(0, 0, name)
	{
		base = b;
		height = h;
	}
	virtual double area() const
	{
		return base * height * .5;
	}
	virtual void draw() const
	{
		int count = base;
		for(int j = 0; j < height; j++)
		{
			for(int i = 0; i < count; i++)
			{
				cout << "* ";
			}
			count--;
			cout << endl;
		}
		cout << endl;
	}
	~Triangle(){};
private:
	double base, height;
};
