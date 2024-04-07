/******************************************************************************
# Author:           Zain Ali
# Lab:              Project 1
# Class 	    CS260
# Date:             Jan 20th 2024
# Description:      "In this program, we use a linked list to perform tasks on songs. We add the artist's name, song name, the length of the song, and the number of likes. We also edit the songs' likes, sort the songs by the amount of likes, and remove songs with fewer than M likes.

# Input:            char tempName[], tempTitle[], tempChar[]
		    int tempLikes, value
		    char str
		    double tempLength
		    Song data

# Output:           Song data
# Sources:          None
#******************************************************************************/  


#include <iostream>
#include <fstream>
#include <cstring>
#include "Song.h"
#include "SongList.h"
using namespace std;
//This is the main function that calls every function in SongList and has a menu
int main() {
	
	//Variables declaration
	char file[MAX] = "song.txt";
  	char str;
	int value = 0;
	char tempName[MAX],tempTitle[MAX], tempChar[MAX];
	int tempLikes;
        double tempLength;
	Song songAdd;

	//objects that calls a constructor with the parameter filename
  	SongList song(file);
	//song.Edit();

	//do-while loop
  	do{
		//The menu for the program
		cout << endl;
	      	cout << "(a) Add a new song" << endl;
	      	cout << "(b) Edit the number of likes for a song" << endl;
	      	cout << "(c) Display all songs in the list" << endl;
	      	cout << "(d) Display all songs for an artist(in order of popularity)"  << endl;
	      	cout << "(e) Remove all songs with fewer than M likes" << endl;
	      	cout << "(q) Quit" << endl;
		//user input for str
	      	cin >> str;
		//Adds to list
	      	if (str == 'a'){
			cout << endl;
        		song.Print();
        		cout << endl;
        		cin.ignore(100,'\n');
        		cout << "Enter the artist's name: ";
        		cin.getline(tempName, MAX);
        		cout << "enter the Title: ";
        		cin.getline(tempTitle, MAX);
        		cout << "Enter the length of the song: ";
       			cin >> tempLength;
        		while(tempLength <= 0 || cin.fail()){
                		cin.clear();
                		cin.ignore(100, '\n');
                		cout << "Please enter a valid length: ";
                		cin >> tempLength;
        		}
        		cout << "Enter the likes of the song: ";
        		cin >> tempLikes;
        		while(tempLikes < 0 || cin.fail()){
               	 		cin.clear();
                		cin.ignore(100, '\n');
                		cout << "Please Enter a valid number of likes: ";
                		cin >> tempLikes;
        		}

		      song.Add(songAdd, tempName, tempTitle, tempLength, tempLikes);
		//Edits the linked list
	      	}else if(str == 'b'){
        		cout << endl;
        		song.Print();
			cout << endl;
			cin.ignore(100, '\n');
        		cout << "Enter the title: ";
		      	cin.getline(tempChar, MAX);
			cout << "What is the new like amount: ";
			cin >> tempLikes;


		      	song.Edit(tempChar, tempTitle, tempLikes);
		      	cout << endl;
		//Prints the linked list
	      	}else if(str == 'c'){
			song.Print();
		//Sorts the linked list
	      	}else if(str == 'd'){
		      	song.ArtistPop();
		//Delete the node with fewer than M likes, M being value
	      	}else if(str == 'e'){
			cout << endl;
		      	song.Print();
		      	cout << endl;
		      	cout << "What is the like amount you want to delete from: ";
		     	cin >> value;
		      	song.Remove(value);
	      	}
	}while(tolower(str) != 'q');

  
}
