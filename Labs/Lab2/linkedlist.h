#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <ostream>

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void add(char ch);
	bool find(char ch);
	bool del(char ch);
	void print();


private:
	struct Node{
		char data;
		Node *next;
	};
	Node *head;
	Node *tail;
};

#endif // _LINKED_LIST_
