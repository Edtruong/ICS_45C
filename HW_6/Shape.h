#ifndef SHAPE_H
#define SHAPE_H
#include <string>
using namespace std;

class Shape
{
public:
	Shape(int centerX=0, int centerY=0, string name="Shape")
	{
		xcoord = centerX;
		ycoord = centerY;
		shapeName = name;
	}
	virtual double area() const = 0;
	virtual void draw() const = 0;
	~Shape(){};
private:
	int xcoord, ycoord;
	string shapeName;
};

#endif
