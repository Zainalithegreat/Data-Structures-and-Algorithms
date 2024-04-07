//This is going to store all the function for hashList.cpp
#pragma once
#include <iostream>
#include "hash.h"

using namespace std;

const int MAX = 101;

class hashList{
	public:
		hashList();
		hashList(char fileName[]);
		~hashList();

		const hashList& operator=(const hashList &hashing);

		void Insert(const hashType &hashing);
		void Insert(char website[MAX], char address[MAX], char summery[MAX], char review[MAX], int rating);
		void Retrieve(const char * key, hashType hashing[], int &found);
		void Edit(const char * key, int rating, char review[]);
		void Remove(const char * key);
		void display(hashType hashing[], int found);
		void display();
		void displayChain();
		void Monitor();

	private:
		struct Node{
			Node(const hashType& hashing){
				data = new hashType(hashing);
				next = nullptr;
			};
			~Node(){
				delete data;
			}
			hashType * data;
			Node * next;
		};
		Node **aTable;
		int CAP = 10;
		int curCap;
		int size;
		int calculateIndex(const char * key) const;
		void removeHelper(Node*& curr, const char* key, bool &removed);
};
