//This is going to hold all the functions for hash.cpp 
#pragma once
#include <iostream>

class Data{
	public:
		Data();
		Data(int , char *, char *);
		~Data();

		Data(const Data& BTS);
		Data& operator=(const Data& BTS);

		//mutators
		void setGuests(const int);
		void setVenue(const char *);
		void setDate(const char *);
	

		//getters
		int getGuests() const;
		const char * getVenue()const;
		const char * getDate()const;

		void print();

	private:
		int guests;
		char *venue;
		char *date;
	

};
