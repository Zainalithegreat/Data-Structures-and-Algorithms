CC = g++
CPPFLAGS = -std=c++11 -Wall -g

main: main.o hash.o hashList.o

main.o: main.cpp hash.h hashList.h

hashList.o: hash.h hashList.h

hash.o: hash.h hash.cpp

clean:
	rm main *.o

check:
	valgrind --leak-check=full ./main
