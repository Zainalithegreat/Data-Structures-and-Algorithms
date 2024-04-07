#include <iostream>
#include <cstring>
#include "WaitList.h"
#include "Wait.h"
#include "stacklist.h"

using namespace std;

int main(){
	char fileName[MAX] = "Queue.txt";
	char tempGroup[MAX], tempSpecial[MAX], tempPromo[MAX];
        int people;

	char str = ' ';
	int size = 10;


	queList list(fileName);
	list.Print();
	StackList stack(fileName, size);


	do{
		cout << endl;
		cout << "(a)Add a new group" << endl;
		cout << "(b)Remove from the queue" << endl;
		cout << "(c)Display the queue" << endl;
		cout << "(d)Peek at who is going to be seated next" << endl;
		cout << "(e)Pop the stack" << endl;
		cout << "(f)Peek at the top most value in the stack" << endl;
		cout << "(g)Display the stack" << endl;
		cout << "(q)Quit" << endl;


		cin >> str;
		
		if(str == 'a'){
			cin.ignore(100, '\n');
			cout << "What is the group's name: ";
			cin.getline(tempGroup, MAX);
			cout << "How many people in the group: ";
			cin >> people;
			while(people < 0 || cin.fail()){
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Invalid group size please re-enter: ";
				cin >> people;
			}
			cin.ignore(100, '\n');
			cout << "if anyone in your group needs a special seat please let us know: ";
			cin.getline(tempSpecial, MAX);
			if(strlen(tempSpecial) == 0){
				strcpy(tempSpecial, "none");
			}
			cout << "If you want a promo code please provide us with you full name comma and email: ";
			cin.getline(tempPromo, MAX);
			if(strlen(tempPromo) == 0){
				strcpy(tempPromo, "none");
			}

			que myGroup = list.Add(tempGroup, people, tempSpecial, tempPromo);
			if(strcmp(myGroup.getPromoDetails(),"none") != 0){
				stack.push(myGroup);
			}

		}else if(str == 'b'){
			list.dequeue();
		}else if(str == 'c'){
			list.Print();
		}else if(str == 'd'){
			list.peek();
		}else if(str == 'e'){
			stack.pop();
		}else if(str == 'f'){
			stack.peek();
		}else if(str == 'g'){
			stack.display();
		}


	}while(tolower(str) != 'q');
}
