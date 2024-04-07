#pragma once
#include <iostream>
#include "Wait.h"

using namespace std;
const int MAX = 100;

class queList{
	public:
		queList();
		queList(char fileName[]);
		~queList();

		queList(const queList &list);
		queList& operator=(const queList &list);

		void enqueue(que &myQue);
		void dequeue();
		que Add(char tempGroup[], int people, char tempSpecial[], char tempPromo[]);
		void peek();
		
		void Print(); 
	private:
		struct Node{
			que data;
			Node *next;
		};
		Node *front;
		Node *rear;
		int size;
		void printHelper(Node *curr, int count);

	
};
