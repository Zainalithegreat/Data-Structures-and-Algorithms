//This is going to hold all the functions for hash.cpp 
#pragma once
#include <iostream>

class Data{
	public:
		Data();
		Data(char *, char *, char *, char *, int );
		~Data();

		Data(const Data& BTS);
		Data& operator=(const Data& BTS);

		//mutators
		void webName(const char *);
		void webKeyWord(const char *);
		void webAddress(const char *);
		void webSummery(const char *);
		void webReview(const char *);
		void webRating(const int);

		//getters
		const char * getName()const;
		const char * getKeyWord()const;
		const char * getAddress()const;
		const char * getSummery()const;
		const char * getReview()const;
		int getRating() const;

		void print();

	private:
		char *name;
		char *keyWord;
		char *address;
		char *summery;
		char *review;
		int rating;

};
