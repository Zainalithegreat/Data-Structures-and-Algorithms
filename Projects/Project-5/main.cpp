//main.cpp

#include <iostream>
#include <cstring>
#include "Data.h"
#include "Graph.h"

using namespace std;


int main() {
	char file[MAX] = "Graph.txt";
	char str;

	char venue[MAXCHAR], date[MAXCHAR];
	int guests;

	Graph BTS(file);

	 do{
                //The menu for the program
                cout << endl;
                cout << "(a) Add a new Invite" << endl;
                cout << "(b) Display All" << endl;
                cout << "(q) Quit" << endl;
                //user input for str
                cin >> str;
                //Adds to list

                if (str == 'a'){
                        cin.ignore(100, '\n');
                        cout << "What is the Venue: ";
                        cin.getline(venue, MAXCHAR);
                        cout << "What is the date: ";
                        cin.getline(date, MAXCHAR);
			cout << "How many guests will be there: ";
                        cin >> guests;

                        while(!cin){
                                cin.clear();
                                cin.ignore(100, '\n');
                                cout << "Please give me a valid rating: ";
                                cin >> guests;
                        }
                        BTS.Insert(venue, date, guests);
		}else if(str == 'b'){
			BTS.printList();
		}
                       

        }while(tolower(str) != 'q');

}
