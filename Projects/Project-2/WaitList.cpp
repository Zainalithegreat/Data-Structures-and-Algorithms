#include "WaitList.h"
#include "Wait.h"
#include "stacklist.h"
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

queList::queList(){
	front = NULL;
	rear = NULL;
	size = 10;
}
queList::queList(char fileName[]){
	front = NULL;
	rear = NULL;
	size = 10;

	char name[MAX], special[MAX], promotion[MAX];
	int numPeople;
	fstream inFile;
	que Que;


	inFile.open(fileName);
	if(!inFile.is_open()){
		cout << "file did not open" << endl;
		exit(1);
	}

	inFile.getline(name, MAX, ';');
	while(!inFile.eof()){
		inFile >> numPeople;
		inFile.ignore(100, ';');
		inFile.getline(special, MAX, ';');
		inFile.getline(promotion, MAX);

		Que.group(name);
		Que.people(numPeople);
		Que.specialSeating(special);
		Que.Promo(promotion);
		enqueue(Que);
		inFile.getline(name, MAX, ';');
	}
	inFile.close();
}
queList::~queList(){
	Node *curr = front;
	Node *temp = front;
	do{
		temp = curr->next;
		delete curr;
		curr = temp;

	}while(curr != front);
	rear = NULL;
}
void queList::enqueue(que &myQue){
	Node *temp = new Node;
	temp->data = myQue;
	temp->next = NULL;

	if(size == 0){
		cout << "The queue is full" << endl;
		return;
	}

	if(!rear){
		rear = temp;
		front = temp;
		rear->next = front;
	}else{
		rear->next = temp;
		rear = temp;
		rear->next = front;
	}
	size--;
}

void queList::dequeue(){
	Node *temp = front;
	if(!front){
		cout << "Sorry the queue is empty" << endl;
		return;
	}else if(front == rear){
		front = rear = NULL;
		delete temp;
		size++;
	}else{
		front = front->next;
		rear->next = front;
		delete temp;
		size++;
	}
	cout << "A seat has just opened" << endl;
}
void queList::printHelper(Node *curr, int count){
	if(!front){
		cout << "Queue is empty" << endl;
		return;
	}
	 cout << count << ": ";
         curr->data.PrintList();
	 curr = curr->next;

	 if(curr == front){
		return;
	 }

	 printHelper(curr, count + 1);

}
void queList::Print(){
	Node *curr = front;
	int count = 1;
	printHelper(curr, count);
}
que queList::Add(char tempGroup[], int people, char tempSpecial[], char tempPromo[]){
	que Que;

	if(size == 0){
		cout << "Queue is full" << endl;
		return Que;
	}	
	Que.group(tempGroup);
	Que.people(people);
	Que.specialSeating(tempSpecial);
	Que.Promo(tempPromo);
	enqueue(Que);


	return Que;
}
void queList::peek(){
	if(!front){
		cout << "Queue is empty" << endl;
	}else{
		cout << "The first group to be seated are" << endl;
		front->data.PrintList();
	}
}
