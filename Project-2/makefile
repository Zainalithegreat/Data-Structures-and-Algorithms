CC = g++
CPPFLAGS = -std=c++11 -Wall -g

main: main.o Wait.o WaitList.o stacklist.o

main.o: Wait.h WaitList.h main.cpp stacklist.h

Wait.o: Wait.h Wait.cpp 

WaitList.o: Wait.h WaitList.h stacklist.h

stacklist.o: stacklist.h Wait.h

clean:
	rm main *.o

check:
	valgrind --leak-check=full ./main
