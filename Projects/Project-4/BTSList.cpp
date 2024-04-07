#include <iostream>
#include "BTSList.h"
#include <fstream>
#include <cstring>
#include "Data.h"
#include <algorithm>

using namespace std;

BTSList::BTSList(){
	size = 0;
	root = NULL;
}



BTSList::BTSList(char fileName[]){
        size = 0;
        root = NULL;

        char name[MAX],keyWord[MAX], address[MAX], summery[MAX], review[MAX];
        int  rating;
        ifstream inFile;
        Data BTS;


        inFile.open(fileName);
        if(!inFile.is_open()){
                cout << "file did not open" << endl;
                exit(1);
        }

        inFile.getline(name, MAX, ';');
        while(!inFile.eof()){
		inFile.getline(keyWord, MAX, ';');
                inFile.getline(address, MAX, ';');
                inFile.getline(summery, MAX, ';');
                inFile.getline(review, MAX, ';');
                inFile >> rating;
                inFile.ignore(100, '\n');

                BTS.webName(name);
		BTS.webKeyWord(keyWord);
                BTS.webAddress(address);
                BTS.webSummery(summery);
                BTS.webReview(review);
                BTS.webRating(rating);
                Insert(BTS);
                inFile.getline(name, MAX, ';');
        }
        inFile.close();
}
BTSList::~BTSList(){
	destroyTree(root);
	root= NULL;
}

void BTSList::destroyTree(Node * curr){
	if(curr){
		destroyTree(curr->lChild);
		destroyTree(curr->rChild);
		delete curr;
	}
}

void BTSList::Insert(Data &BTS){
	insertHelper(root, BTS);

}
void BTSList::insertHelper(Node *& root, Data &BTS){
        if(!root){
		Node *temp = new Node;
        	temp->data = BTS;
        	temp->lChild = temp->rChild = NULL;

                root = temp;
		size++;
		return;
        }
	if(strcmp(BTS.getKeyWord(), root->data.getKeyWord()) < 0){
		insertHelper(root->lChild, BTS);
	}else if(strcmp(BTS.getKeyWord(), root->data.getKeyWord()) > 0){
		insertHelper(root->rChild, BTS);
	}else{
                return;
        }
	
}

void BTSList::display(){
	Node * curr = root;
	displayHelper(curr);
}

void BTSList::displayHelper(Node * curr){
	if(!curr)
		return;
	if(curr){
		displayHelper(curr->lChild);
		curr->data.print();		
		displayHelper(curr->rChild);
	}
}

void BTSList::Insert(char website[], char keyWord[], char address[], char summery[], char review[], int rating){
        Data BTS;

        BTS.webName(website);
	BTS.webKeyWord(keyWord);
        BTS.webAddress(address);
        BTS.webSummery(summery);
        BTS.webReview(review);
        BTS.webRating(rating);

        Insert(BTS);
}
void BTSList::Height(){
	cout << "The Height of the tree is " << Height(root) << endl;

}
int BTSList::Height(Node * curr){
	if(!curr){
		return 0;
	}else{
		int left = Height(curr->lChild);
		int right = Height(curr->rChild);

		return max(left, right) + 1;
	}
}
void BTSList::Remove(const char* key) {
        removeHelper(root, key);
}
void BTSList::removeHelper(Node*& curr, const char* key) {
    if (!curr) {
        return;
    }

    int temp = strcmp(key, curr->data.getKeyWord());
    
    if (temp == 0) {
	    deleteNode(curr);
	    size--;
    } else if (temp < 0) {
        removeHelper(curr->lChild, key);
    } else {
	removeHelper(curr->rChild, key);

    }
}
void BTSList::deleteNode(Node *& curr){
	if(!curr->rChild && !curr->lChild){
		delete curr;
		curr = nullptr;
	}else if(!curr->rChild){
		Node * temp = curr;
		curr = curr->lChild;
		delete temp;
	}else if(!curr->lChild){
		Node * temp = curr;
		curr = curr->rChild;
		delete temp;
	}else{
		Node * prev = nullptr;
		Node * temp = curr->rChild;

		if(!temp->lChild){
			curr->rChild = temp->rChild;

		}else{
			while(temp->lChild){
				prev = temp;
				temp = temp->lChild;
			}

			prev->lChild = temp->rChild;
		}

		curr->data = temp->data;
		delete temp;
		return;


	}
}

void BTSList::allRemove(const char* name) {
        allRemoveHelper(root, name);
}
void BTSList::allRemoveHelper(Node*& curr, const char *name) {
    	if (!curr) {
        	return;
    	}

    	if (curr->lChild) {
        	allRemoveHelper(curr->lChild, name);
    	}
    	if (curr->rChild) {
        	allRemoveHelper(curr->rChild, name);
    	}
    	int temp = strcmp(name, curr->data.getName());
   	if (temp == 0) {
        	if (!curr->lChild) {
            		Node* temp = curr;
            		curr = curr->rChild;
            		delete temp;
        	} else if (!curr->rChild) {
            		Node* temp = curr;
            		curr = curr->lChild;
            		delete temp;
        	} else {
            		Node* temp = curr->rChild;
            		while (temp->lChild) {
                		temp = temp->lChild;
            		}
            		curr->data = temp->data;
            		allRemoveHelper(curr->rChild, name);
        }
    }
}

void BTSList::Retrieve(const char * key, Data &BTS, int &found){
	Retrieve(root, key, BTS, found);
	if(found == 1){
	BTS.print();
	}
}
void BTSList::Retrieve(Node * curr, const char * key, Data &BTS, int &found){
	if(!curr){
		return;
	}
	int temp = strcmp(key, curr->data.getKeyWord());

	if(temp == 0){
		BTS = curr->data;
		found = 1;
		return;
	}else if(temp < 0){
		Retrieve(curr->lChild, key, BTS, found);
	}else if( temp > 0){
		Retrieve(curr->rChild, key, BTS, found);
	}
}
