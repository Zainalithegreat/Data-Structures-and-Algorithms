#pragma once
#include "Wait.h"
const int MAXNUM = 100;
class StackList{
	public:
		StackList();
		StackList(char fileName[], int size);
		~StackList();

		StackList(const StackList& stack);
		StackList operator=(const StackList& stack);


		void push(que &Que);
		void pop();
		void peek();
		void display();

	private:
		que *st;
		int top;
		int size;		

};
