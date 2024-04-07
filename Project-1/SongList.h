#pragma once
#include "Song.h"

const int MAX = 101;
//This is the SongList class that Adds/Edit/Remove/Sort on a linked list
class SongList{
	public:
		//default constructor, constructor with parameters, destructor
		SongList();
    		SongList(char []);
    		~SongList();

    		//copy constructor and assignment operator overload
    		SongList(const SongList& song);
    		SongList& operator=(const SongList& song);
    		//Here we have the member function of SongList class
		void Add(Song &song, char [], char [], double , int );
    		void Roster(Song &song);
    		void Edit(char [],char [] , int );
		//void Edit();
    		void Print();
    		void ArtistPop();
    		void Remove(int value);
  	private:
		//these are the private member variables/function
		//This strcut Node defines a Linked List
    		struct Node{
      			Song data;
      			Node *next;
    		};
    		Node *head;
    		Node *tail; 
    		int size;
		//Private member function
		void PrintHelper(Node *head);
		void RemoveHelper(Node *&head, int value);

};
