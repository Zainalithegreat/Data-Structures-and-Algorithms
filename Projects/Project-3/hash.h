//This is going to hold all the functions for hash.cpp 
#pragma once
#include <iostream>

class hashType{
	public:
		hashType();
		hashType(char *, char *, char *, char *, int );
		~hashType();

		hashType(const hashType& hashing);
		hashType& operator=(const hashType& hashing);

		//mutators
		void webName(const char *);
		void webAddress(const char *);
		void webSummery(const char *);
		void webReview(const char *);
		void webRating(const int);

		//getters
		const char * getName()const;
		const char * getAddress()const;
		const char * getSummery()const;
		const char * getReview()const;
		int getRating() const;

		void print();

	private:
		char *name;
		char *address;
		char *summery;
		char *review;
		int rating;

};
