//This is going to store all the function for BTSList.cpp
#pragma once
#include <iostream>
#include "Data.h"

using namespace std;

const int MAX = 101;

class BTSList{
	public:
		BTSList();
		BTSList(char fileName[]);
		~BTSList();

		const BTSList& operator=(const BTSList &BTS);

		void Insert(Data &BTS);
		void Insert(char website[MAX], char keyWord[], char address[], char summery[], char review[], int rating);
		void Retrieve(const char * key, Data &BTS, int &found);
		void Edit(const char * key, int rating, char review[]);
		void Remove(const char * key);
		void allRemove(const char * name);
		void display(Data BTS[], int found);
		void display();
		void displayChain();
		void Monitor();
		void Height();

	private:
		struct Node{
			Node *lChild;
			Data data;
			Node *rChild;
		};
		Node *root;
		int size;
		void removeHelper(Node*& curr, const char* key);
		void deleteNode(Node *& curr);
		void allRemoveHelper(Node *& curr, const char *name);
		void insertHelper(Node*& root, Data &BTS);
		void displayHelper(Node *curr);
		void destroyTree(Node * curr);
		int Height(Node * curr);
		void Retrieve(Node * curr, const char * key, Data &BTS, int &found);
		

};
