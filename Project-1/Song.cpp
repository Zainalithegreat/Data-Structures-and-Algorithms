/******************************************************************************
# Author:           Zain Ali
# Lab:              Project 1
# Date:             Jan 20th 2024
# Description:      "This file is the data file where all the Song.h mutators and accessors are avaiable, also the constructors, destructor, and  assignment operator overload.
# Input:            char *name, *title, *length
                    int likes
                    Song data
# Output:           char *name, *title, *length
                    int likes
               
# Sources:          None
# File Name	    Song.cpp
#******************************************************************************/



#include "Song.h"
#include <iostream>
#include <fstream>
#include <cstring> 
using namespace std;
//default constructor initilizing all variables to unknown and -1
Song::Song(){
  name = new char[strlen("unknown") + 1];
  strcpy(name, "unknown");
  title = new char[strlen("unknown") + 1];
  strcpy(title, "unknown");
  length = -1;
  likes = -1;
}
//constructor with parameters, assigning all variables to the parameters
Song::Song(char *name, char *title, double newLength, int  newLikes){
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
  this->title = new char[strlen(title) + 1];
  strcpy(this->title, title);
  length = newLength;
  likes = newLikes;
}
//destructor, that dealocates memory
Song::~Song(){
  if(name){
    delete[] name;
  }
  if(title){
    delete[] title;
  }
}
//This is a song class copy constructor
Song::Song(const Song &song){
    name = new char[strlen(song.name) + 1];
    strcpy(name, song.name);
    title = new char[strlen(song.title) + 1];
    strcpy(title, song.title);
    length = song.length;
    likes = song.likes;
}
//operator overloading =, this function makes sure if the user copys an objects we will not have any memory leek
Song& Song::operator=(const Song &song){
  if(this != &song){
    delete[] name;
    delete[] title; 
  
    name = new char[strlen(song.name) + 1];
    strcpy(name, song.name);
    title = new char[strlen(song.title) + 1];
    strcpy(title, song.title);
    length = song.length;
    likes = song.likes;
  }
  return *this;
}
//mutators
//This is a setName function that sets the member function name to the parameter name
void Song::setName(const char *name){
  if(this->name){
    delete[] this->name;
  }
  this->name = new char[strlen(name) + 1];
  strcpy(this->name, name);
}
//This function sets title to member function title
void Song::setTitle(const char *title){
  if(this->title){
    delete[] this->title;
  }
  this->title = new char[strlen(title) + 1];
  strcpy(this->title, title);
}
//This function sets length to the member function length
void Song::setLength(const double length){
  this->length = length;
}
//This function sets likes to the member function likes
void Song::setLike(const int likes){
  this->likes = likes;
}

//accessors 
//This function returns the member var name
const char * Song::getName() const{
  return this->name;
}
//This function returns member var title
const char * Song::getTitle() const{
  return this->title;
}
//This function returns member var length
double Song::getLength() const{
  return this->length;
}
//This function returns member var likes
int Song::getLike() const{
  return this->likes;
}
//This function prints out all the member var
void Song::PrintAct(){
  cout << name << ';' << title << ";" << length << ";" << likes << endl;
} 
