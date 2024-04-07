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
	int sum();
	int sumR();

private:
	struct Node{
		char data;
		Node *next;
	};
	Node *head;
	Node *tail;
	void printHelper(Node * first);
	bool delHelper(Node *& head, char ch);
	void sumRHelper(Node * head, int &sum);

};

#endif // _LINKED_LIST_
