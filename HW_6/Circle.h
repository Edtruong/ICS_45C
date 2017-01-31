#include "Shape.h"
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class Circle : public Shape
{
public:
	Circle(string name, double r) : Shape(0, 0, name)
	{
		radius = r;
	}
	virtual double area() const
	{
		return PI * (radius * radius);
	}
	virtual void draw() const
	{
		for(int i = 0; i <= 2*radius; i++)
		{
			for(int j = 0; j <= 2*radius; j++)
			{
				float distance_to_center = sqrt((i - radius)*(i - radius) + (j - radius)*(j - radius));
				if(distance_to_center > radius-.5 && distance_to_center < radius+.5)
				{ 
					cout << '*';
				 }
				else
				{
					 cout << ' ';
				 }
			}
			cout << endl;
		}
		cout << endl;
	}
	~Circle(){};
private:
	double radius;
	const double PI = 3.14159;
};
