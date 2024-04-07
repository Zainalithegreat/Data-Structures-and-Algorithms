//This is going to have all the operations
#include <iostream>
#include <cstring>
#include <fstream>
#include "hash.h"
#include "hashList.h"

using namespace std;
hashList::hashList(){
        size = 0;
        curCap = CAP;
        aTable = new Node*[curCap];
        for(int i = 0; i < curCap; i++){
                aTable[i] = nullptr;
        }
}


hashList::hashList(char fileName[]){
        size = 0;
	curCap = CAP;
	aTable = new Node*[curCap];
	for(int i = 0; i < curCap; i++){
		aTable[i] = nullptr;
	}

        char name[MAX], address[MAX], summery[MAX], review[MAX];
        int  rating;
        fstream inFile;
        hashType hashing;


        inFile.open(fileName);
        if(!inFile.is_open()){
                cout << "file did not open" << endl;
                exit(1);
        }

        inFile.getline(name, MAX, ';');
        while(!inFile.eof()){
                inFile.getline(address, MAX, ';');
                inFile.getline(summery, MAX, ';');
		inFile.getline(review, MAX, ';');
		inFile >> rating;
		inFile.ignore(100, '\n');

                hashing.webName(name);
                hashing.webAddress(address);
                hashing.webSummery(summery);
                hashing.webReview(review);
		hashing.webRating(rating);
                Insert(hashing);
                inFile.getline(name, MAX, ';');
        }
        inFile.close();
}
hashList::~hashList(){
	Node * curr;
	Node * temp;
	for(int i = 0; i < curCap; i++){
		curr = aTable[i];
		while(curr){
			
			temp = curr->next;
			delete curr;
			curr = temp;
			
		}
	}
	if(aTable != nullptr){
		delete[] aTable;
		aTable = nullptr;
	}

}

void hashList::Insert(const hashType &hashing){
	int index = calculateIndex(hashing.getName());
	Node * newNode = new Node(hashing);
	newNode->next = aTable[index];
	aTable[index] = newNode;
	size++;
}
int hashList::calculateIndex(const char * key) const{
	int hashingResult = 0;

	for(size_t i = 0; i < strlen(key); i++){
		hashingResult += key[i];
	}

	return hashingResult % curCap;
}
void hashList::display(){
	for(int i = 0; i < curCap; i++){
		Node *curr = aTable[i];
		while(curr){
			(*curr->data).print();
			curr = curr->next;
		}
		
	}

}

void hashList::Insert(char website[MAX], char address[MAX], char summery[MAX], char review[MAX], int rating){
	hashType hashing;

	hashing.webName(website);
	hashing.webAddress(address);
	hashing.webSummery(summery);
	hashing.webReview(review);
	hashing.webRating(rating);

	Insert(hashing);

}
void hashList::display(hashType hashing[], int found) {
	for(int i = 0; i < found; i++){
		hashing[i].print();
	}
}
void hashList::Remove(const char* key) {
	bool removed = false;

    	for(int i = 0; i < curCap; i++){
    		removeHelper(aTable[i], key, removed);
    	}
	if(removed){
		cout << endl << endl << "removed all the websites with 1 star rating" << endl;
	}else{
		cout << endl << endl << "No websites found that have the rating 1" << endl;
	}
}

void hashList::removeHelper(Node*& curr, const char* key, bool &removed) {
    	if (!curr) {
        	return;
    	}

    	if (curr->data->getRating() == 1) {
        	Node* helper = curr->next;
        	delete curr;
        	curr = helper;
		removed = true;
        	removeHelper(curr, key, removed);
    	} else {
        	removeHelper(curr->next, key, removed);
    	}
}
void hashList::Edit(const char * key, int rating, char review[]) {
	for(int i = 0; i < curCap; i++){
        	Node *curr = aTable[i];
       		while(curr) {
        		const char *name = curr->data->getName();
        		if (strstr(name, key) != NULL) {
            			curr->data->webReview(review);
            			curr->data->webRating(rating);
        		}
        		curr = curr->next;
    		}
	}
}

void hashList::Retrieve(const char * key, hashType hashing[], int &found){
	for(int i = 0; i < curCap; i++){
		Node *curr = aTable[i];
		char temp[MAX];
		while (curr) {
			strcpy(temp, curr->data->getName());
                	if (strstr(temp, key) != NULL) {
				hashing[found] = *(curr->data);
				found++;
                	}
                	curr = curr->next;
        	}
	}

}
void hashList::Monitor(){
	for(int i = 0; i < curCap; i++){
		Node *curr = aTable[i];
		int count = 0;
		while(curr){
			curr = curr->next;
			count++;
		}
		cout << "Number of nodes in chain " << i + 1 << ": " << count << endl;
	}
}
