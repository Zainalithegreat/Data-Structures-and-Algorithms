//This is going to have all the data functions
#include <iostream>
#include <cstring>
#include "hash.h"

using namespace std;


hashType::hashType(){
	name = new char[strlen("unknown") + 1];
  	strcpy(name, "unknown");
  	address = new char[strlen("unknown") + 1];
  	strcpy(address, "unknown");
	summery = new char[strlen("unknown") + 1];
        strcpy(summery, "unknown");
	review = new char[strlen("unknown") + 1];
        strcpy(review, "unknown");
  	rating = -1;


}

hashType::hashType(char *webName, char *webAddress, char *webSummery, char *webReview, int webRating){
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
hashType::~hashType(){
	if(name){
		delete[] name;
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
hashType::hashType(const hashType& hashing){
	name = new char[strlen(hashing.name) + 1];
        strcpy(name, hashing.name);
        address = new char[strlen(hashing.address) + 1];
        strcpy(address, hashing.address);
        summery = new char[strlen(hashing.summery) + 1];
        strcpy(summery, hashing.summery);
        review = new char[strlen(hashing.review) + 1];
        strcpy(review, hashing.review);
        rating = hashing.rating;
	
}
hashType& hashType::operator=(const hashType &hashing){
	if(this != &hashing){
		this->webName(hashing.name);
		this->webAddress(hashing.address);
		this->webSummery(hashing.summery);
		this->webReview(hashing.review);
		this->webRating(hashing.rating);
	}
	return *this;
}
//mutators
void hashType::webName(const char *name){
	if(this->name){
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

}

void hashType::webAddress(const char *address){
	if(this->address){
		delete[] this->address;
	}
	this->address = new char[strlen(address) + 1];
        strcpy(this->address, address);

}

void hashType::webSummery(const char *summery){
	if(this->summery){
		delete[] this->summery;
	}
	this->summery = new char[strlen(summery) + 1];
	strcpy(this->summery, summery);
}
void hashType::webReview(const char *review){
	if(this->review){
		delete[] this->review;
	}
	this->review = new char[strlen(review) + 1];
	strcpy(this->review, review);
}
void hashType::webRating(const int rating){
	this->rating = rating;
}

//getters
const char * hashType::getName()const{
	return this->name;
}

const char * hashType::getAddress()const{
	return this->address;
	
}
const char * hashType::getSummery()const{
	return this->summery;

}
const char * hashType::getReview() const{
	return this->review;
}
int hashType::getRating() const{
	return this->rating;
}

void hashType::print(){
	cout << name << ";" << address << ";" << summery << ";" << review << ";" << rating << endl;
}
