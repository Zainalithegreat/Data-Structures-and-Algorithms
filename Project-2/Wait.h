#pragma once


class que{
	public:
		que();
		que(const char *, const int, const char *, const char *);
		~que();

		que(const que &myQue);
		que& operator=(const que &myQue);

		//mutator 
		void group(const char *);
		void people(const int);
		void specialSeating(const char *);
		void Promo(const char *);


		//accessors
		const char * getGroupName() const;
		int getNumPeople() const;
		const char * getSpecialSeating() const;
		const char * getPromoDetails() const;

		void PrintList();
	private:
		char *groupName;
                int numPeople;
                char *specialSeat;
                char *Promotional;


};
