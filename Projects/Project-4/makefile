CC = g++
CPPFLAGS = -std=c++11 -Wall -g

main: main.o Data.o BTSList.o

main.o: main.cpp Data.h BTSList.h

hashList.o: Data.h BTSList.h

hash.o: Data.h Data.cpp

clean:
	rm main *.o

check:
	valgrind --leak-check=full ./main
