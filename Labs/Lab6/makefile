CC = g++
CPPFLAGS = -std=c++11 -Wall -g

main: main.o supplied.o table.o

main.o: main.cpp table.h

table.o: table.h

clean:
	rm main table.o main.o

check:
	valgrind --leak-check=full ./main
