/******************************************************************************
# Author:           Zain Ali
# Lab:              Project 1
# Date:             Jan 20th 2024
# Description:      "This file includes all the ADT function, Add, Remove, Display, Sort etc. This file also has the constructors, destructors, copy constructors, and assignment operator overload.
# Input:            char *name, *title, *length
                    int likes
                    Song data
# Output:           char *name, *title, *length
                    int likes
                    Song data
# Sources:          None
#File Name:	    SongList.cpp
#******************************************************************************/



#include "SongList.h"
#include "Song.h"
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
//This is the defualt constructor that sets everything to NULL or 0
SongList::SongList(){
  	head = NULL;
  	tail = NULL;
  	size = 0;
}
//This is a constructor with parameters that opens file and retrives the data from the files into local variables, then it adds the varibels to a linked list
SongList::SongList(char file[]){
  	head = nullptr;
  	tail = nullptr;
  	size = 0;

  	fstream inFile;
  	char tempName[MAX], tempTitle[MAX];
  	double tempLength;
  	int tempLike;
  	Song song;

  	inFile.open(file);
  	if(!inFile.is_open()){
    		cout << "file not opening" << endl;
    		exit(1);
  	}
 	 inFile.getline(tempName,MAX,';');
  	while(!inFile.eof()){
    		inFile.getline(tempTitle,MAX, ';');
    		inFile >> tempLength;
    		inFile.ignore(100, ';');
   		inFile >> tempLike;

    		inFile.ignore(100, '\n');

    		song.setName(tempName);
    		song.setTitle(tempTitle);
    		song.setLength(tempLength);
    		song.setLike(tempLike);
   	 	Roster(song);
    		inFile.getline(tempName,MAX,';');
  	}
  	inFile.close();
}
//This is a destructor that deallocates/deletes the Linked List
SongList::~SongList(){
  	Node *curr = head;
  	while(head){
    		head = curr->next;
    		delete curr;
    		curr = head;
  	}
  	tail = NULL;
}
//This is a copy constructor that will copy the parameter
SongList::SongList(const SongList& song) {
        // Perform a deep copy of the linked list
        head = nullptr;
        tail = nullptr;
        size = 0;

        Node* current = song.head;
        while (current != nullptr) {
		Node* newNode = new Node{current->data, nullptr};
            	if (tail == nullptr) {
                	head = newNode;
                	tail = newNode;
            	} else {
                tail->next = newNode;
                tail = newNode;
            	}
            	size++;
            	current = current->next;
        }
}
SongList& SongList::operator=(const SongList& song) {
	if (this != &song) {  // Avoid self-assignment
            // Clear current content
            while (head != nullptr) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
            tail = nullptr;
            size = 0;

            // Perform a deep copy of the linked list
            Node* current = song.head;
            while (current != nullptr) {
                Node* newNode = new Node{current->data, nullptr};
                if (tail == nullptr) {
                    head = newNode;
                    tail = newNode;
                } else {
                    tail->next = newNode;
                    tail = newNode;
                }
                size++;
                current = current->next;
            }
        }
        return *this;
}
//This adds the song object varibles to a linked list
void SongList::Roster(Song &song){
  	Node *temp = new Node;
  	temp->data = song;
  	temp->next = nullptr;
  	if(!head){
    		head = temp;
    		tail = temp;
    		temp = NULL;
  	}else{
    		tail->next = temp;
    		tail = temp;
    		temp = NULL;
  	}
  	size++;
}
//This function is a PrintHelper function that prints the Linked List recursively
void SongList::PrintHelper(Node *head){
	if(head == nullptr){
		return;
	}else{
		head->data.PrintAct();
		PrintHelper(head->next);
	}	

}
//This function is a Print function that calls PrintHelper
void SongList::Print(){
	Node *curr = head;
	PrintHelper(curr);
}
//This function has 4 local variables which get inputted by the user, then calls the song classes functins and finally adds the user inputted values to the Linked List 
void SongList::Add(Song &song, char tempName[], char tempTitle[], double tempLength, int tempLikes){
	song.setName(tempName);
	song.setTitle(tempTitle);
	song.setLength(tempLength);
	song.setLike(tempLikes);
	Roster(song);
}
//This function Edits the number of likes in a linked list
void SongList::Edit(char tempChar[],char  tempTitle[], int val){
	Node *curr = head;
	while(curr){
		strcpy(tempTitle, curr->data.getTitle());
		if(strstr(tempTitle, tempChar) != NULL){
			curr->data.PrintAct();
			curr->data.setLike(val);
			cout << "After:		";
			curr->data.PrintAct();
		}
		curr = curr->next;

	}
	cout << endl;
}
//This function uses bubble sort to sort a linkedlist by the number of likes
void SongList::ArtistPop(){
	Node *curr = head;
    	Song tempSong;

    	while(curr && curr->next){
        	Node *innerLoop = head;
        	while(innerLoop && innerLoop->next){
            		if(innerLoop->data.getLike() > innerLoop->next->data.getLike()){
                		tempSong = innerLoop->data;
                		innerLoop->data = innerLoop->next->data;
                		innerLoop->next->data = tempSong;
            		}
            		innerLoop = innerLoop->next;
        	}
        	curr = curr->next;
    	}
	cout << endl;
    	Print();

}
//This function calls RemoveHelper function which remove less than M number of likes in a linked list
void SongList::Remove(int value){
	RemoveHelper(head, value);

}
//This function removes all nodes who are less than M number of likes, M being value
void SongList::RemoveHelper(Node *&head, int value) {
	if(head == NULL)
		return;
	else if(head->data.getLike() < value){
		Node *nextNode = head->next;
		delete head;
		head = nextNode;	
		RemoveHelper(head, value);
	}else{
		RemoveHelper(head->next, value);
	}
}

