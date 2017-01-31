#include <iostream>
#include <string>
#define MAX 1000
using namespace std;

class Stack
{
	private:
		char stack_on_stack[MAX];
		int count;

	public:
		Stack(){count = 0;}
		void push(char c)
		{
			if (isFull())
			{
				cout << "Error: can't push full stack" << endl;
			}
			stack_on_stack[count] = c;
			count++;
		}
		char pop()
		{
			if (isEmpty())
			{
				cout<< "Error: can't pop empty stack" << endl;
			}
			stack_on_stack[count] = 0;
			count--;
		}
		char top()
		{
			return stack_on_stack[count];
		}
		bool isEmpty()
		{
			return count == -1;
		}
		bool isFull()
		{
			return count >= MAX;
		}
		~Stack(){};
		
};
