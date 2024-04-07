//This is going to be the user driven file
#include <iostream>
#include <cstring>
#include "BTSList.h"
#include "Data.h"

using namespace std;
int main() {
	//Variables declaration
	char file[MAX] = "BTSWeb.txt";
  	char str;
	char website[MAX], address[MAX],  summery[MAX], review[MAX];
	int rating;
	int found = 0;
	char keyWord[MAX];
	char name[MAX];

	
	//objects that calls a constructor with the parameter filename
  	BTSList BTS(file);
	//BTS.Monitor();


	//do-while loop
	BTS.Height();
  	do{
		//The menu for the program
		cout << endl;
	      	cout << "(a) Add a new Website" << endl;
	      	cout << "(b) Display a specific Website" << endl;
		cout << "(c) Display all the Websites" << endl;
	      	cout << "(d) Remove a website" << endl;
		cout << "(e) Remove all matches to a topic name" << endl;
	      	cout << "(q) Quit" << endl;
		//user input for str
	      	cin >> str;
		//Adds to list
		
	      	if (str == 'a'){
			cin.ignore(100, '\n');
			cout << "What is the website's name you want to add: ";
			cin.getline(website, MAX);
			cout << "What is the website's key word: ";
			cin.getline(keyWord, MAX);
			cout << "What is the website's address: ";
			cin.getline(address, MAX);
			cout << "What is the summary of your website: ";
			cin.getline(summery, MAX);
			cout << "What is your review on the website: ";
			cin.getline(review, MAX);
			cout << "Give me a rating for the website 1-5: ";
			cin >> rating;

			while(!cin || rating < 1 || rating > 5){
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Please give me a valid rating: ";
				cin >> rating;
			}
			BTS.Insert(website,keyWord, address,summery,review, rating);
			BTS.Height();
	      	}else if(str == 'b'){
			found = 0;
			cin.ignore(100, '\n');
			Data BTSL;
			BTS.display();
			cout << endl << endl;
			cout << "What is the name of the website you want to print: ";
			cin.getline(keyWord, MAX);
			BTS.Retrieve(keyWord, BTSL, found);
			if(found == 1){
				cout << "Name Retrieved" << endl;
			}else{
				cout << "Name not Retrieved" << endl;
			}

		
		//Sorts the linked list
		
		}else if(str == 'c'){
		      	BTS.display();
		
		
		//Delete the node with fewer than M likes, M being value
		
		}else if(str == 'd'){
			cout << endl;
		      	BTS.display();
		      	cout << endl;
			cin.ignore(100, '\n');
			cout << "What is the key of the website you want to delete: ";
                        cin.getline(keyWord, MAX);

		      	
		      	BTS.Remove(keyWord);
	      	}else if(str == 'e'){
			cout << endl;
			BTS.display();
			cout << endl;
			cin.ignore(100, '\n');
			cout << "What is the name of the website you want to delete: ";
			cin.getline(name, MAX);
			BTS.allRemove(name);

		}
		
		
	}while(tolower(str) != 'q');
	BTS.Height();

	//BTS.Monitor();


  
}
