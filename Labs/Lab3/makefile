CC = g++
CPPFLAGS = -Wall -g -std=c++11

app:			app.o linkedlist.o

app.o:			app.cpp linkedlist.h

linkedlist.o:		linkedlist.h linkedlist.cpp

.PHONY:	clean
clean:			# clean the directory
			$(info -- cleaning the directory --)
			rm -f *.o
			rm -f app
