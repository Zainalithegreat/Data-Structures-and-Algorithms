CC = g++
CPPFLAGS = -std=c++11 -Wall -g

main: main.o Data.o Graph.o

main.o: main.cpp Data.h Graph.h

Graph.o: Data.h Graph.h

Data.o: Data.h Data.cpp

clean:
	rm main *.o

check:
	valgrind --leak-check=full ./main

