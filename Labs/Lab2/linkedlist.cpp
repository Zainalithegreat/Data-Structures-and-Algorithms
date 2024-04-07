#include "linkedlist.h"
#include <iostream>

using namespace std;

//implementations for the member functions of LinkedList class


LinkedList::LinkedList(){
	head = NULL;
	tail = NULL;
}

LinkedList::~LinkedList(){
	Node *curr = head;

	while(curr){
		head = curr->next;
		delete curr;
		curr = head;
	}
	tail = NULL;

}


void LinkedList::add(char ch){
	Node* temp = new Node;
	temp->data = ch;
	temp->next = NULL;

	if(!head){
		head = temp;
		tail = temp;

	}else{
		tail->next = temp;
		tail = temp;
		temp = NULL;

	}

}

bool LinkedList::find(char ch){
	Node* curr = head;

	while(curr){
		if(curr->data == ch){
			return true;
		}
		curr = curr->next;
	}
	return false;
}


bool LinkedList::del(char ch){
	Node* curr = head;
	Node* temp = NULL;


	if(head && head->data == ch){
		temp = head;
		head = head->next;
		delete temp;
		return true;

	}else{

		while(curr){
			if(curr->data == ch){
				temp->next = curr->next;

				delete curr;
				return 	true;
			}
			temp = curr;	
			curr = curr->next;
		}
	}
	return false;

}

void LinkedList::print(){
	Node* curr = head;

	while(curr){
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;

}
