#include "Shape.h"
#include <iostream>
using namespace std;

typedef class ShapeLinkedListPair * ShapeLinkedList;
class ShapeLinkedListPair
{
public:
	Shape * info;
	ShapeLinkedList next;
	ShapeLinkedListPair(Shape * newInfo, ShapeLinkedList newNext)
		: info(newInfo), next(newNext)
	{}
};

class Picture
{
public:
	Picture()
		: head(0)
	{}
	void addShape(Shape * a)
	{
		head = new ShapeLinkedListPair(a, head);
	}
	double totalArea()
	{
		double totArea = 0.0;
		for(ShapeLinkedList p = head; p != 0; p = p->next)
		{
			totArea += p->info->area();
		}
		return totArea;
	}
	void drawAll()
	{
		for(ShapeLinkedList p = head; p != 0; p = p->next)
			p->info->draw();
	}
private:
	ShapeLinkedList head;
};
