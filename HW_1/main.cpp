#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

int main()
{
	while (true)
	{
		string x;
		cout << "Please input a string of characters: ";
		getline(cin, x);
		if(x == "^Z")
		{
			break;
		}
		int length = x.length();
		Stack s;
		int count = 0;
		while(count != length)
		{
			s.push(x[count]);
			count++;
		}	
		while(!(s.isEmpty()))
		{
			cout << s.top() << endl;
			s.pop();
		}
	}
}
