#include <iostream>
#include <fstream>
#include <cstring>
#include "stacklist.h"
#include "Wait.h"

using namespace std;

StackList::StackList(){
	st = NULL;
	size = 0;
	top = -1;
}
StackList::StackList(char fileName[], int size){
	this->size = size;
	st = new que[this->size];
	top = -1;

	fstream inFile;
	char name[MAXNUM], specialSeat[MAXNUM], Promotion[MAXNUM];
	int numPeople;
	que Que;
	
	inFile.open(fileName);
	if(!inFile.is_open()){
		cout << "file not open" << endl;
		exit(1);
	}
	
	inFile.getline(name, MAXNUM, ';');
	while(!inFile.eof()){
		inFile >> numPeople;
		inFile.ignore(100, ';');
		inFile.getline(specialSeat, MAXNUM, ';');
		inFile.getline(Promotion, MAXNUM);
		
		Que.group(name);
                Que.people(numPeople);
                Que.specialSeating(specialSeat);
                Que.Promo(Promotion);

		if(strcmp(Promotion, "none") != 0){
			push(Que);
		}
		strcpy(Promotion, "none");
		inFile.getline(name, MAXNUM, ';');

	}

}

StackList::~StackList(){
	if(st){
		delete[] st;
		st = NULL;
	}
}
void StackList::push(que &Que){
	ofstream outFile;
	outFile.open("Stack.txt", std::ios_base::app);
	if(!outFile.is_open()){
		cout << "file not open";
		exit(1);
	}
	char name[MAXNUM], specialSeat[MAXNUM], Promotion[MAXNUM];
        int numPeople;

	if(top == size){
		cout << "Stack overflow" << endl;
	}else{
		top++;
		st[top] = Que;
		strcpy(name, Que.getGroupName());
		numPeople = Que.getNumPeople();
		strcpy(specialSeat, Que.getSpecialSeating());
		strcpy(Promotion, Que.getPromoDetails());
		outFile << name << ";" << numPeople << ";" << specialSeat << ";" << Promotion << endl;
		if (outFile.fail()) {
    			cout << "Error writing to file\n";
		}
	}
	outFile.close();	
}
void StackList::pop(){
	if(top == -1){
		cout << "Stack is empty" << endl;
	}else{
		top--;
		cout << "Just sent a Promotional code" << endl;
	}
}
void StackList::peek(){
	if(top == -1){
		cout << "Stack is empty" << endl;
	}else{
		st[top].PrintList();
	}
}
void StackList::display(){
	for(int i = top; i >= 0; i--){
		st[i].PrintList();
	}
}
