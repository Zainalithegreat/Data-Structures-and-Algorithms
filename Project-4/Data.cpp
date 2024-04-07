//This is going to have all the data functions
#include <iostream>
#include <cstring>
#include "Data.h"

using namespace std;


Data::Data(){
	name = new char[strlen("unknown") + 1];
  	strcpy(name, "unknown");
	keyWord = new char[strlen("unknown") + 1];
	strcpy(keyWord, "unknown");
  	address = new char[strlen("unknown") + 1];
  	strcpy(address, "unknown");
	summery = new char[strlen("unknown") + 1];
        strcpy(summery, "unknown");
	review = new char[strlen("unknown") + 1];
        strcpy(review, "unknown");
  	rating = -1;


}

Data::Data(char *webName, char *webAddress, char *webSummery, char *webReview, int webRating){
	name = new char[strlen(webName) + 1];
	strcpy(name, webName);
        address = new char[strlen(webAddress) + 1];
        strcpy(address, webAddress);
        summery = new char[strlen(webSummery) + 1];
        strcpy(summery, webSummery);
        review = new char[strlen(webReview) + 1];
        strcpy(review, webReview);
        rating = webRating;

}
Data::~Data(){
	if(name){
		delete[] name;
	}
	if(keyWord){
		delete[] keyWord;
	}
	if(address){
		delete[] address;
	}
	if(summery){
		delete[] summery;
	}
	if(review){
		delete[] review;
	}
}
Data::Data(const Data& BTS){
	name = new char[strlen(BTS.name) + 1];
        strcpy(name, BTS.name);
	keyWord = new char[strlen(BTS.keyWord) + 1];
	strcpy(keyWord, BTS.keyWord);
        address = new char[strlen(BTS.address) + 1];
        strcpy(address, BTS.address);
        summery = new char[strlen(BTS.summery) + 1];
        strcpy(summery, BTS.summery);
        review = new char[strlen(BTS.review) + 1];
        strcpy(review, BTS.review);
        rating = BTS.rating;
	
}
Data& Data::operator=(const Data &BTS){
	if(this != &BTS){
		this->webName(BTS.name);
		this->webKeyWord(BTS.keyWord);
		this->webAddress(BTS.address);
		this->webSummery(BTS.summery);
		this->webReview(BTS.review);
		this->webRating(BTS.rating);

	}
	return *this;
}
//mutators
void Data::webName(const char *name){
	if(this->name){
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

}
void Data::webKeyWord(const char *keyWord){
	if(this->keyWord){
		delete[] this->keyWord;
	}
	this->keyWord = new char[strlen(keyWord) + 1];
	strcpy(this->keyWord, keyWord);
}
void Data::webAddress(const char *address){
	if(this->address){
		delete[] this->address;
	}
	this->address = new char[strlen(address) + 1];
        strcpy(this->address, address);

}

void Data::webSummery(const char *summery){
	if(this->summery){
		delete[] this->summery;
	}
	this->summery = new char[strlen(summery) + 1];
	strcpy(this->summery, summery);
}
void Data::webReview(const char *review){
	if(this->review){
		delete[] this->review;
	}
	this->review = new char[strlen(review) + 1];
	strcpy(this->review, review);
}
void Data::webRating(const int rating){
	this->rating = rating;
}

//getters
const char * Data::getName()const{
	return this->name;
}

const char * Data::getKeyWord() const{
	return this->keyWord;
}

const char * Data::getAddress()const{
	return this->address;
	
}
const char * Data::getSummery()const{
	return this->summery;

}
const char * Data::getReview() const{
	return this->review;
}
int Data::getRating() const{
	return this->rating;
}

void Data::print(){
	cout << name << ";" << keyWord << ";" << address << ";" << summery << ";" << review << ";" << rating << endl;
}
