#include "Square.h"
#include "Triangle.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Picture.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	Picture frame;
	frame.addShape(new Square("Square1", 5));
	frame.addShape(new Square("Square2", 10));
	frame.addShape(new Triangle("Triangle1", 5, 5));
	frame.addShape(new Triangle("Triangle2", 4, 3));
	frame.addShape(new Circle("Circle1", 5));
	frame.addShape(new Circle("Circle2", 10));
	frame.addShape(new Rectangle("Rectangle1", 4, 8));
	frame.addShape(new Rectangle("Rectangle2", 8, 4));
	frame.drawAll();
	cout << "The total area of the shapes on this picture is " << frame.totalArea() << " square units." << endl;
	return 0;
}
