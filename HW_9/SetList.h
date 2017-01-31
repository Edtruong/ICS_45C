#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

template <typename Element>
class SetList
{
private:
	struct ListNode
	{
		Element info;
		ListNode * next;
		ListNode(Element newInfo, ListNode * newNext)
			: info( newInfo ), next( newNext )
		{
		}
	};
	ListNode * head;
	static ListNode * copy(ListNode * L)
	{
		if(L == nullptr)
			return nullptr;
		else
			return new ListNode(L->info, copy(L->next));
	}
	static ListNode * concat(ListNode * L1, ListNode * L2)
	{
		if(L1 == nullptr)
			return copy(L2);
		else
			return new ListNode(L1->info, concat(L1->next, L2));
	}
	static int length(ListNode * L)
	{
		if(L == 0)
			return 0;
		else 
			return 1 + length(L->next);
	}
public:
	struct iterator
	{
		typedef std::forward_iterator_tag iterator_category;
		typedef iterator self_type;
		typedef Element value_type;
		typedef Element& reference;
		typedef Element* pointer;
		typedef ptrdiff_t difference_type;
	private:
		ListNode * buf;
	public:
		iterator(ListNode * ptr) : buf( ptr ){}
		self_type operator++(){ buf = buf->next; return *this; }
		self_type operator++(int postifx) {self_type cpy = *this; buf = buf->next; return cpy;}
		reference operator*(){ return buf->info; }
		pointer operator->(){ return buf; }
		bool operator == (const self_type& rhs) const {return buf == rhs.buf;}
		bool operator != (const self_type& rhs) const {return buf != rhs.buf;}	
	};
///////////////
	struct const_iterator
	{
		typedef std::forward_iterator_tag iterator_category;
		typedef const_iterator self_type;
		typedef Element value_type;
		typedef Element& reference;
		typedef Element* pointer;
		typedef ptrdiff_t difference_type;
	private:
		ListNode * buf;
	public:
		const_iterator(ListNode * ptr) : buf(ptr){}
		self_type operator+(){ buf = buf->next; return *this; }
		self_type operator++(int postfix){self_type cpy = *this; buf = buf->next; return cpy;}
		const reference operator*(){return buf->info;}
		const pointer operator->(){return buf;}
		bool operator == (const self_type& rhs)const{return buf == rhs.buf;}
		bool operator != (const self_type& rhs)const{return buf != rhs.buf;}
	};
///////////////// SetList member functions	
	SetList()
	{
		head = nullptr;
	}
	iterator insert(const Element & e)
	{
		if(find(e) == nullptr)
		{
			if(head == nullptr || head->info > e)
				head = new ListNode(e, head);
			else
			{
				ListNode * current = head;
				while(current-> next != nullptr && current->next->info < e)
					current = current->next;
				current->next = new ListNode(e, current->next);
			}
		}
	}
	iterator find(const Element & e)
	{
		for( ListNode * p = head; p != nullptr; p = p->next)
		{
			if( p->info == e )
				return iterator(p);
		}
		return nullptr;
	}
	iterator begin()
	{
		return iterator(head);
	}
	iterator end()
	{
		return iterator(nullptr);
	}
	const_iterator begin() const
	{
		return const_iterator(head);
	}
	const_iterator end() const
	{
		return const_iterator(nullptr);
	}
	~SetList()
	{
		ListNode * temp;
		for( ListNode * p = head ; p != nullptr;)
		{
			temp = p;
			p = p->next;
			delete temp;
		}
	}
};
