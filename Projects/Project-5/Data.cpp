//This is going to have all the data functions
#include <iostream>
#include <cstring>
#include "Data.h"

using namespace std;


Data::Data(){
 	guests = 0;
	venue = new char[strlen("unknown") + 1];
  	strcpy(venue, "unknown");
	date = new char[strlen("unknown") + 1];
	strcpy(date, "unknown");
}

Data::Data(int guests, char * venue, char * date ){
	this->guests = guests;
	this->venue = new char[strlen(venue)+1];
	strcpy(this->venue, venue);
	this->date = new char[strlen(date)+1];
	strcpy(this->date, date);

}
Data::~Data(){
	if(date){
		delete[] date;
	}
	if(venue){
		delete[] venue;
	}
}
Data::Data(const Data& BTS){
	venue = new char[strlen(BTS.venue) + 1];
        strcpy(venue, BTS.venue);
	date = new char[strlen(BTS.date) + 1];
	strcpy(date, BTS.date);
        guests = BTS.guests;
	
}
Data& Data::operator=(const Data &BTS){
	if(this != &BTS){
		this->setGuests(BTS.guests);
		this->setVenue(BTS.venue);
		this->setDate(BTS.date);
	}
	return *this;
}
//mutators
void Data::setDate(const char *date){
	if(this->date){
		delete[] this->date;
	}
	this->date = new char[strlen(date) + 1];
        strcpy(this->date, date);

}
void Data::setVenue(const char *venue){
	if(this->venue){
		delete[] this->venue;
	}
	this->venue = new char[strlen(venue) + 1];
	strcpy(this->venue, venue);
}
void Data::setGuests(const int guests){
	this->guests = guests;
}

//getters
const char * Data::getVenue() const{
	return this->venue;
}

const char * Data::getDate() const{
	return this->date;
}

int Data::getGuests() const{
	return this->guests;
}

void Data::print(){
	cout << guests << ";" << venue << ";" << date << endl;
}
