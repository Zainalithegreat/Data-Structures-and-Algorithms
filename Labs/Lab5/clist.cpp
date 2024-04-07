// Write your functions in this file.
#include <iostream> 
#include "clist.h"

using namespace std;


int count(node * head){
	node * curr = head;
	int num = 0;
	do{
		curr = curr->next;
		num++;

	}while(curr != head);

	return num;

}

int countR(node * head){
	node * start = head;
	int count = 0;

	if(!head) return 0;
	countRHelper(head, start, count);

	return count;

}

int countRHelper(node * head, node * start, int &count){
	count++;
	head = head->next;
	if(head == start){
		return count;
	}

	return countRHelper(head, start, count);

}
int sum(node * head){
	int num = 0;
	node * curr = head;

	do{
		num += curr->data;
		curr = curr->next;
	}while(curr != head); 

	return num;
}
int sumR(node * head){
	int sum = 0;
	node * start = head;
	if(!head) return 0;
	sumRHelper(head,start,sum);

	return sum;

}

int sumRHelper(node * head, node * start, int &sum){
	sum += head->data;
	head = head->next;
    	if(head == start){
        	return sum;  
    	}
    	return sumRHelper(head, start, sum);
}

