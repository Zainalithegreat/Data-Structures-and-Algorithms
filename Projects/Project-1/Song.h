#pragma once

//This is a Song class, which mutator and access variables through member function;
class Song{
	public:
		//defualt constructor, constructor with parameters and destructor
    		Song();
    		Song(char *, char *, double , int );
    		~Song();
    		//copy constructor;
    		Song(const Song &song);
    		//assignment operator
    		Song& operator=(const Song &song);

    		//mutator
    		void setName(const char *);
   		void setTitle(const char *);
    		void setLength(const double);
    		void setLike(const int);

    		//accessors
    		const char * getName() const;
    		const char * getTitle() const;
    		double getLength() const;
    		int getLike() const;

    		void PrintAct();
    
    

  	private:
		//Private member variables
   		char *name;
    		char *title;
    		double length;
    		int likes;
};
