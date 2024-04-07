#include "Wait.h"
#include <iostream>
#include <cstring>

using namespace std;

que::que(){
        groupName = new char[strlen("unknown") + 1];
        strcpy(groupName, "unknown");
        numPeople = -1;
        specialSeat = new char[strlen("unknown") + 1];
        strcpy(specialSeat, "unknown");
        Promotional = new char[strlen("unknown") + 1];
        strcpy(Promotional, "unknown");
}

que::que(const char *name, const int people, const char *specialSeat, const char *Promotion){
        groupName = new char[strlen(name) + 1];
        strcpy(groupName, name);
        numPeople = people;
        this->specialSeat = new char[strlen(specialSeat) + 1];
        strcpy(this->specialSeat, specialSeat);
        Promotional = new char[strlen(Promotion) + 1];
        strcpy(Promotional, Promotion);
}
que::~que(){
        if(groupName){
                delete[] groupName;
        }
        if(specialSeat){
                delete[] specialSeat;
        }
        if(Promotional){
                delete[] Promotional;
        }
}
que::que(const que &myQue){
        groupName = new char[strlen(myQue.groupName) + 1];
        strcpy(groupName, myQue.groupName);
        numPeople = myQue.numPeople;
        specialSeat = new char[strlen(myQue.specialSeat) + 1];
        strcpy(specialSeat,myQue.specialSeat);
        Promotional = new char[strlen(myQue.Promotional) + 1];
        strcpy(Promotional, myQue.Promotional);
}
que& que::operator=(const que &myQue){
        if(this != &myQue){
		this->group(myQue.groupName);
		this->people(myQue.numPeople);
		this->specialSeating(myQue.specialSeat);
		this->Promo(myQue.Promotional);
		
        }
        return *this;
}
//mutators
void que::group(const char *name){
        if(groupName){
                delete[] groupName;
        }
        groupName = new char[strlen(name) + 1];
        strcpy(groupName, name);
}

void que::people(const int people){
        numPeople = people;
}
void que::specialSeating(const char *special){
        if(specialSeat){
                delete[] specialSeat;
        }
        specialSeat = new char[strlen(special) + 1];
        strcpy(specialSeat, special);
}
void que::Promo(const char *Promotion){
	if(Promotional){
		delete[] Promotional;
	}
	Promotional = new char[strlen(Promotion )+ 1];
	strcpy(Promotional, Promotion);
}
//accessors
const char * que::getGroupName() const{
	return groupName;
}
int que::getNumPeople() const{
	return numPeople;
}
const char * que::getSpecialSeating() const{
	return specialSeat;
}
const char * que::getPromoDetails()const{
	return Promotional;
}
void que::PrintList(){
	cout << groupName << ";" << numPeople << ";" << specialSeat << ";" << Promotional << endl;
}
