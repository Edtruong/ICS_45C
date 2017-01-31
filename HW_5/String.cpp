#include "String.h"
#include <iostream>
using namespace std;
//public:
String::String(const char * s)
{
	head = ListNode::stringToList(s);
}
String::String(const String & s)
{
	head = ListNode::copy(s.head);
}
String String::operator = (const String & s)
{
	ListNode::deleteList(head);
	head = ListNode::copy(s.head);
	return *this;
}
char & String::operator [] (const int index)
{
	if(!inBounds(index))
	{
		cout << "Error: index not in bounds" << endl;
		static char c = '\0';
		return c;
	}
	else
	{
		ListNode * temp = head;
		for(int i = 0; i < index; i++)
		{
			temp = temp->next;
		}
		return temp->info;
	}
}
int String::length() const
{
	return ListNode::length(head);
}
int String::indexOf(char c) const
{
	int i = 0;
	for(ListNode * p = head; p != nullptr;)
	{
		if(p->info == c)
			return i;
		p = p->next;
		i++;
	}
	return -1;
}
bool String::operator == (const String & s) const
{
	return ListNode::equal(head, s.head) == 1;
}
bool String::operator < (const String & s) const
{
	return ListNode::compare(head, s.head) < 0;
}
String String::operator + (const String & s) const
{
	String temp;
	temp.head = ListNode::concat(head, s.head);
	return temp;
}
String String::operator += (const String & s)
{
	head = ListNode::concat(head, s.head);
	return *this;
}
void String::print(ostream & out)
{
	for ( ListNode * p = head; p != nullptr; p = p->next)
	{
		out << p->info;
	}
}
void String::read(istream & in)
{
	char *new_head = new char[1000];
	in.getline(new_head, 1000);
	head = ListNode::stringToList(new_head);
}
String::~String()
{
	ListNode::deleteList(head);
}
//private:

bool String::inBounds(int i)
{
	return i >= 0 && i < length();
}
String::ListNode * String::ListNode::stringToList(const char * s)
{
	if(*s  == '\0')
		return nullptr;
	else
	{
		ListNode * temp = new ListNode(*s, stringToList(s+1));
		return temp;
	}
}
String::ListNode * String::ListNode::copy(ListNode * L)
{
	return L == nullptr ? nullptr: new ListNode(L->info, copy(L->next));
}
bool String::ListNode::equal(ListNode * L1, ListNode * L2)
{
	if(L1 == nullptr && L2 != nullptr) {return 0;}
	else if(L1 != nullptr && L2 == nullptr) {return 0;}
	else if(L1 == nullptr && L2 == nullptr) {return 1;}
	else if(L1->info != L2->info) {return 0;}
	else if(L1->info == L2->info) {return equal(L1->next, L2->next);}
}
String::ListNode * String::ListNode::concat(ListNode * L1, ListNode * L2)
{
	if(L1 == nullptr)
		return copy(L2);
	else
	{
		return new ListNode(L1->info, concat(L1->next, L2));
	}
}
int String::ListNode::compare(ListNode * L1, ListNode * L2)
{
	if(L1 == nullptr && L2 != nullptr) {return L1->info - 0;}
	else if(L1 != nullptr && L2 == nullptr) {return 0 - L1->info;}
	else if(L2 == nullptr && L2 == nullptr) {return 0;}
	else if(L1->info != L2->info) {return L1->info - L2->info;}
	else if(L1->info == L2->info) {return compare(L1->next, L2->next);}
}
void String::ListNode::deleteList(ListNode * L)
{
	if (L != nullptr)
	{
		deleteList(L->next);
		delete L;
	}
}
int String::ListNode::length(ListNode * L)
{
	ListNode * temp = L;
	if(temp == nullptr)
		return 0;
	else
		return 1 + length(temp->next);
}
ostream & operator << (ostream & out, String str)
{
	str.print(out);
	return out;
}
istream & operator >> (istream & in, String & str)
{
	str.read(in);
	return in;
}
