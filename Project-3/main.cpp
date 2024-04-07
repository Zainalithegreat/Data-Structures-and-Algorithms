//This is going to be the user driven file
#include <iostream>
#include <cstring>
#include "hashList.h"
#include "hash.h"

using namespace std;
int main() {
	//Variables declaration
	char file[MAX] = "hashWeb.txt";
  	char str;
	char website[MAX], address[MAX],  summery[MAX], review[MAX];
	int rating;
	int found = 0;
	char keyWord[MAX];

	
  	hashList hashing(file);
	hashing.Monitor();


  	do{
		cout << endl;
	      	cout << "(a) Add a new Website" << endl;
	      	cout << "(b) Edit the review and rating of a website" << endl;
	      	cout << "(c) Display a specific Website" << endl;
		cout << "(d) Display all the Websites" << endl;
	      	cout << "(e) Remove a website" << endl;
	      	cout << "(q) Quit" << endl;
	      	cin >> str;
	      	if (str == 'a'){
			cin.ignore(100, '\n');
			cout << "What is the website's name you want to add: ";
			cin.getline(website, MAX);
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
			hashing.Insert(website,address,summery,review, rating);

		
		}else if(str == 'b'){
			cin.ignore(100, '\n');
                      	cout << "What is the name of the website you want to edit: ";
                        cin.getline(keyWord, MAX);
			
			cout << "What do you want the new review to be: ";
			cin.getline(review, MAX);
			cout << "What do you want the new rating to be: ";
			cin >> rating;
			while(!cin || rating < 1 || rating > 5){
				cin.clear();
                                cin.ignore(100, '\n');
                                cout << "Please give me a valid rating: ";
                                cin >> rating;
                        }

		      	hashing.Edit(keyWord, rating, review);
		
	      	}else if(str == 'c'){
			found = 0;
			cin.ignore(100, '\n');
			hashType hashD[10];
			cout << "What is the name of the website you want to print: ";
			cin.getline(keyWord, MAX);
                        hashing.Retrieve(keyWord, hashD, found);
                        hashing.display(hashD, found);

		
		
		}else if(str == 'd'){
		      	hashing.display();

		
		
		}else if(str == 'e'){
			cout << endl;
		      	hashing.display();
		      	hashing.Remove(keyWord);
	      	}
		
		
	}while(tolower(str) != 'q');

	hashing.Monitor();

  
}
